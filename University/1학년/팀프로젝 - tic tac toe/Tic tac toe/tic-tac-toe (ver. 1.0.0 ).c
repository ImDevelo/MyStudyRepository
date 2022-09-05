#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
//함수 정의
void init_board(char b[][3]);
void welcome_message();
void draw_board(char b[][3]);
int who_first();
void human_move(char b[][3]);
void computer_move(char b[][3]);

//메세지 출력
void welcome_message() {
	printf("Welcome to my tic-tac-toe game.\n");
	printf("The corrdinates are,\n");
	printf("|---|---|---|\n");
	printf("|0 0|0 1|0 2|\n");
	printf("|---|---|---|\n");
	printf("|1 0|1 1|1 2|\n");
	printf("|---|---|---|\n");
	printf("|2 0|2 1|2 2|\n");
	printf("|---|---|---|\n");
}

//순서 결정
int who_first() {  //return 1 for human, 0 for computer
	char ch;
	printf("play first? (Y/N)\n");
	scanf("%c", &ch);
	if (ch == 'Y' || ch == 'y')
		return 1;
	else
		return 0;
}

//보드판 초기화
void init_board(char b[][3]) { //initialize whit a blank character
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			b[i][j] = ' ';
	}
}

//main
int main() {
	int turn, game_over = 0, state;
	char board[3][3];
	
	welcome_message();//첫 화면 업뎃
	init_board(board);//보드판 초기화
	turn = who_first();//순서 결정

	while (!game_over) {
		if (turn == 1) { //사람차례 (입력)
			human_move(board);
			state = cheak(board, '0');//사람이 찍는 표시는 0
		}
		else { //컴퓨터차례 (입력)
			computer_move(board);
			state = cheak(board, 'X');//컴퓨터가 찍는 표시는 X
		}

		draw_board(board); //보드 결과 출력 (결과)

		if (state == 0) { //컴터 승리
			printf("Computer win.\n\n");
			game_over = 1;
		}
		else if (state == 1) { // 플레이어 승리
			printf("player win.\n\n");
			game_over = 1;
		}
		else if (state == 2) {// 무승부
			printf("It's draw.\n");
			game_over = 1;
		}
		turn = (turn + 1) % 2;
	}
	return 0;

}

//플레이어 턴
void human_move(char b[][3]) {
	int i, j;
	printf("It's YOUR turn. ");
	printf("Enter coordinates. For instance, 1 0\n");
	scanf("%d%d", &i, &j);
	if (i < 0 || i>2 || j < 0 || j>2) { //잘못된것에 두면 프로그램 종료
		printf("Invalid coordinate exit the proram.\n");
		exit(1);
	}
	b[i][j] = '0';
	printf("You moved as follows.\n");
}

// AI 턴
void computer_move(char b[][3]) {
	int i, j;
	printf("Computer moved as follows.\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			if (b[i][j] == ' ') {
				b[i][j] = 'X';
				return;
			}
	}
}

// 승리 판별
int cheak(char b[][3], char ch) {
	int i, j, matched = 0, count = 0;

	for (i = 0; i < 3; i++) //horizontal line cheak
		if (b[i][0] == ch && b[i][1] == ch && b[i][2] == ch)
			matched = 1;

	for (j = 0; j < 3; j++)//vertical line cheak
		if (b[0][j] == ch && b[1][j] == ch && b[2][j] == ch)
			matched = 1;

	if (b[1][1] == ch) {//diagonal line cheak
		if ((b[0][0] == ch && b[2][2] == ch) || (b[0][2] == ch && b[2][0] == ch))
			matched = 1;

	}

	if (matched) {
		if (ch == 'X')
			return 0;//computer won
		else
			return 1;//human won
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (b[i][j] == ' ')
				count++;
		}
	}
	if (count == 0)
		return 2;
	return 3;
}

// 보드판 출력
void draw_board(char b[][3]) {
	int i;
	for (i = 0; i < 3; i++) {
		printf("|---|---|---|\n");
		printf("| %c | %c | %c |\n",b[i][0],b[i][1],b[i][2]);
	}
	printf("|---|---|---|\n\n");
}
