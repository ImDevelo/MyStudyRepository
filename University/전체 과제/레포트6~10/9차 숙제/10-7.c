/* < C programing >                           Day 2019. 05. 18
 Project Title: Assignment 9. (10-7)
 Contents: �迭�� �̿��Ͽ� long long�� �ʰ��ϴ� ���ڸ� �Կ��ް�
 ��ȣȭ�ϴ� ���α׷��� �ۼ��϶�                              */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
//��ȣȭ �Լ�
int modulo(int a[], const int m, const int size) {
	int i, N = 1;
	int remainder = a[0] % 7;// �ʱⰪ ����
	for (i = 1; i < size; i++) {
		remainder = (remainder * 10 + a[i]) % 7;
	}
	return remainder;
}
//�־��� main�Լ�
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

