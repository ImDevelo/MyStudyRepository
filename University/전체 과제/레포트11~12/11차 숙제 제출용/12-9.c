/* < C programing >                           Day 2019. 06. 01
 Project Title: Assignment 11. (12-9)
 Contents: �ѱ��� ��������� ����ϴ� ���α׷��� ������   */
#include<stdio.h>
#include<string.h>

//�ѱ۹��� ���� count
int k_letters(const char *string) {
	int count=0,i;
	for (i = 0; string[i] != '\0';) {
		if (string[i] >= 0 && string[i] <= 127)//�ƽ�Ű���� pass
			i++;
		else{
			i += 2;
			count++;
		}
	}
	return count;
}

int main() {
	char str[100];
	while (1){
		printf("Enter a sentence with Korean and English letter.\n");
		gets(str);
		if (strcmp(str, "quit") == 0)
			break;
		printf("�ѱ۹��ڴ� %d ���ɴϴ�.\n", k_letters(str));
	}
	return 0;
}