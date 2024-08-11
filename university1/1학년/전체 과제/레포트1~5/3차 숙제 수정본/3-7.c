/* < C programing >                                   Day 2019. 03. 27
 Project Title: Assignment 3. 3-7
 Contents:
 거스름돈 문제(Coin Change Problem)는 '주어진 잔돈을 동전으로 거슬러 주
 되 어떻게 하면 동전개수를 최소화할수 있는가'의 문제이다. 어떤 자판기가
 500원, 100원, 50원, 10원짜리 동전을 갖고 있을경우 거스름돈이 270원이면
 동전 몇개씩 주어야 하는지 출력하는 프로그램을 작성해라              */
#include <stdio.h>

int main() {
	int Blank1, Coin_500, Coin_100, Coin_50, Coin_10;

	printf("Enter the amount of change.\n");
	scanf("%d", &Blank1);

	Coin_500 = Blank1 / 500;//500원 계산값
	Coin_100 = (Blank1 % 500) / 100;//100원 계산값
	Coin_50 = (Blank1 % 100) / 50;//50원 계산값
	Coin_10 = (Blank1 % 50) / 10;//10원 계산값

	printf("500원: %d개, 100원: %d개, 50원: %d개, 10원: %d개", Coin_500, Coin_100, Coin_50, Coin_10);
	return 0;

}