/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-14)
 Contents:
 �Է� �ڿ����� �ݴ�� ����ϴ� ���α׷��� �ۼ��϶�. ��, �� ����
 �׷��� 0�̳� ������ �Էµ� ������ ��� �ݺ��Ǿ���Ѵ�.       */
#include<stdio.h>
void reverse_it(int);

int main() {
	int Num;
	 while(1){
		 printf("Enter a natual number.\n");
		 scanf("%d",&Num);

		 if (Num <= 0)
			 break;
		 reverse_it(Num);
		 printf("\n");
		}
}

//�ڸ����� �ݴ�� ����ϴ� �Լ�
void reverse_it(int num) {
	
	while (num > 0) {
		printf("%d", num % 10);
		num /= 10;
	}
	
	return;
}