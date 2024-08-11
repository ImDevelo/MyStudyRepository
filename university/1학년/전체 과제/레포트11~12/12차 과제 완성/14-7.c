/* < C programing >                                 Day 2019. 06. 07
 Project Title: Assignment 12. (14-7)
 Contents: ����ü���� count�� �����Ͽ� ���ѻ����� ������. ����Ͽ�
 �ܾ �߰��ϴ� �������� ������.                               */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	char word[20];
	char meaning[100];
}wordType;

//dict �迭���� w�� ����Ű�� �ܾ� ã��. count�� �迭�� ���� �ܾ� ����
char *search(char* w, wordType dict[], int count) {
	int i;
	for (i = 0; i < count; i++) {
		if (strcmp(w, dict[i].word)==0)//�迭�ܾ���� w�� ����Ű�� �ܾ��� ������
			return (dict[i].meaning);
	}
	return NULL;
}

//dict �迭�� w�� ����Ű�� �ܾ� �߰��ϱ� 
void insert(char* w, char *m, wordType dict[], int *cptr) {
	strcpy(dict[*cptr].word, w);//�迭���� ���ο� �ܾ� �� �߰�
	strcpy(dict[*cptr].meaning, m);//�ܾ� �� �߰�
	(*cptr)++;//�ܾ�� ����
}

//���Ͽ� ���ο� �ܾ��߰��ϱ�, oldcnt�� ���� ���� �ܾ� ��, newcnt�� �����ܾ� ��
void save_dicitionay(FILE* fp, wordType dict[], int oldcnt, int newcnt) {
	int i;
	fseek(fp, 0, SEEK_END);
	for (i = oldcnt; i < newcnt; i++) {
		if (fwrite((wordType*)&dict[i], sizeof(wordType), 1, fp) < 1) {
			fprintf(stderr, "Error writing a structure.\n");
			exit(1);
		}
	}
}

//�������� �о� �鸮��. �ܾ� ���� ��� *cptr ��, count�� ����
void read_dictionary(FILE* fp, wordType dict[], int *cptr) {
	*cptr = 0;
	while (fread((wordType*)&dict[*cptr], sizeof(wordType), 1, fp))
		(*cptr)++;
	if (!feof(fp)) {
		fprintf(stderr, "Error writing a structure.\n");
		exit(1);
	}
}

int main() {
	char word[20], *there;
	char meaning[100];
	int count, old_count;
	wordType mydict[5000];
	
	FILE* fp = fopen("append binary.bin", "a+b");
	read_dictionary(fp, &mydict, &count);
	old_count = count;
	while (1) {
		printf("Enter a word to search.\n");
		gets(word);
		if (strcmp(word, "quit") == 0) {
			save_dicitionay(fp, &mydict, old_count, count);
			break;
		}

		there = search(word, &mydict, count);
		if (there != NULL)
			puts(there);
		else {
			puts("No such word in current dictionary. Enter the meaning.");
			gets(meaning);
			insert(word, meaning, &mydict, &count);
		}
	}
	fclose(fp);
	return 0;
}