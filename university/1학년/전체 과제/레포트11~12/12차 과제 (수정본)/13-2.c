/* < C programing >                            Day 2019. 06. 06
 Project Title: Assignment 12. (13-2)
 Contents: 구조체b를 a로 복사하기 위해 깊은 복사를 사용하여 해당
 프로그램을 작성하라                                          */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	char *name;
	int age;
}personType;

void copy_structure(personType *to, const personType *from);
void print_structure(const personType *p);
int main() {
	personType a, b = { "Park",19 };	
	print_structure(&b);
	copy_structure(&a, &b);
	print_structure(&a);
	return 0;
}

//구조체 복사
void copy_structure(personType *to, const personType *from) {
	to->name = (personType*)malloc(5 * sizeof(personType));//할당
	*to = *from;//복사
}

//구조체 출력
void print_structure(const personType *p) {
	printf("name is %s, age is %d.\n", p->name, p->age);
}
