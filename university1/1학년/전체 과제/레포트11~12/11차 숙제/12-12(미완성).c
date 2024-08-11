#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char** p = NULL, word[100];
	int i, row = 0;

	while (1){
		printf("Enter a word.\n");
		gets(word);
		if (strcmp(word, "quit") == 0)//quit 입력시 루프를 빠져나감
			break;

		p = (char**)realloc(p, (row + 1) * sizeof(char*));//행의 수를 등가
		if (p == NULL)//NULL 테스트
			exit(1);

		p[row] = (char *)malloc((strlen(word) + 1) * sizeof(char));//p[row]가 단어크기만큼 동적메모리를 갖음
		if (p[row] == NULL)//NULL 테스트
			exit(1);

		for (i = 0; word[i] != '\0'; i++)
			strcpy(p[row], word);
		row++;
	}


	for (i = 0;i<row; i++)//출력
		printf("%s\n", p[i]);

	printf("\n");//개행

	for (i = 0; i < row; i++)//반납
		free(p[i]);
	free(p);

	return 0;
}