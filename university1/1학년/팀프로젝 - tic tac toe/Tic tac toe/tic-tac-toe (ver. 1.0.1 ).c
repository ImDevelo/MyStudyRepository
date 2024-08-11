/*
  < Tic_tac_toe Game >..................( ver. 1.0.1 )

  [Patch Note]
  -이제 컴퓨터가 무작위로 돌을 놓습니다.
*/

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
//함수 정의
void init_board(char b[][3]);
void welcome_message();
void draw_board(char b[][3]);
int who_first();
void human_move(char b[][3]);
void computer_move(char b[][3],int t_count);
int cheak(char b[][3], char ch);
//새로운 함수정의
void find_two_point(char b[][3], char ch, int *p, int *q);
int cheak_two_point(char b[][3], char ch);
void Defence_mode();
void Attack_mode();

///////////////////////////////////////////////////////////////////////////////////////

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
	int turn_count = 0;
	srand(time(NULL));
	

	welcome_message();//첫 화면 업뎃
	init_board(board);//보드판 초기화
	turn = who_first();//순서 결정


	while (!game_over) {
		if (turn == 1) { //사람차례 (입력)
			turn_count++;
			human_move(board);
			state = cheak(board, 'O');//사람이 찍는 표시는 0
			
		}
		else { //컴퓨터차례 (입력)
			turn_count++;
			computer_move(board, turn_count);
			state = cheak(board, 'X');//컴퓨터가 찍는 표시는 X
			
		}

		draw_board(board); //보드 결과 출력 (결과)
		

		//승리판별
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
	b[i][j] = 'O';
	printf("You moved as follows.\n");
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
	printf("| %c | %c | %c |\n", b[i][0], b[i][1], b[i][2]);
}
printf("|---|---|---|\n\n");
}




///////////////////인공지능 구현/////////////////////////////

// AI 턴
void computer_move(char b[][3], int t_count) {
	int i, j;

	//자신이 이길 수 있는 상황이라면 공격
	if (cheak_two_point(b, 'X')) {
		find_two_point(b, 'X', &i, &j);
		b[i][j] = 'X';
		return;
	}
	//상대가 이길 수 있는 상황이라면 방어
	else if (cheak_two_point(b, 'O')) {
		find_two_point(b, 'O', &i, &j);
		b[i][j] = 'X';
		return;
	}



	//어떤경우도 아니라면 랜덤으로 아무곳에 둠
	while (1) {
		i = (rand() % 3);
		j = (rand() % 3);
		if (b[i][j] == ' ') {
			b[i][j] = 'X';
			return;
		}
	}

}

int cheak_two_point(char b[][3], char ch) {
	int i;

	//가로 판별
	for (i = 0; i < 3; i++) {
		if ((b[i][0] == ch && b[i][1] == ch && b[i][2] == ' ') || (b[i][0] == ch && b[i][1] == ' '&& b[i][2] == ch) || (b[i][0] == ' '&& b[i][1] == ch && b[i][2] == ch))
			return 1;
	}
	//세로 판별
	for (i = 0; i < 3; i++) {
		if ((b[0][i] == ch && b[1][i] == ch && b[2][i] == ' ') || (b[0][i] == ch && b[1][i] == ' '&& b[2][i] == ch) || (b[0][i] == ' '&& b[1][i] == ch && b[2][i] == ch))
			return 1;
	}
	//대각선 판별
	if ((b[0][0] == ch && b[1][1] == ch && b[2][2] == ' ') || (b[0][0] == ch && b[1][1] == ' '&& b[2][2] == ch) || (b[0][0] == ' '&& b[1][1] == ch && b[2][2] == ch))
		return 1;
	if ((b[0][2] == ch && b[1][1] == ch && b[2][0] == ' ') || (b[0][2] == ch && b[1][1] == ' '&& b[2][0] == ch) || (b[0][2] == ' '&& b[1][1] == ch && b[2][0] == ch))
		return 1;

	return 0;
}

void find_two_point(char b[][3], char ch, int *p, int *q) {
	int i;
	//가로
	for (i = 0; i < 3; i++) {
		if (b[i][0] == ch && b[i][1] == ch && b[i][2] == ' ') {
			*p = i;
			*q = 2;
			return;
		}
		else if (b[i][0] == ch && b[i][1] == ' '&& b[i][2] == ch) {
			*p = i;
			*q = 1;
			return;
		}
		else if (b[i][0] == ' '&& b[i][1] == ch && b[i][2] == ch) {
			*p = i;
			*q = 0;
			return;
		}
	}
	//세로
	for (i = 0; i < 3; i++) {
		if (b[0][i] == ch && b[1][i] == ch && b[2][i] == ' ') {
			*p = 2;
			*q = i;
			return;
		}
		else if (b[0][i] == ch && b[1][i] == ' '&& b[2][i] == ch) {
			*p = 1;
			*q = i;
			return;
		}
		else if (b[0][i] == ' '&& b[1][i] == ch && b[2][i] == ch) {
			*p = 0;
			*q = i;
			return;
		}
	}

	//대각선
	if (b[0][0] == ch && b[1][1] == ch && b[2][2] == ' ') {
		*p = 2;
		*q = 2;
		return;
	}
	else if (b[0][0] == ch && b[1][1] == ' '&& b[2][2] == ch) {
		*p = 1;
		*q = 1;
		return;
	}
	else if (b[0][0] == ' '&& b[1][1] == ch && b[2][2] == ch) {
		*p = 0;
		*q = 0;
		return;
	}
	else if (b[0][2] == ch && b[1][1] == ch && b[2][0] == ' ') {
		*p = 2;
		*q = 0;
		return;
	}
	else if (b[0][2] == ch && b[1][1] == ' '&& b[2][0] == ch) {
		*p = 1;
		*q = 1;
		return;
	}
	else if (b[0][2] == ' '&& b[1][1] == ch && b[2][0] == ch) {
		*p = 0;
		*q = 2;
		return;
	}
}


//전술부여
void Attack_Mode() {

}

void Defence_Mode() {

}











