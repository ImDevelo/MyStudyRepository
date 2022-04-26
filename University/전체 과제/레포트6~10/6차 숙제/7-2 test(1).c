//달력출력프로그램 테스트파일입니다.
#include<stdio.h>

//요일 계산하는 함수
int Day_of_week(Num) {
	int  Day_week;
	Day_week = Num % 7 + 1;
	return Day_week; //리턴값이 1이면 월요일, 2이면 화요일....6이면 토요일, 0이면 일요일이다.
}
//달력출력하는 프로그램
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
	scanf("%d", &Num);// 이전 전체일수 입력
	print_calendar(Num);
	return 0;

}
