/* < C programing >                           Day 2019. 04. 25
 Project Title: Assignment 6. (7-2)
 Contents:
 �޷� ���α׷��� �ϼ��϶�,�� print the calendar �κ��� ����ϴ�
 ������ �Լ��� ����� �� �Լ��� ���� ���� �׽�Ʈ�ϴ� ���α׷��� 
 �ۼ��ؾ��Ѵ�. ���� ��� �Լ��� ��Ƽ� ��ü���� ���α׷��� �ϼ�
 �϶�.                                                        */
#include<stdio.h>
#define lape_year 1
#define non_lape_year 0

int leap_year(int y);
int to_last_year(int year);
int to_last_month(int year, int month);
int Day_of_week(int year, int month);
int Month(int,int);
void print_calendar(int, int);

int main() {
	int Year, Month;

	while (1){
		printf("<Enter year and month>.\n");
		scanf("%d %d", &Year, &Month);
		if (Year <= 0 || Month <= 0 || Month >= 13)
			break;
		print_calendar(Year, Month); // [�޷���� ���α׷�] �Լ� ȣ��
		printf("\n\n");
	}
	printf("�޷� ���α׷� ����\n");
	return 0;
}

// [�޷���� ���α׷�]
void print_calendar(int year,int month) {
	int i, j;
	int count = Day_of_week(year, month); //�����Լ� ȣ��

	printf("[ %d�� %d�� �޷�]\n", year, month);
	printf("[Sun]	[Mon]	[Tue]	[Wed]	[Thu]	[Fri]	[Sat]\n");

	for (i = 0; ; i++) { //�޷� �� ��� �� ����� ����
		if (i == Day_of_week(year, month))
			break;
		printf("	");
	}

	for (j = 1; j <= Month(year, month); j++) {//1~30 (Ȥ�� 28,29,31��) ��¥ ��� ��, ������� �Ǹ� �� �ٲ�
		count++;
		printf("%d	", j);
		if (count == 7) {
			printf("\n");
			count = 0;
		}
	}
}

//���� �������� �Ǻ�
int Day_of_week(int year, int month) {
	int total_day, Day_week;
	total_day = to_last_year(year) + to_last_month(year, month) + 1;
	Day_week = total_day % 7;
	return Day_week; //���ϰ��� 1�̸� ������, 2�̸� ȭ����....6�̸� �����, 0�̸� �Ͽ����̴�.
}

//���� 1�� 1�Ϻ��� �۳� ������ ��¥��
int to_last_year(int year) {
	int i, total = 0;
	for (i = 1; i <= (year - 1); i++) {
		if (leap_year(i))
			total += 366;
		else
			total += 365;
	}
	return total;
}

// ������� �Ǵ�
int Month(int year, int month) {
	int i = month, total = 0;
	
	if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		total += 31;
	else if (i == 4 || i == 6 || i == 9 || i == 11)
		total += 30;
	else {
		if (leap_year(year))
			total += 29;
		else
			total += 28;
	}
	return total;
}

// �ݳ� 1�� 1�� ���� ���� ���ϱ��� ��¥ ��
int to_last_month(int year, int month) {
	int i, total = 0;

	for (i = 1; i <= month - 1; i++) {
		total += Month(year, i);
	}
	return total;
}

//���� ���� �Ǻ�
int leap_year(int y) { 
	if ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 400 == 0))
		return lape_year;
	else
		return non_lape_year;
}
