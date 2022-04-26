/* < C programing >                             Day 2019. 06. 06
 Project Title: Assignment 12. (13-6)
 Contents: 문제와 같은 p가 가르키는 구조체에 값을 입력받고 그 값
 을 계산하는 프로그램을 만들어라.                             */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char* name; //아이템명
	int price; //단가
}infoTtpe;

typedef struct {
	infoTtpe item; //아이템 정보
	int seasonal_sales[4]; //계절별 판매량
}itemType;

int main() {
	itemType* p = (itemType*)malloc(sizeof(itemType)); //p할당
	int i, sum = 0;
	char temp[30];
	//상품명 입력
	printf("Enter item name.\n");
	gets(temp);
	p->item.name = (char*)malloc(sizeof(char)*(strlen(temp)+1));
	strcpy(p->item.name, temp);
	//가격
	printf("Enter unit price.\n");
	scanf("%d", &p->item.price);
	//계절별 판매량
	printf("Enter seasonal sales.\n");
	for (i = 0; i < 4; i++) {
		scanf("%d", &p->seasonal_sales[i]);
		sum += p->seasonal_sales[i];
	}
	//출력
	printf("Yearly income of %s is %d\n", p->item.name, sum*(p->item.price));
	return 0;
}