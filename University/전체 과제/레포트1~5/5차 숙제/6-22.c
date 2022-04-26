/* < C programing >                             Day 2019. 04. 11
 Project Title: Assignment 5. (6-22)
 Contents:
 숫자가 3, 6, 9가 들어갈 때 그 숫자가 나올때 마다 그 갯수만큼 박
 수를 친다. 1부터 N까지 숫자에 대하여 369를 할 경우의 출력을 작성
 하라                                                          */
#include<stdio.h>
int Game_369(int);

int main() {
	int Number;

	printf("Enter a number.\n");
	scanf("%d", &Number);
	Game_369(Number);

	return 0;
}

//3 6 9일때 '!'(박수)를 출력하는 함수
int Game_369(int N) {
	int i, j, k;
	int In_Num; //10으로 나눈 나머지 저장해두는 함수
	int Point_369; // 3,6,9가 몇개인지 세는 변수
    int save_Num; //i값을 저장해두는 변수

	for (i = 1; i <= N; i++) {
		Point_369 = 0;// 369개수 초기화
		save_Num = i; //save_Num에 i값 저장

		//3,6,9 개수당 Point_369 값 추가
		for (j = 1; ; j++) {
			In_Num = save_Num % 10;
			save_Num /= 10;
			if (In_Num == 3 || In_Num == 6 || In_Num == 9)
				Point_369++;
			if (save_Num == 0)
				break;
		}

		//'!'혹은 정수 출력
		if (Point_369 > 0)
			for (k = 1; k <= Point_369; k++) {
				printf("!");
			}
		else if (Point_369 == 0) {
			printf("%d", i);
		}
		printf(" ");
	}
	return;
}