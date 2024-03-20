#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// N��N ũ���� ��
// r�� c�� 1���� ����
// �� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�.
// ������ ������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�.
// �ϳ��� ĭ�� ���� ���� ������ �ִٸ�, ���̰� � �������� ����� �Դ´�. 
// ���� ����� ������ �ڽ��� ���̸�ŭ ����� ���� �� ���� ������ ����� ���� ���ϰ� ��� �״´�.
// �������� ���� ���� ������ ������� ���ϰ� �ȴ�. ������ ���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�.
// �������� ������ �����Ѵ�. 
// �����ϴ� ������ ���̰� 5�� ����̾�� �ϸ�,
// ������ 8���� ĭ�� ���̰� 1�� ������ �����.
// �ܿ￡�� S2D2�� ���� ���ƴٴϸ鼭 ���� ����� �߰��Ѵ�. 
// �� ĭ�� �߰��Ǵ� ����� ���� A[r][c]

//ù° �ٿ� N, M, K
// x, y, z (x,y) z ����

// �� ���
// ���� ���ȭ
// ���� ����
// �ܿ� ��� �߰�

class Ground {
public:
    int nutrient;
    int breedingPossibleTreeCount;
    std::priority_queue<int, std::vector<int>, std::greater<int>> trees;       // ����ִ� ������ �����ϴ� �켱���� ť
    std::queue<int> deadTrees;            // ���� ������ �����ϴ� ť

    // �����ڸ� ���� nutrient�� 5�� �ʱ�ȭ
    Ground() : nutrient(5), breedingPossibleTreeCount(0) {

    }

    // ��(Spring) �޼���
    void spring() {
        std::priority_queue<int, std::vector<int>, std::greater<int>> newTrees;

        while (!trees.empty()) {
            int treeYear = trees.top();
            trees.pop();

            // ���� ������� ������ �ڶ� �� �ִ��� Ȯ��
            if (nutrient >= treeYear) {
                nutrient -= treeYear;  // ��� �Һ�
                treeYear++;            // ������ ���� ����
                if ((treeYear % 5) == 0) {
                    breedingPossibleTreeCount++;
                }
                newTrees.push(treeYear);  // ���ο� ������ ������ ť�� �߰�
            }
            else {
                // �ڶ� �� ���� ���, ��� ����
                deadTrees.push(treeYear);

            }
        }

        trees = newTrees;  // ���ο� ������ �������� ����
    }

    // ����(Summer) �޼���
    void summer() {

        while (!deadTrees.empty()) {
            int treeYear = deadTrees.front();
            deadTrees.pop();

            nutrient += treeYear / 2;  // ������ ������ ���ݸ�ŭ ������� ��ȯ�Ͽ� �߰�
        }
    }

    // ����(Autumn) �޼���
    void autumn(std::vector<std::vector<Ground>>& otherGround, int r, int c) {
        if (breedingPossibleTreeCount > 0) {
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0) continue;

                    int ni = i + r;  // �� �ε��� ��ȯ
                    int nj = j + c;  // �� �ε��� ��ȯ

                    if (ni == -1 || nj == -1 || ni == otherGround.size() || nj == otherGround.size()) continue;

                    for (int k = 0; k < breedingPossibleTreeCount; k++) {
                        otherGround[ni][nj].trees.push(1);
                    }
                }
            }
        }
        breedingPossibleTreeCount = 0;
    }

    // �ܿ�(Winter) �޼���
    void winter(int winterNutrient) {
        nutrient += winterNutrient;  // �ܿ￡�� ��� �߰�
    }

    // ����ִ� ������ ������ ���� �޼���
    int countLivingTrees() const {
        return trees.size();
    }

    // ���� ���� ������ ������ ����ϴ� �޼���
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

// ���� ����� ����ϴ� �Լ�
void printMatrix(const std::vector<std::vector<Ground>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& ground : row) {
            std::cout << ground.nutrient << " ";
        }
        std::cout << std::endl;
    }
}

// ���� �������� ����ϴ� �Լ�
void printTree(const std::vector<std::vector<Ground>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& ground : row) {
            std::cout << ground.countLivingTrees() << " ";
        }
        std::cout << std::endl;
    }
}

// ���� �������� ����ϴ� �Լ�
void printTreeYear(std::vector<std::vector<Ground>>& matrix) {
    for (auto& row : matrix) {
        for (auto& ground : row) {
            std::cout << ground.printHighestAgeTree() << " ";
        }
        std::cout << std::endl;
    }
}

void MySolution() {
    int N, M, K; // ���� ũ��, M���� ����, �⵵
    std::cin >> N >> M >> K;

    // Ground Ŭ������ �迭 ���� �� �ʱ�ȭ
    std::vector<std::vector<Ground>> matrix(N, std::vector<Ground>(N));
    std::vector<std::vector<int>> giveNutrient(N, std::vector<int>(N));

    // �� ������ �־��� ��� ����
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> giveNutrient[i][j];
        }
    }

    // ���� ����
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        matrix[x - 1][y - 1].trees.push(z);
    }

    // �� �⵵�� ���� �۾� ����
    for (int year = 1; year <= K; ++year) {
        //std::cout << year << "�⵵ ����" << std::endl;
        //std::cout << "��" << std::endl;
        // ��(Spring) �޼��� ȣ��
        for (auto& row : matrix) {
            for (auto& ground : row) {
                ground.spring();
            }
        }
        //printTree(matrix);
        //printTreeYear(matrix);
        //std::cout << "����" << std::endl;
        // ����(Summer) �޼��� ȣ��
        for (auto& row : matrix) {
            for (auto& ground : row) {
                ground.summer();
            }
        }
        //printTree(matrix);
        //std::cout << "����" << std::endl;
        // ����(Autumn) �޼��� ȣ��
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j].autumn(matrix, i, j);
            }
        }

        //std::cout << "�ܿ�" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j].winter(giveNutrient[i][j]);
            }
        }

        //std::cout << year << "�⵵ �� ���>" << std::endl;

        //printMatrix(matrix);
        //printTree(matrix);
        //printTreeYear(matrix);

    }

    // ���� ��� ���
    //std::cout << K << "�� " << " ���� ����:" << std::endl;
    //printMatrix(matrix);
    //printTree(matrix);

    // ��� �ִ� ������ �� ���� ���
    int totalLivingTrees = 0;
    for (const auto& row : matrix) {
        for (const auto& ground : row) {
            totalLivingTrees += ground.countLivingTrees();
        }
    }
    std::cout << totalLivingTrees;
}
