class Bank:
    money = 0
    @classmethod
    def change_money(cls, m):
        cls.money += m

    @classmethod
    def print_money(cls):
        print(cls.money)

bank = Bank()
bank.change_money(10000) #잔고에 만원 추가
bank.print_money()      #10000
bank.change_money(-5000) # 5천원 사용
bank.print_money()      #5000

        