/* < C programing >                           Day 2019. 05. 11
 Project Title: Assignment 8. (10-6)
 Contents:�Է¹����� �Ųٷ� ����ϴ� ���α׷��� �ۼ��϶�    */
#include<stdio.h>
//���� �Ųٷ� ����ϴ� ���α׷�
void reverse(char s[], int last) {
	if (last == -1) {
		return;
	}
	else {
		printf("%c", s[last]);
		reverse(s, last - 1);
	}
}
int main() {
	char S[100];
	int i = 0;
	printf("Enter the string.\n");
	while ((S[i] = getchar()) != '\n')//�Է��Ͽ� �迭�� ����
		i++;
	reverse(S, i - 1);

}