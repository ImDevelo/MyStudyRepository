/* < C programing >                               Day 2019. 06. 06
 Project Title: Assignment 12. (13-8)
 Contents: ���� ���α׷��� �ϼ��Ͽ� ���ѻ����� �ϼ��϶�. �� �ӷµ�
 �ܾ� �ִٸ� �� ���� ���÷����ϰ� �׷��� ������ �� �ܾ ������
 �߰��϶� ���α׷��� quit�� �Էµɶ� ���� ����Ǿ���Ѵ�.       */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char word[20];
	char meaning[100];
}wordType;

typedef struct {
	wordType dict[100];
	int count;
}dictType;

//d�� ����Ű�� �������� w�� ����Ű�� �ܾ ã�� meaning�� ����
char *search(char* w, dictType *d) {
	int i;
	for (i = 0; i <= d->count; i++) {//i�� count���� ���� �� ����
		if (strcmp(w, d->dict[i].word) == 0) //���ڿ� ��   
			return (d->dict[i].meaning);
	}
	return NULL;
}

//d�� ����Ű�� ������ w�� ����Ű�� �ܾ� ��� m�� ����Ű�� �ܾ� ���� ����
void insert(char* w, char* m, dictType *d) {
	//d = (dictType*)malloc(sizeof(dictType));
	strcpy(d->dict[(d->count)].word, w);
	strcpy(d->dict[(d->count)].meaning, m);
	return (d->count += 1);
}

int main() {
	char word[20], *there;
	char meaning[100];
	dictType mydict;
	mydict.count = 0;
	while (1) {
		printf("Enter a word to search.\n");
		gets(word);
		if (strcmp(word, "quit") == 0)
			break;
		there = search(word, &mydict);
		if (there != NULL) //�ܾ ã������
			puts(there); //ã�� �ܾ��� ���� ���÷���
		else {
			puts("No such word in dictionary. Enter the meaning.");
			gets(meaning);
			insert(word, meaning, &mydict);//���ο� �ܾ� ����
		}
	}
	return 0;
}