/* < C programing >                             Day 2019. 06. 06
 Project Title: Assignment 12. (13-6)
 Contents: ������ ���� p�� ����Ű�� ����ü�� ���� �Է¹ް� �� ��
 �� ����ϴ� ���α׷��� ������.                             */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char* name; //�����۸�
	int price; //�ܰ�
}infoTtpe;

typedef struct {
	infoTtpe item; //������ ����
	int seasonal_sales[4]; //������ �Ǹŷ�
}itemType;

int main() {
	itemType* p = (itemType*)malloc(sizeof(itemType)); //p�Ҵ�
	int i, sum = 0;
	char temp[30];
	//��ǰ�� �Է�
	printf("Enter item name.\n");
	gets(temp);
	p->item.name = (char*)malloc(sizeof(char)*(strlen(temp)+1));
	strcpy(p->item.name, temp);
	//����
	printf("Enter unit price.\n");
	scanf("%d", &p->item.price);
	//������ �Ǹŷ�
	printf("Enter seasonal sales.\n");
	for (i = 0; i < 4; i++) {
		scanf("%d", &p->seasonal_sales[i]);
		sum += p->seasonal_sales[i];
	}
	//���
	printf("Yearly income of %s is %d\n", p->item.name, sum*(p->item.price));
	return 0;
}