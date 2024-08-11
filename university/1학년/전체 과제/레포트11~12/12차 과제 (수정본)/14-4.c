/* < C programing >                               Day 2019. 06. 07
 Project Title: Assignment 12. (14-4)
 Contents: fopen(__FILE__, "r")�� �̿��Ͽ� �ҽ��ڵ� �ڽ��� �ҷ� ��
 ��ȣ�� �Ұ�ȣ�� ������ ���� �´��� �˻��ϴ� ���α׷��� �ۼ��϶�*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int left_parenthesis=0, right_parenthesis=0, left_braceis=0, right_brace=0;
	int ch;
	FILE* fp = fopen(__FILE__, "r");

	//�߰�ȣ �Ұ�ȣ ���� count
	while ((ch= fgetc(fp))!=EOF){
		if (ch == '(')
			left_parenthesis++;
		else if (ch == ')')
			right_parenthesis++;
		else if (ch == '{')
			left_braceis++;
		else if (ch == '}')
			right_brace++;
	} 

	printf("left_parenthesis: %d, right_parenthesis: %d \n", left_parenthesis, right_parenthesis);
	printf("left_braceis: %d, right_brace: %d \n", left_braceis, right_brace);

}