/* < C programing >                              Day 2019. 06. 06
 Project Title: Assignment 12. (14-6)
 Contents: 13���� ���� �������α׷��� ���� ������ ���Ͽ� �����ϰ�
 ������ ���� �Ҷ� �ٽ� �ҷ����� ���α׷��� �ۼ��϶�.           */
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

void save_dictionary(FILE* fp, dictType* d) {
	int i;
	fp = fopen("dictionary.bin", "wb"); //���� ��������� ���� ������� ����
	i = fwrite((dictType*)&d, sizeof(dictType), 1, fp); //���� ����ü �ϳ��� ����
	if (i < 1) {
		fprintf(stderr, "Error.\n");
		exit(1);
	}
	fclose(fp);
}


void read_dictionary(FILE* fp, dictType* d) {
	int i;
	if ((fp = fopen("dictionary.bin", "rb")) == NULL)//���� ������ ������
		d->count = 0; //���� ����ü�� count�� 0���� �ʱ�ȭ
	else {//���������� �ִٸ�
		i = fread((dictType*)&d, sizeof(dictType), 1, fp);//��������ü�� �ϳ� �о�帲
		if (i < 1) {
			fprintf(stderr, "Error.\n");
			exit(1);
		}
		fclose(fp);
	}
}

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
	strcpy(d->dict[(d->count)].word, w);
	strcpy(d->dict[(d->count)].meaning, m);
	d->count++;
}

int main() {
	char word[20], *there;
	char meaning[100];
	FILE* fp = NULL;
	dictType mydict;
	mydict.count = 0;

	read_dictionary(fp, &mydict);
	while (1) {
		printf("Enter a word to search.\n");
		gets(word);
		if (strcmp(word, "quit") == 0) {
			save_dictionary(fp, &mydict);
			break;
		}
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