//주사위 굴리기
//https://www.acmicpc.net/problem/14499
#include<iostream>
using namespace std;
#define MAX 20

class Dice {
    int dice[4][3] = { 0 };
    int floor_r, floor_c;
    int ceiling_r, ceiling_c;
public:
    Dice() {
        ceiling_r = 1; floor_r = 3;
        ceiling_c = 1; floor_c = 1;
    }
    void rollUp() {
        floor_r -= 1;
        ceiling_r -= 1;
        if (floor_r < 0) floor_r = 3;
        if (ceiling_r < 0) ceiling_r = 3;
    }
    void rollDown() {
        floor_r += 1;
        ceiling_r += 1;
        if (floor_r > 3) floor_r = 0;
        if (ceiling_r > 3) ceiling_r = 0;
    }
    void rollLeft() {
        floor_c -= 1;
        ceiling_c -= 1;
        if (floor_c < 0) floor_c = 2;
        if (ceiling_c < 0) ceiling_c = 2;
    }
    void rollRight() {
        floor_c += 1;
        ceiling_c += 1;
        if (floor_c > 2) floor_c = 0;
        if (ceiling_c > 2) ceiling_c = 0;
    }
    int getFloor() {
        int return_value = dice[floor_r][floor_c];
        if (floor_c == 0)
            for (int i = 0; i < 3; i++) dice[i][0] = 0;
        else if (floor_c == 2)
            for (int i = 0; i < 3; i++) dice[i][2] = 0;
        return return_value;
    }
    int getCeiling() {
        return dice[ceiling_r][ceiling_c];
    }

    void setFloor(int n) {
        dice[floor_r][floor_c] = n;
        if (floor_c == 0)
            for (int i = 0; i < 3; i++) dice[i][0] = dice[floor_r][floor_c];
        else if (floor_c == 2)
            for (int i = 0; i < 3; i++) dice[i][2] = dice[floor_r][floor_c];
    }

};

int arr[MAX][MAX];
Dice dice;

void setDice(int r_dice_pos, int c_dice_pos) {
    if (arr[r_dice_pos][c_dice_pos] == 0) {
        arr[r_dice_pos][c_dice_pos] = dice.getFloor();
    }
    else {
        dice.setFloor(arr[r_dice_pos][c_dice_pos]);
    }
    cout << dice.getCeiling() << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int R, C, r_start, c_start, T;


    cin >> R >> C >> r_start >> c_start >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    int r_dice_pos = r_start, c_dice_pos = c_start;
    for (int i = 0, test; i < T; i++) {
        cin >> test;
        switch (test)
        {
        case 1: //동 
            if (c_dice_pos + 1 < C) {
                c_dice_pos += 1;
                dice.rollRight();
                setDice(r_dice_pos, c_dice_pos);
            } break;
        case 2: //서
            if (c_dice_pos - 1 >= 0) {
                c_dice_pos -= 1;
                dice.rollLeft();
                setDice(r_dice_pos, c_dice_pos);
            } break;
        case 3: //북
            if (r_dice_pos - 1 >= 0) {
                r_dice_pos -= 1;
                dice.rollUp();
                setDice(r_dice_pos, c_dice_pos);
            } break;
        case 4: //님 
            if (r_dice_pos + 1 < R) {
                r_dice_pos += 1;
                dice.rollDown();
                setDice(r_dice_pos, c_dice_pos);
            } break;
        }
    }
}