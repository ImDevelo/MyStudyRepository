/*
  < Tic_tac_toe Game >..................( ver. 1.0.1 )

  [Patch Note]
  -���� ��ǻ�Ͱ� �������� ���� �����ϴ�.
*/

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
//�Լ� ����
void init_board(char b[][3]);
void welcome_message();
void draw_board(char b[][3]);
int who_first();
void human_move(char b[][3]);
void computer_move(char b[][3],int t_count);
int cheak(char b[][3], char ch);
//���ο� �Լ�����
void find_two_point(char b[][3], char ch, int *p, int *q);
int cheak_two_point(char b[][3], char ch);
void Defence_mode();
void Attack_mode();

///////////////////////////////////////////////////////////////////////////////////////

//�޼��� ���
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

//���� ����
int who_first() {  //return 1 for human, 0 for computer
	char ch;
	printf("play first? (Y/N)\n");
	scanf("%c", &ch);
	if (ch == 'Y' || ch == 'y')
		return 1;
	else
		return 0;
}

//������ �ʱ�ȭ
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
	

	welcome_message();//ù ȭ�� ����
	init_board(board);//������ �ʱ�ȭ
	turn = who_first();//���� ����


	while (!game_over) {
		if (turn == 1) { //������� (�Է�)
			turn_count++;
			human_move(board);
			state = cheak(board, 'O');//����� ��� ǥ�ô� 0
			
		}
		else { //��ǻ������ (�Է�)
			turn_count++;
			computer_move(board, turn_count);
			state = cheak(board, 'X');//��ǻ�Ͱ� ��� ǥ�ô� X
			
		}

		draw_board(board); //���� ��� ��� (���)
		

		//�¸��Ǻ�
		if (state == 0) { //���� �¸�
			printf("Computer win.\n\n");
			game_over = 1;
		}
		else if (state == 1) { // �÷��̾� �¸�
			printf("player win.\n\n");
			game_over = 1;
		}
		else if (state == 2) {// ���º�
			printf("It's draw.\n");
			game_over = 1;
		}
		turn = (turn + 1) % 2;
	}
	return 0;

}

//�÷��̾� ��
void human_move(char b[][3]) {
	int i, j;
	printf("It's YOUR turn. ");
	printf("Enter coordinates. For instance, 1 0\n");
	scanf("%d%d", &i, &j);
	if (i < 0 || i>2 || j < 0 || j>2) { //�߸��ȰͿ� �θ� ���α׷� ����
		printf("Invalid coordinate exit the proram.\n");
		exit(1);
	}
	b[i][j] = 'O';
	printf("You moved as follows.\n");
}

// �¸� �Ǻ�
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

// ������ ���
void draw_board(char b[][3]) {
	int i;

for (i = 0; i < 3; i++) {
	printf("|---|---|---|\n");
	printf("| %c | %c | %c |\n", b[i][0], b[i][1], b[i][2]);
}
printf("|---|---|---|\n\n");
}




///////////////////�ΰ����� ����/////////////////////////////

// AI ��
void computer_move(char b[][3], int t_count) {
	int i, j;

	//�ڽ��� �̱� �� �ִ� ��Ȳ�̶�� ����
	if (cheak_two_point(b, 'X')) {
		find_two_point(b, 'X', &i, &j);
		b[i][j] = 'X';
		return;
	}
	//��밡 �̱� �� �ִ� ��Ȳ�̶�� ���
	else if (cheak_two_point(b, 'O')) {
		find_two_point(b, 'O', &i, &j);
		b[i][j] = 'X';
		return;
	}



	//���쵵 �ƴ϶�� �������� �ƹ����� ��
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

	//���� �Ǻ�
	for (i = 0; i < 3; i++) {
		if ((b[i][0] == ch && b[i][1] == ch && b[i][2] == ' ') || (b[i][0] == ch && b[i][1] == ' '&& b[i][2] == ch) || (b[i][0] == ' '&& b[i][1] == ch && b[i][2] == ch))
			return 1;
	}
	//���� �Ǻ�
	for (i = 0; i < 3; i++) {
		if ((b[0][i] == ch && b[1][i] == ch && b[2][i] == ' ') || (b[0][i] == ch && b[1][i] == ' '&& b[2][i] == ch) || (b[0][i] == ' '&& b[1][i] == ch && b[2][i] == ch))
			return 1;
	}
	//�밢�� �Ǻ�
	if ((b[0][0] == ch && b[1][1] == ch && b[2][2] == ' ') || (b[0][0] == ch && b[1][1] == ' '&& b[2][2] == ch) || (b[0][0] == ' '&& b[1][1] == ch && b[2][2] == ch))
		return 1;
	if ((b[0][2] == ch && b[1][1] == ch && b[2][0] == ' ') || (b[0][2] == ch && b[1][1] == ' '&& b[2][0] == ch) || (b[0][2] == ' '&& b[1][1] == ch && b[2][0] == ch))
		return 1;

	return 0;
}

void find_two_point(char b[][3], char ch, int *p, int *q) {
	int i;
	//����
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
	//����
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

	//�밢��
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


//�����ο�
void Attack_Mode() {

}

void Defence_Mode() {

}











