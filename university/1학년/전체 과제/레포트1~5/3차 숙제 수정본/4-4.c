/* < C programing >                                 Day 2019. 03. 28
 Project Title: Assignment 3. 4-4
 Contents:
���ĺ� �ҹ��ڸ� �о� �빮�ڷ� ��ȯ�ϴ� �Լ��� �ۼ��ϰ� main���� �װ�
�� �ҷ� Ȯ���ϴ� ���α׷��� �ۼ��϶�. �Լ� ������ char to_upper_case
(char ch);�� �Ѵ�.                                                */
#include <stdio.h>
char to_upper_case(char ch);

//�ҹ��� �ƽ�Ű�ڵ尪�� �빮�ڰ����� �ٲٴ� �Լ�
char to_upper_case(char ch){
	return ch - 32;
}

int main() {
	char Blank1;

	printf("���ĺ� �ҹ��ڸ� �Է��ϼ���.\n");
	scanf("%c",&Blank1); 
	printf("�ҹ��� %c�� �빮�ڴ� %c�Դϴ�.\n",Blank1, to_upper_case(Blank1));

	return 0;

}