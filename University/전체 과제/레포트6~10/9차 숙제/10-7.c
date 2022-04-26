/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (10-7)
 Contents: 배열을 이용하여 long long을 초과하는 숫자를 입역받고
 암호화하는 프로그램을 작성하라                              */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
//암호화 함수
int modulo(int a[], const int m, const int size) {
	int i, N = 1;
	int remainder = a[0] % 7;// 초기값 설정
	for (i = 1; i < size; i++) {
		remainder = (remainder * 10 + a[i]) % 7;
	}
	return remainder;
}
//주어진 main함수
int main() {
	int i, mod, arr[1000];
	char ch;
	printf("Enter a big positive integer.\n");
	i = 0;
	while ((ch=getchar())!='\n'){
		arr[i] = atoi(&ch);
		i++;
	}
	printf("Enter a modulus number.\n");
	scanf("%d", &mod);
	printf("The result of modulois %d.\n", modulo(arr,mod, i));
	return 0;
}

