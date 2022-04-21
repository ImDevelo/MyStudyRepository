import time
import pyupbit
import datetime
import requests
import pandas

access = "h8j24rQ38wqz9wYlEPQu6vMqwpxiHD4m2SFlxK62"
secret = "1VloA7VU2lBP9vaVPnaex9MeZiaNtWcwGpHrJteM"

#매수 시장 최대 항목 8개
TICKER = ["XRP","SAND","ETH","ONG","ATOM","TRX","KNC","XTZ"]

#총 투자금
INVESTMENT_AMOUNT = 20000
TICKER_RSI_L = [False,False,False,False,False,False,False,False]
BuyCount = [12,15,0,5,6,0,0,5]
BuyAverage = [0,0,0,0,0,0,0,0]
InitBuyCount = [12,15,0,0,6,0,0,5]
InitBuyAvarage = [939,3597,0,0,31505,0,0,3950]

def get_start_time(ticker):
    #시작시간조회
    df = pyupbit.get_ohlcv(ticker, interval="day", count=1)
    start_time = df.index[0]
    return start_time
def get_balance(ticker):
    #잔고조회
    balances = upbit.get_balances()
    for b in balances:
        if b['currency'] == ticker:
            if b['balance'] is not None:
                return float(b['balance'])
            else:
                return 0
    return 0
def get_current_price(tic):
    #현제가조회
    ticker = "KRW-" + tic
    return pyupbit.get_orderbook(ticker=ticker)["orderbook_units"][0]["ask_price"]
def post_message(text):
    #슬렉메세지
    response = requests.post("https://slack.com/api/chat.postMessage",
        headers={"Authorization": "Bearer "+"xoxb-3067670227845-3100758611376-YBS2L5qBgfmkgSRv9vlxIrrf"},
        data={"channel":"#autobit","text": text})
    print(response)

def set_avarage_coin(ticker, index):
    #매수평균가 = 현제 구매량/ 잔고...
    BuyCount[index] += 1
    now = get_balance(ticker)
    BuyAverage[index] = ((BuyCount[index] * INVESTMENT_AMOUNT)/now)

    print(ticker + " | " + BuyAverage[index])





def get_rsi(ticker):
    data = pyupbit.get_ohlcv("KRW-"+ticker, interval="minute10") 
    delta = data["close"].diff()
    ups, downs = delta.copy(), delta.copy() 
    ups[ups < 0] = 0 
    downs[downs > 0] = 0 
    period = 14
    AU = ups.ewm(com = period-1, min_periods = period).mean() 
    AD = downs.abs().ewm(com = period-1, min_periods = period).mean() 
    RS = AU/AD
    return (100 - (100/(1 + RS))).iloc[-1]




def buy_coin_rsi(ticker,i):
    now_rsi = get_rsi(ticker)
    if now_rsi <= 25 :
        TICKER_RSI_L[i] = True
    elif now_rsi >= 31 and TICKER_RSI_L[i] == True:
        upbit.buy_market_order("KRW-"+ticker, INVESTMENT_AMOUNT)
        set_avarage_coin(ticker,i)
        TICKER_RSI_L[i] = False
    
    






# 로그인
upbit = pyupbit.Upbit(access, secret)
print("*----AutoTrade Start----*")
post_message("*----AutoTrade Start----*")

# 자동매매 시작
while True:
    try:
        for i in range(len(TICKER)):
            buy_coin_rsi(TICKER[i],i)

        time.sleep(1)
    #오류예외
    except Exception as e:
        print(e)
        post_message("CRASH!")
        time.sleep(1)