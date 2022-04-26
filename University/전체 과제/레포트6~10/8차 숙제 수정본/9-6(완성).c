/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (9-6)
 Contents: 10명이 8명의 후보에게 투표하여 당선자를 알아내는 프로
 그램을 만들어라. 단, 득표수가 과반수가 아니라면 당선자는 없다.*/
#include <stdio.h>

int main() {
	int vote[10];
	int count[8] = { 0 };
	int i, j, k;
	int max = 0; // 최대 득표수
	int Winner; //승자 번호

	printf("Enter the result of voting.\n");
	for (i = 0; i < 10; i++) {
		scanf("%d", &vote[i]);//입력변수 vote에 저장
		for (j = 0; j < 8; j++) {
			if (j == vote[i] - 1)
				count[j]++;//count에 vote 득표 수 등록
		}
	}
	//승자 판별
	for (k = 0; k < 8; k++) {
		if (max < count[k]) {
			Winner = k + 1;
			max = count[k];
		}
	}

	if (max >= 6)
		printf("Number %d is the winner.", Winner);
	else
		printf("There is no winner.");
	return 0;
}