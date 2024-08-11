/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-11)
 Contents: 하노이탑 문제                                    */
#include<stdio.h>
//하노이탑 알고리즘  X->Y로 옮김
void move(int N, char x, char y, char z) {
	if (N == 1) {
		printf("move a disk from %c to %c\n", x, y); 
		return;
	}
	else {
		move(N - 1, x, z, y);
		move(1, x, y, z);
		move(N - 1, z, y, x);
	}
}

int main() {
	int Num;
	printf("Enter the number of disk.\n");
	scanf("%d", &Num);
	move(Num,'X','Y','Z');
	return 0;
}