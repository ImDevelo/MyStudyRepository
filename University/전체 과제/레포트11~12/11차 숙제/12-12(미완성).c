#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char** p = NULL, word[100];
	int i, row = 0;

	while (1){
		printf("Enter a word.\n");
		gets(word);
		if (strcmp(word, "quit") == 0)//quit �Է½� ������ ��������
			break;

		p = (char**)realloc(p, (row + 1) * sizeof(char*));//���� ���� �
		if (p == NULL)//NULL �׽�Ʈ
			exit(1);

		p[row] = (char *)malloc((strlen(word) + 1) * sizeof(char));//p[row]�� �ܾ�ũ�⸸ŭ �����޸𸮸� ����
		if (p[row] == NULL)//NULL �׽�Ʈ
			exit(1);

		for (i = 0; word[i] != '\0'; i++)
			strcpy(p[row], word);
		row++;
	}


	for (i = 0;i<row; i++)//���
		printf("%s\n", p[i]);

	printf("\n");//����

	for (i = 0; i < row; i++)//�ݳ�
		free(p[i]);
	free(p);

	return 0;
}