/* < C programing >                            Day 2019. 06. 06
 Project Title: Assignment 12. (13-2)
 Contents: ����üb�� a�� �����ϱ� ���� ���� ���縦 ����Ͽ� �ش�
 ���α׷��� �ۼ��϶�                                          */
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

//����ü ����
void copy_structure(personType *to, const personType *from) {
	to->name = (personType*)malloc(5 * sizeof(personType));//�Ҵ�
	*to = *from;//����
}

//����ü ���
void print_structure(const personType *p) {
	printf("name is %s, age is %d.\n", p->name, p->age);
}
