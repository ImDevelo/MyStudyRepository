/* < C programing >                                   Day 2019. 03. 27
 Project Title: Assignment 3. 3-7
 Contents:
 �Ž����� ����(Coin Change Problem)�� '�־��� �ܵ��� �������� �Ž��� ��
 �� ��� �ϸ� ���������� �ּ�ȭ�Ҽ� �ִ°�'�� �����̴�. � ���ǱⰡ
 500��, 100��, 50��, 10��¥�� ������ ���� ������� �Ž������� 270���̸�
 ���� ��� �־�� �ϴ��� ����ϴ� ���α׷��� �ۼ��ض�              */
#include <stdio.h>

int main() {
	int Blank1, Coin_500, Coin_100, Coin_50, Coin_10;

	printf("Enter the amount of change.\n");
	scanf("%d", &Blank1);

	Coin_500 = Blank1 / 500;//500�� ��갪
	Coin_100 = (Blank1 % 500) / 100;//100�� ��갪
	Coin_50 = (Blank1 % 100) / 50;//50�� ��갪
	Coin_10 = (Blank1 % 50) / 10;//10�� ��갪

	printf("500��: %d��, 100��: %d��, 50��: %d��, 10��: %d��", Coin_500, Coin_100, Coin_50, Coin_10);
	return 0;

}