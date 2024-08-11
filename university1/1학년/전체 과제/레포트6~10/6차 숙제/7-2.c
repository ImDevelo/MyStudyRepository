/* < C programing >                           Day 2019. 04. 25
 Project Title: Assignment 6. (7-2)
 Contents:
 달력 프로그램을 완성하라,단 print the calendar 부분을 담당하는
 별도의 함수를 만들되 그 함수만 따로 때어 테스트하는 프로그램을 
 작성해야한다. 이후 모든 함수를 모아서 전체적인 프로그램을 완성
 하라.                                                        */
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
		print_calendar(Year, Month); // [달력출력 프로그램] 함수 호출
		printf("\n\n");
	}
	printf("달력 프로그램 종료\n");
	return 0;
}

// [달력출력 프로그램]
void print_calendar(int year,int month) {
	int i, j;
	int count = Day_of_week(year, month); //요일함수 호출

	printf("[ %d년 %d월 달력]\n", year, month);
	printf("[Sun]	[Mon]	[Tue]	[Wed]	[Thu]	[Fri]	[Sat]\n");

	for (i = 0; ; i++) { //달력 일 출력 전 빈공간 생성
		if (i == Day_of_week(year, month))
			break;
		printf("	");
	}

	for (j = 1; j <= Month(year, month); j++) {//1~30 (혹은 28,29,31일) 날짜 출력 단, 토요일이 되면 줄 바꿈
		count++;
		printf("%d	", j);
		if (count == 7) {
			printf("\n");
			count = 0;
		}
	}
}

//무슨 요일인지 판별
int Day_of_week(int year, int month) {
	int total_day, Day_week;
	total_day = to_last_year(year) + to_last_month(year, month) + 1;
	Day_week = total_day % 7;
	return Day_week; //리턴값이 1이면 월요일, 2이면 화요일....6이면 토요일, 0이면 일요일이다.
}

//서기 1월 1일부터 작년 말까지 날짜수
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

// 몇월인지 판단
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

// 금년 1월 1일 부터 전달 말일까지 날짜 수
int to_last_month(int year, int month) {
	int i, total = 0;

	for (i = 1; i <= month - 1; i++) {
		total += Month(year, i);
	}
	return total;
}

//윤년 인지 판별
int leap_year(int y) { 
	if ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 400 == 0))
		return lape_year;
	else
		return non_lape_year;
}
