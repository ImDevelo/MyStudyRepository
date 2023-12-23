#pragma once
#include <iostream>
using namespace std;
//흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b.
// U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면

class Cube
{
public:
	Cube() {
		int currentCudeColor = 0;
		for (int  k = 0; k < 6; k++){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 3; j++){
					cube[k][i][j] = currentCudeColor;
				}
			}
			currentCudeColor++;
		}
	}

	void rotateCube(const char _face, const char _direction) {
		char face = _face;
		bool clockwiseRotation = (_direction == '+'); // 시계방향
		switch (face)
		{
		case 'U': //윗 면
			rotateX(0, clockwiseRotation);
			rotateFaceClockwise(0, clockwiseRotation);
			break;
		case 'D': //아랫 면
			rotateX(2, !clockwiseRotation);
			rotateFaceClockwise(2, clockwiseRotation);
			break;
		case 'F': //앞 면
			rotateY(0, clockwiseRotation);
			rotateFaceClockwise(1, clockwiseRotation);
			break;
		case 'B': //뒷 면
			rotateY(2, !clockwiseRotation);
			rotateFaceClockwise(3, clockwiseRotation);
			break;
		case 'L': //왼쪽 면
			rotateZ(0,clockwiseRotation);
			rotateFaceClockwise(4, clockwiseRotation);
			break;
		case 'R': //오른쪽 면
			rotateZ(2,!clockwiseRotation);
			rotateFaceClockwise(5, clockwiseRotation);
			break;
		default:
			break;
		}
	}

	void rotateFaceClockwise(int _face, bool rotationDirection) {
		const int face = _face;
		int temp[3][3];
		for (int i = 0; i < 1; ++i) {
			for (int j = i; j < 2 - i; ++j) {
				int temp = cube[face][i][j];
				if (!rotationDirection) {
					cube[face][i][j] = cube[face][j][2 - i];
					cube[face][j][2 - i] = cube[face][2 - i][2 - j];
					cube[face][2 - i][2 - j] = cube[face][2 - j][i];
					cube[face][2 - j][i] = temp;
				}
				else {
					cube[face][i][j] = cube[face][2 - j][i];
					cube[face][2 - j][i] = cube[face][2 - i][2 - j];
					cube[face][2 - i][2 - j] = cube[face][j][2 - i];
					cube[face][j][2 - i] = temp;
				}
				
			}
		}
	}

	void rotateX(int _side, bool _direct) {
		const int side = _side, direct = _direct;
		const int rotateRule[2][4] = { {1, 4, 3, 5}, { 1,5,3,4 } };
		int tempCube[3];

		for (int i = 0; i < 3; i++) {
			tempCube[i] = cube[rotateRule[direct][0]][side][i];
		}

		for (int r = 0; r < 3; r++) {
			int currentFace = rotateRule[direct][r];
			int nextFace = rotateRule[direct][r + 1];
			for (int i = 0; i < 3; i++) {
				cube[currentFace][side][i] = cube[nextFace][side][i];
			}
		}

		for (int i = 0; i < 3; i++) {
			cube[rotateRule[direct][3]][side][i] = tempCube[i];
		}
	}

	//0->5

	void rotateY(int _side, bool _direct) {
		const int side = _side, direct = _direct;
		const int rotateRule[2][4] = { {0,5,2,4}, {5,0,4,2} };
		int tempCube[3];
		cout << "회전해!" << _side << " " << _direct << endl;
		
		if (_direct) {
			for (int i = 0; i < 3; i++) { //?<-5번
				tempCube[i] = cube[rotateRule[direct][0]][side ^ 2][i];
			}
			for (int i = 0; i < 3; i++) { //5번 <- 0번
				cube[rotateRule[direct][0]][side ^ 2][i] = cube[rotateRule[direct][1]][i][side];
			}
			for (int i = 0; i < 3; i++) { //0번 <- 4번 
				cube[rotateRule[direct][1]][i][side] = cube[rotateRule[direct][2]][side][2 - i];
			}
			for (int i = 0; i < 3; i++) { //4번 <- 2번
				cube[rotateRule[direct][2]][side][i] = cube[rotateRule[direct][3]][i][side ^ 2];
			}
			for (int i = 0; i < 3; i++) {//2번<-?
				cube[rotateRule[direct][3]][i][side ^ 2] = tempCube[i];
			}
		}
		else {
			for (int i = 0; i < 3; i++) { //?<-5번
				tempCube[i] = cube[rotateRule[direct][0]][side ^ 2][i];
			}
			for (int i = 0; i < 3; i++) { //5번 <- 0번
				cube[rotateRule[direct][0]][side ^ 2][i] = cube[rotateRule[direct][1]][i][side];
			}
			for (int i = 0; i < 3; i++) { //0번 <- 4번 
				cube[rotateRule[direct][1]][i][side] = cube[rotateRule[direct][2]][side][2 - i];
			}
			for (int i = 0; i < 3; i++) { //4번 <- 2번
				cube[rotateRule[direct][2]][side][i] = cube[rotateRule[direct][3]][i][side ^ 2];
			}
			for (int i = 0; i < 3; i++) {//2번<-?
				cube[rotateRule[direct][3]][i][side ^ 2] = tempCube[i];
			}
		}
	}

	void rotateZ(int _side, bool _direct) {
		const int side = _side, direct = _direct;
		const int rotateRule[2][4] = { {0,1,2,3}, {2,1,0,3} };
		int tempCube[3];

		for (int i = 0; i < 3; i++) {
			tempCube[i] = cube[rotateRule[direct][0]][i][side];
		}
		for (int i = 0; i < 3; i++) {
			cube[rotateRule[direct][0]][i][side] = cube[rotateRule[direct][1]][i][side];
		}
		for (int i = 0; i < 3; i++) {
			cube[rotateRule[direct][1]][i][side] = cube[rotateRule[direct][2]][i][side];
		}
		for (int i = 0; i < 3; i++) {
			cube[rotateRule[direct][2]][i][side] = cube[rotateRule[direct][3]][2 - i][side ^ 2];
		}
		for (int i = 0; i < 3; i++) {
			cube[rotateRule[direct][3]][2 - i][side ^ 2] = tempCube[i];
		}
	}

	void printEntireCude() {
		for (int k = 0; k < 6; k++) {
			printFace(k);
		}
	}

	void printFace(int _face = 0) {
		const char cudeColor[6] = { 'w', 'r', 'y', 'o','g','b' };
		const int face = _face;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cudeColor[cube[face][i][j]] << " ";
			}
			cout << "\n";
		}
	}

private:
	int cube[6][3][3];
};


void TestCase() {
	int N;
	Cube cube;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c[2];
		cin >> c[0] >> c[1];
		cube.rotateCube(c[0], c[1]);
		//cube.printEntireCude();
		//cube.printFace(0);
	}
	cube.printFace(0);
}

void MySolution() {
	int Test;
	cin >> Test;
	for (int t = 0; t < Test; t++){
		TestCase();
	}
}
