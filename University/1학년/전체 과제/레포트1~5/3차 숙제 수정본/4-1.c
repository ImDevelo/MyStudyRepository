/* < C programing >                                  Day 2019. 03. 27
 Project Title: Assignment 3. 4-1
 Contents: �������� �Է¹޾� ù��° ������ �ι�° �������� ũ�ų� ����
 �� 1��, �׷��� ������ 0�� �ǵ����ִ� �Լ��� �ۼ��ϰ� main���� �� �Լ�
 �� �ҷ� ����� ����ϴ� ���α׷��� �ۼ��϶�
�Լ� ������ int is_latger(int f, int s);                            */
#include <stdio.h>
int is_latger(int f, int s);

//�� ���� ���ϴ� �Լ�
int is_latger(int f, int s) {
	return f >= s;

}

int main() {
	int Blank1, Blank2;

	printf("Enter two integers.\n");
	scanf("%d %d", &Blank1,&Blank2);
	printf("Result is %d.", is_latger(Blank1, Blank2));
	return 0;

}