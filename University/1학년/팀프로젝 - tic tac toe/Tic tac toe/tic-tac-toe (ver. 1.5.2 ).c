/*
  < Tic_tac_toe Game >..................( ver. 1.5.2 )

  [Patch Note]
  -���� ��ǻ�Ͱ� �������� ���� �����ϴ�.( ver. 1.1.0)
  -��ǻ�Ͱ� �̱�� �ִ� ��Ȳ�� �� �� �ִ� ��Ȳ�� �Ǻ� �մϴ�.( ver. 1.2.0 )
  -���� �α� �������� �� ���� �������� �� �� �ֽ��ϴ�.( ver. 1.2.1 )
  -��ǻ�Ͱ� �̱�� �ְų� �� �� �ִ� ��Ȳ (���ٿ� 2���� �ִ� ��Ȳ) ���� �ڽ��� ���� Ȥ�� ��� ������ �� �� �� �ֽ��ϴ�. (ver 1.2.4 )
  -��ǻ�Ͱ� �����϶� �ڽ��� ������ ù ���� �� �� �ֽ��ϴ�.( ver. 1.2.6 )
  -'���ݸ��'�� ������Ʈ �մϴ�.( ver.1.3.0 )
  -��ǻ���� ������ ������ �δ� ���α׷��� '���ݸ��'�� �����մϴ�.( ver 1.3.1 )
  -'���� ���'�� ������ ������Ʈ �˴ϴ�.( ver 1.3.2 )
  -����_1 �� ������Ʈ �Ǿ����ϴ�.(ver 1.3.3)
  -�ߺ��� ��ǥ �Է½� ���α׷� �����մϴ�.(ver 1.3.4)
  -����_2 �� ������Ʈ �Ǿ����ϴ�. (ver. 1.3.6)
  -����_3 �� ������Ʈ �Ǿ����ϴ�. (ver. 1.3.8)
  -����_4 �� ������Ʈ �Ǿ����ϴ�. (ver. 1.3.10)
  -'��� ���'�� ������Ʈ �˴ϴ�. (ver. 1.4.0)
  -��� ��Ȳ���� �� ���������ϴ�. (ver 1.4.2)
  -���� ������ ��� �ݺ��˴ϴ�.(ver 1.5.0)
  -����ǥ�� ������Ʈ�˴ϴ�.(ver 1.5.2)
*/
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

//������
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

	//���� ������ ����
	welcome_message();//ù ȭ�� ����
	printf("If you win three times, you win. \nIf the draw is five, the more the winner wins.\n");
	printf("\n\n\n");

	Game_turn = turn;
	
	while (1) {
		turn = who_first();
		//�� ���ӽ����� ����
		game_over = 0;
		init_board(board);//������ �ʱ�ȭ

		printf("������[Game Start]������\n");
		Score(a, b, c);

	
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
				b++;
			}
			else if (state == 1) { // �÷��̾� �¸�
				printf("player win.\n\n");
				game_over = 1;
				a++;
			}
			else if (state == 2) {// ���º�
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

//�÷��̾� ��
void human_move(char b[][3]) {
	int i, j;
	printf("It's YOUR turn. ");
	printf("Enter coordinates. For instance, 1 0\n");
	while (1) {
		scanf("%d%d", &i, &j);
		getchar();
		if (i < 0 || i>2 || j < 0 || j>2) { //�߸��ȰͿ� �θ� ���α׷� ����
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

// AI ��
void computer_move(char b[][3], int t_count) {
	int i, j;
	int mode;

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
	mode = 0;
	if (t_count % 2)
		Attack_Mode(b, t_count, &mode);//�¸� ���� ���� �ý���
	else
		Defense_Mode(b, t_count, &mode);//��� ���� ���� �ý���
	
	if (mode)//������ ã�Ҵٸ� 1,��ã�Ҵٸ� 0;
		return;


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

//���ٿ� 2���� �׿��ִ� ��Ȳ���� �Ǻ�
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

//�� �ش� �ڸ��� ã�� �� �ڸ��� ��ǥ�� ����
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

//���ݸ��
void Attack_Mode(char b[][3],int t_count, int *m) {

	if (t_count == 1) {//���� �ڽ��� ù �� ��� �ڽ��� �̱� �� �ִ� ������ ���� ��
		Tactical_set_1(b,m);
		return;
	}
	else if (t_count == 3) {//���� ������ ��밡 �� ���� ���� �¸� ���� ����, ���ٸ� �׳� ����
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

//�����
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

//������ set_1
void Tactical_set_1(char b[][3], int *m) {
	int st;
	//������1:������ ���� ��� Ȥ�� �𼭸��� �δ� �Ϳ� ������ �ο� 

	if (rand() % 2) {//�߰�
		if (b[1][1] == ' ') {
			b[1][1] = 'X';
			*m = 1;
			return;
		}
	}
	else {
		diagonal_coner(b, m);//�𼭸�
		return;
	}

}

//������ set_2
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

//������ set_3
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

//������ set_4
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

//�� �ڳʿ� �������� �δ� �Լ�
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

//�ڳʿ� �ڽ��� ���� ����� ���� �Լ�
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
