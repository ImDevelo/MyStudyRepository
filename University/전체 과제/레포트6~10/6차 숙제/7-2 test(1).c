//�޷�������α׷� �׽�Ʈ�����Դϴ�.
#include<stdio.h>

//���� ����ϴ� �Լ�
int Day_of_week(Num) {
	int  Day_week;
	Day_week = Num % 7 + 1;
	return Day_week; //���ϰ��� 1�̸� ������, 2�̸� ȭ����....6�̸� �����, 0�̸� �Ͽ����̴�.
}
//�޷�����ϴ� ���α׷�
void print_calendar(int Num) {
	int i, j ,wnf = Day_of_week(Num);
	printf("%d\n",Num);
	printf("Sun	Mon	Tue	Wed	Thu	Fri	Sat\n");

	for (i = 0; ; i++) {
		if (i == Day_of_week(Num))
			break;
		printf("	");
	}
	for (j = 1; j <= 30; j++) {
		wnf++;
		printf("%d	", j);
		if (wnf == 7) {
			printf("\n");
			wnf = 0;
		}
	}
}

int main() {
	int Num;
	printf("Enter befor sum of day.\n");
	scanf("%d", &Num);// ���� ��ü�ϼ� �Է�
	print_calendar(Num);
	return 0;

}
