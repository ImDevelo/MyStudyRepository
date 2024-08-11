/*
  < Tic_tac_toe Game >..................( ver. 1.5.2 )

  [Patch Note]
  -이제 컴퓨터가 무작위로 돌을 놓습니다.( ver. 1.1.0)
  -컴퓨터가 이길수 있는 상황과 질 수 있는 상황을 판별 합니다.( ver. 1.2.0 )
  -수를 두기 시작한지 몇 턴이 지났는지 알 수 있습니다.( ver. 1.2.1 )
  -컴퓨터가 이길수 있거나 질 수 있는 상황 (한줄에 2개가 있는 상황) 에서 자신이 공격 혹은 상대 공격을 방어를 할 수 있습니다. (ver 1.2.4 )
  -컴퓨터가 선공일때 자신이 유리한 첫 수를 둘 수 있습니다.( ver. 1.2.6 )
  -'공격모드'를 업데이트 합니다.( ver.1.3.0 )
  -컴퓨터의 유리한 선공을 두는 프로그램을 '공격모드'로 이전합니다.( ver 1.3.1 )
  -'공격 모드'에 전술이 업데이트 됩니다.( ver 1.3.2 )
  -전술_1 이 업데이트 되었습니다.(ver 1.3.3)
  -중복된 좌표 입력시 프로그램 종료합니다.(ver 1.3.4)
  -전술_2 가 업데이트 되었습니다. (ver. 1.3.6)
  -전술_3 가 업데이트 되었습니다. (ver. 1.3.8)
  -전술_4 가 업데이트 되었습니다. (ver. 1.3.10)
  -'방어 모드'가 업데이트 됩니다. (ver. 1.4.0)
  -모든 상황에서 방어가 가능해집니다. (ver 1.4.2)
  -이제 게임이 계속 반복됩니다.(ver 1.5.0)
  -점수표가 업데이트됩니다.(ver 1.5.2)
*/
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
void Defense_Mode(char b[][3], int t_count, int *m);
void Attack_Mode(char b[][3], int t_count,int *m);
void Tactical_set_1(char b[][3],int *m);
void Tactical_set_2(char b[][3],int *m);
void Tactical_set_3(char b[][3], int *m);
void Tactical_set_4(char b[][3], int m);
void diagonal_coner(char b[][3], int *m);
int coner_count(char b[][3]);

void Score(int a, int b, int c);


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

//점수판
void Score(int a, int b, int c) {
	printf("[ player: %d\tcomputer: %d\tdraw: %d ]\n", a, b, c);
}

//main
int main() {
	int turn, game_over, state;
	int Game_turn=0;
	char board[3][3];
	int turn_count = 0;
	int a, b, c;
	a = b = c = 0;
	srand(time(NULL));

	//게임 시작전 설정
	welcome_message();//첫 화면 업뎃
	printf("If you win three times, you win. \nIf the draw is five, the more the winner wins.\n");
	printf("\n\n\n");

	Game_turn = turn;
	
	while (1) {
		turn = who_first();
		//매 게임시작전 설정
		game_over = 0;
		init_board(board);//보드판 초기화

		printf("■■■■■[Game Start]■■■■■\n");
		Score(a, b, c);

	
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
				b++;
			}
			else if (state == 1) { // 플레이어 승리
				printf("player win.\n\n");
				game_over = 1;
				a++;
			}
			else if (state == 2) {// 무승부
				printf("It's draw.\n");
				game_over = 1;
				c++;
			}
			turn = (turn + 1) % 2;
		}
		turn = Game_turn++;
	}
	return 0;
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

//플레이어 턴
void human_move(char b[][3]) {
	int i, j;
	printf("It's YOUR turn. ");
	printf("Enter coordinates. For instance, 1 0\n");
	while (1) {
		scanf("%d%d", &i, &j);
		getchar();
		if (i < 0 || i>2 || j < 0 || j>2) { //잘못된것에 두면 프로그램 종료
			printf("Invalid coordinate exit the proram.\n");
		}
		else if(b[i][j]!=' ') {
			printf("Invalid coordinate, Please re-enter.\n ");
		}
		else {
			break;
		}
	}
	b[i][j] = 'O';
	printf("You moved as follows.\n");
}

// AI 턴
void computer_move(char b[][3], int t_count) {
	int i, j;
	int mode;

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
	mode = 0;
	if (t_count % 2)
		Attack_Mode(b, t_count, &mode);//승리 전략 전술 시스템
	else
		Defense_Mode(b, t_count, &mode);//방어 전략 전술 시스템
	
	if (mode)//전술을 찾았다면 1,못찾았다면 0;
		return;


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

//한줄에 2개가 쌓여있는 상황인지 판별
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

//그 해당 자리를 찾고 그 자리의 좌표를 리턴
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

//공격모드
void Attack_Mode(char b[][3],int t_count, int *m) {

	if (t_count == 1) {//만약 자신이 첫 수 라면 자신이 이길 수 있는 유리한 수를 둠
		Tactical_set_1(b,m);
		return;
	}
	else if (t_count == 3) {//다음 수에서 상대가 둔 곳에 따라 승리 전략 설계, 없다면 그냥 리턴
		if (b[1][1] == 'X') {
			Tactical_set_2(b, m);
		}
		else {
			if(b[1][1]!='O')
			Tactical_set_4(b, m);
		}
		return;
	}
	else if (t_count == 5) {
		if (b[1][1] == 'X' && (b[0][0] == 'X' || b[2][0] == 'X' || b[0][2] == 'X' || b[2][2] == 'X')) {
			Tactical_set_3(b, m);
			return;
		}
		else if ((coner_count(b) == 2 )&&(b[1][0] == 'O' || b[0][1] == 'O' || b[1][2] == 'O' || b[2][1] == 'O')) {
			Tactical_set_3(b, m);
		}
		else if (coner_count(b) == 2) {
			diagonal_coner(b, m);
			return;
		}
	}
	else {
		return;
	}
}

//방어모드
void Defense_Mode(char b[][3], int t_count, int *m) {
	if (t_count == 2) {
		if (b[1][1] == 'O') {
			diagonal_coner(b, m);
			return;
		}
		else {
			b[1][1] = 'X';
			*m = 1;
		}
		return;
	}
}

//전술법 set_1
void Tactical_set_1(char b[][3], int *m) {
	int st;
	//전술법1:유리한 수인 가운데 혹은 모서리에 두는 것에 랜덤성 부여 

	if (rand() % 2) {//중간
		if (b[1][1] == ' ') {
			b[1][1] = 'X';
			*m = 1;
			return;
		}
	}
	else {
		diagonal_coner(b, m);//모서리
		return;
	}

}

//전술법 set_2
void Tactical_set_2(char b[][3], int *m) {
	int st;
	if (b[0][0] == 'O' || b[2][0] == 'O' || b[0][2] == 'O' || b[2][2] == 'O') {
		return;
	}
	else {
		diagonal_coner(b, m);
		return;
	}
}

//전술법 set_3
void Tactical_set_3(char b[][3], int *m) {
	while (1) {
		if (b[0][0] == ' '&&b[0][1] != 'O'&&b[1][0] != 'O') {
			b[0][0] = 'X';
			*m = 1;
			return;
		}
		else if ( b[0][2] == ' '&&b[0][1] != 'O'&&b[1][2] != 'O') {
			b[0][2] = 'X';
			*m = 1;
			return;
		}
		else if (b[2][0] == ' '&&b[1][0] != 'O'&&b[2][1] != 'O') {
			b[2][0] = 'X';
			*m = 1;
			return;
		}
		else if (b[2][2] == ' '&&b[2][1] != 'O'&&b[1][2] != 'O') {
			b[2][2] = 'X';
			*m = 1;
			return;
		}
	}


}

//전술법 set_4
void Tactical_set_4(char b[][3], int m) {
	if (b[1][0] == 'O' || b[0][1] == 'O' || b[2][1] == 'O' || b[1][2] == 'O') {
		Tactical_set_1(b, m);
		return;
	}
	else {
		diagonal_coner(b, m);
		return;
	}
}

//각 코너에 랜덤으로 두는 함수
void diagonal_coner(char b[][3], int *m) {
	int st;
	while (1) {
		st = (1 + rand() % 4);
		if (b[0][0] != ' '&&b[2][0] != ' '&&b[0][2] != ' '&&b[2][2] != ' ') {
			return;
		}
		else if (st == 1 && b[0][0] == ' ') {
			b[0][0] = 'X';
			*m = 1;
			return;
		}
		else if (st == 2 && b[0][2] == ' ') {
			b[0][2] = 'X';
			*m = 1;
			return;
		}
		else if (st == 3 && b[2][0] == ' ') {
			b[2][0] = 'X';
			*m = 1;
			return;
		}
		else if (st == 4 && b[2][2] == ' ') {
			b[2][2] = 'X';
			*m = 1;
			return;
		}
	}
}

//코너에 자신의 돌이 몇개인지 세는 함수
int coner_count(char b[][3]) {
	int count=0;
	if (b[0][0] == 'X')
		count++;
	if (b[0][2] == 'X')
		count++;
	if (b[2][2] == 'X')
		count++;
	if (b[2][0] == 'X')
		count++;
	return count;
}
