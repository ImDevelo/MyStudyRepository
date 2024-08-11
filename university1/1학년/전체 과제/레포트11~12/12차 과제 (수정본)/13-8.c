/* < C programing >                               Day 2019. 06. 06
 Project Title: Assignment 12. (13-8)
 Contents: 다음 프로그램을 완성하여 영한사전을 완성하라. 단 임력된
 단억 있다면 그 뜻을 디스플레이하고 그렇지 않으면 그 단어를 사전에
 추가하라 프로그램에 quit가 입력될때 까지 실행되어야한다.       */
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

//d가 가르키는 사전에서 w가 가리키는 단어를 찾아 meaning을 리턴
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