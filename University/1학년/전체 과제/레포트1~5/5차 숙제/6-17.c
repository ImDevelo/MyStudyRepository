/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-17)
 Contents:
 상태변화를 추적함으로써 입력문장에서 전치사 in이 몇번 나오는지
 판단하여 출력하는 프로그램을 작성하라.                      */
#include<stdio.h>
int main() {
	int state,ch, In_sum=0;
	printf("Enter a sentence.\n");

	state = 0;
	for (ch = getchar(); ch != '\n'; ch = getchar()) {
		switch (state){
		case 0://휴식상태 : i를 입력받으면 state 1으로
			if (ch == 'i') {
				state = 1;
				break;
			}
			else
			break;
		case 1://i를 립력받은 생태 : n를 입력받으면 state 2으로 아니라면 휴식상태
			if (ch == 'n') {
				state = 2;
				break;
			}
			else {
				state = 0;
				break;
			}
		case 2://n를 립력받은 생태 : ' '를 입력받으면 전치사'in'갯수 추가
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