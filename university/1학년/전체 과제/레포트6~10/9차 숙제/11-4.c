/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (11-4)
 Contents: 모음이 몇개나오는지 검사하는 프로그램을 만드시오. */
#include<stdio.h>
//모음 판별
int count_vowel(char * arr, int lenght) {
	int sum = 0, i;//sum에 모음갯수 저장
	for (i = 0; i < lenght; i++) {
		if (*(arr + i) == 'a' || *(arr + i) == 'e' || *(arr + i) == 'u' || *(arr + i) == 'i' || *(arr + i) == 'o')
			sum++;
	}
	return sum;
}

int main() {
	char ch, arr[100];
	int i = 0;
	printf("Enter the srntence.\n");
	while ((ch = getchar()) != '\n') { //입력
		arr[i++] = ch;
	}
	printf("vowel is %d", count_vowel(arr, i));
	return 0;
}