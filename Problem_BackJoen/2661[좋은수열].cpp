//좋은 수열
//https://www.acmicpc.net/problem/2661
#include<iostream>
#include<vector>
using namespace std;
vector<int> v;

int GoodSequence(int len) {
    bool s = true;
    for (int n = 1; n <= 3; n++) {
        if (v.at(len - 1) == n) {
            continue;
        }
        else{
            for (int i = 1; i <= (len / 2); i++) { //1,2,3 반복 이의 없음 고! 불만족시 continew
                if (true) {
                    for (int j = 0; j <= (len / 2); j++) { // i와 i-1 비교끝
                        if (v.at(len - j - 1) != v.at(len + i - j)) {
                            break;
                        }
                    }
                }
            }

            //불만 없이 전부 빠져나왔다면? 
            return n;
        }

    }
    return 1;
}

//조건 1

void MySolution() {
    int N;
    cin >> N;
    v.push_back(1);
    for (int len = 1; len < N; len++) {// 자리수
        v.push_back(GoodSequence(len));
    }

    //121

    //현제 i는 3
    //4기입 조건1 i-1과 같지 않다
    //조건2 길이3일때 (4가 될예정) //즉 홀수 일때
    //i-(x+2)번과 i-x번확인 같다면 i-(x+1)과 i는 같으면 안된다.

    //1213 4 2번
    //12131 :현제 길이 5(6이 될 예정) >> 반복횟수는 3번 
    //i는 5
    //i는 i-1과 같지 않다.
    // i-1과 i-3이 같다면 같으면 i-2와 i가 같으면 안된다.
    // i-2와 i-5와 비교 같다면 다음 i-1과 i-4비교 같다면 i는 i-3와 같으면 안된다.
    //i는 i-(x+2)번과 i-x번확인 같다면 i-(x+1)과 i는 같으면 안된다.

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}
