/* < C programing >                              Day 2019. 06. 06
 Project Title: Assignment 12. (14-6)
 Contents: 13장의 영한 사전프로그램을 사전 내용을 파일에 저장하고
 다음에 실행 할때 다시 불러오는 프로그램을 작성하라.           */
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
	fp = fopen("dictionary.bin", "wb"); //이전 내용지우고 새로 쓰기모드로 열기
	i = fwrite((dictType*)&d, sizeof(dictType), 1, fp); //사전 구조체 하나를 저장
	if (i < 1) {
		fprintf(stderr, "Error.\n");
		exit(1);
	}
	fclose(fp);
}


void read_dictionary(FILE* fp, dictType* d) {
	int i;
	if ((fp = fopen("dictionary.bin", "rb")) == NULL)//기존 파일이 없으면
		d->count = 0; //사전 구조체의 count를 0으로 초기화
	else {//기존파일이 있다면
		i = fread((dictType*)&d, sizeof(dictType), 1, fp);//사전구조체를 하나 읽어드림
		if (i < 1) {
			fprintf(stderr, "Error.\n");
			exit(1);
		}
		fclose(fp);
	}
}

char *search(char* w, dictType *d) {
	int i;
	for (i = 0; i <= d->count; i++) {//i가 count보다 작을 때 까지
		if (strcmp(w, d->dict[i].word) == 0) //문자열 비교   
			return (d->dict[i].meaning);
	}
	return NULL;
}

//d가 가르키는 사전에 w가 가르키는 단어 명과 m이 가르키는 단어 뜻을 삽입
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
		if (there != NULL) //단어를 찾았으면
			puts(there); //찾은 단어의 뜻을 디스플레이
		else {
			puts("No such word in dictionary. Enter the meaning.");
			gets(meaning);
			insert(word, meaning, &mydict);//새로운 단어 삽입
		}
	}
	return 0;
}