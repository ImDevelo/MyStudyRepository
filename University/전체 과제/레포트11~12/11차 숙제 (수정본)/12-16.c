/* < C programing >                          Day 2019. 06. 01
 Project Title: Assignment 11. (12-16)
 Contents: �ѱ� ������ �Է¹޾� �װ��� ȸ������ �Ǵ��ϴ� ����
 �׷��� �ۼ��϶�.                                          */
#include<stdio.h>
#include<string.h>
//�ѱ� ȸ�� �Ǻ��ϴ� ���α׷�
int k_palindrome(const char *string) {
	int i,j=0, first, last;
	char H_str[100];
	char ch1, ch2;

	for (i = 0; string[i] != '\0'; i++)//��ĭ, ��ȣ �����Ͽ� H_str�� �ѱ۸� ����
		if (!(string[i] >= 32 && string[i] <= 47)) {
			H_str[j++] = string[i++];
			H_str[j++] = string[i];
		}
	first = 0, last = j; j = 0;
	for (i = last-1; i >= first; ) {//�ѱ۸� �������¿��� ȸ���Ǵ�
		if ((H_str[i - 1] != H_str[j])|| (H_str[i] != H_str[j+1]))
			return 0;
		i -= 2; j += 2;
	}
	return 1;
}

int main() {
	while (1){
		char str[100];
		int lim;
		printf("�ѱ� ������ �Է��Ͻÿ�.\n");
		gets(str);
		if (strcmp(str, "quit") == 0)
			break;

		lim = k_palindrome(str);
		(lim)? printf("�� ȸ���Դϴ�.\n"): printf("ȸ���� �ƴմϴ�.\n");
		return 0;
	}
}