#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// N×N 크기의 땅
// r과 c는 1부터 시작
// 장 처음에 양분은 모든 칸에 5만큼 들어있다.
// 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
// 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 
// 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
// 여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
// 가을에는 나무가 번식한다. 
// 번식하는 나무는 나이가 5의 배수이어야 하며,
// 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 
// 각 칸에 추가되는 양분의 양은 A[r][c]

//첫째 줄에 N, M, K
// x, y, z (x,y) z 나이

// 봄 양분
// 여름 양분화
// 가을 증식
// 겨울 양분 추가

class Ground {
public:
    int nutrient;
    int breedingPossibleTreeCount;
    std::priority_queue<int, std::vector<int>, std::greater<int>> trees;       // 살아있는 나무를 저장하는 우선순위 큐
    std::queue<int> deadTrees;            // 죽은 나무를 저장하는 큐

    // 생성자를 통해 nutrient를 5로 초기화
    Ground() : nutrient(5), breedingPossibleTreeCount(0) {

    }

    // 봄(Spring) 메서드
    void spring() {
        std::priority_queue<int, std::vector<int>, std::greater<int>> newTrees;

        while (!trees.empty()) {
            int treeYear = trees.top();
            trees.pop();

            // 현재 양분으로 나무가 자랄 수 있는지 확인
            if (nutrient >= treeYear) {
                nutrient -= treeYear;  // 양분 소비
                treeYear++;            // 나무의 나이 증가
                if ((treeYear % 5) == 0) {
                    breedingPossibleTreeCount++;
                }
                newTrees.push(treeYear);  // 새로운 나이의 나무를 큐에 추가
            }
            else {
                // 자랄 수 없는 경우, 즉시 죽음
                deadTrees.push(treeYear);

            }
        }

        trees = newTrees;  // 새로운 상태의 나무들을 저장
    }

    // 여름(Summer) 메서드
    void summer() {

        while (!deadTrees.empty()) {
            int treeYear = deadTrees.front();
            deadTrees.pop();

            nutrient += treeYear / 2;  // 나무의 나이의 절반만큼 양분으로 변환하여 추가
        }
    }

    // 가을(Autumn) 메서드
    void autumn(std::vector<std::vector<Ground>>& otherGround, int r, int c) {
        if (breedingPossibleTreeCount > 0) {
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0) continue;

                    int ni = i + r;  // 행 인덱스 변환
                    int nj = j + c;  // 열 인덱스 변환

                    if (ni == -1 || nj == -1 || ni == otherGround.size() || nj == otherGround.size()) continue;

                    for (int k = 0; k < breedingPossibleTreeCount; k++) {
                        otherGround[ni][nj].trees.push(1);
                    }
                }
            }
        }
        breedingPossibleTreeCount = 0;
    }

    // 겨울(Winter) 메서드
    void winter(int winterNutrient) {
        nutrient += winterNutrient;  // 겨울에는 양분 추가
    }

    // 살아있는 나무의 개수를 세는 메서드
    int countLivingTrees() const {
        return trees.size();
    }

    // 가장 높은 나이의 나무를 출력하는 메서드
    int printHighestAgeTree() {
        std::priority_queue<int, std::vector<int>, std::greater<int>> newTrees;
        int maxValue = 0;
        while (!trees.empty()) {
            int treeYear = trees.top();
            newTrees.push(treeYear);
            maxValue = treeYear;
            trees.pop();
        }

        trees = newTrees;
        return maxValue;
    }
};

// 땅의 양분을 출력하는 함수
void printMatrix(const std::vector<std::vector<Ground>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& ground : row) {
            std::cout << ground.nutrient << " ";
        }
        std::cout << std::endl;
    }
}

// 땅의 나무수를 출력하는 함수
void printTree(const std::vector<std::vector<Ground>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& ground : row) {
            std::cout << ground.countLivingTrees() << " ";
        }
        std::cout << std::endl;
    }
}

// 땅의 나무수를 출력하는 함수
void printTreeYear(std::vector<std::vector<Ground>>& matrix) {
    for (auto& row : matrix) {
        for (auto& ground : row) {
            std::cout << ground.printHighestAgeTree() << " ";
        }
        std::cout << std::endl;
    }
}

void MySolution() {
    int N, M, K; // 땅의 크기, M개의 나무, 년도
    std::cin >> N >> M >> K;

    // Ground 클래스의 배열 생성 및 초기화
    std::vector<std::vector<Ground>> matrix(N, std::vector<Ground>(N));
    std::vector<std::vector<int>> giveNutrient(N, std::vector<int>(N));

    // 각 지점에 주어진 양분 저장
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> giveNutrient[i][j];
        }
    }

    // 나무 저장
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        matrix[x - 1][y - 1].trees.push(z);
    }

    // 각 년도에 따라 작업 수행
    for (int year = 1; year <= K; ++year) {
        //std::cout << year << "년도 시작" << std::endl;
        //std::cout << "봄" << std::endl;
        // 봄(Spring) 메서드 호출
        for (auto& row : matrix) {
            for (auto& ground : row) {
                ground.spring();
            }
        }
        //printTree(matrix);
        //printTreeYear(matrix);
        //std::cout << "여름" << std::endl;
        // 여름(Summer) 메서드 호출
        for (auto& row : matrix) {
            for (auto& ground : row) {
                ground.summer();
            }
        }
        //printTree(matrix);
        //std::cout << "가을" << std::endl;
        // 가을(Autumn) 메서드 호출
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j].autumn(matrix, i, j);
            }
        }

        //std::cout << "겨울" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j].winter(giveNutrient[i][j]);
            }
        }

        //std::cout << year << "년도 끝 결과>" << std::endl;

        //printMatrix(matrix);
        //printTree(matrix);
        //printTreeYear(matrix);

    }

    // 최종 결과 출력
    //std::cout << K << "년 " << " 후의 상태:" << std::endl;
    //printMatrix(matrix);
    //printTree(matrix);

    // 살아 있는 나무의 총 개수 출력
    int totalLivingTrees = 0;
    for (const auto& row : matrix) {
        for (const auto& ground : row) {
            totalLivingTrees += ground.countLivingTrees();
        }
    }
    std::cout << totalLivingTrees;
}
