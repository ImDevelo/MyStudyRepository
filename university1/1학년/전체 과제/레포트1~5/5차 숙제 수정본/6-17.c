/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-17)
 Contents:
 ���º�ȭ�� ���������ν� �Է¹��忡�� ��ġ�� in�� ��� ��������
 �Ǵ��Ͽ� ����ϴ� ���α׷��� �ۼ��϶�.                      */
#include<stdio.h>
int main() {
	int state,ch, In_sum=0;
	printf("Enter a sentence.\n");

	state = 0;
	for (ch = getchar(); ch != '\n'; ch = getchar()) {
		switch (state){
		case 0://�޽Ļ��� : i�� �Է¹����� state 1����
			if (ch == 'i') {
				state = 1;
				break;
			}
			else
			break;
		case 1://i�� ���¹��� ���� : n�� �Է¹����� state 2���� �ƴ϶�� �޽Ļ���
			if (ch == 'n') {
				state = 2;
				break;
			}
			else {
				state = 0;
				break;
			}
		case 2://n�� ���¹��� ���� : ' '�� �Է¹����� ��ġ��'in'���� �߰�
			if (ch == ' ') {
				In_sum++;
				state = 0;
				break;

			}
			else {
				state = 0;
				break;
			}
		}
	}
	printf("The preposition in appear %d time.\n", In_sum);
	return 0;
}