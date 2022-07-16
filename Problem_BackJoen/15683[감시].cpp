//감시
//https://www.acmicpc.net/problem/15683
// 1. class 형식의 객체화
// 2. 겹치는 영역이 있다면 bool 로 영역 체크
// 3. 테스트 범위가 좁을땐 '조합' 의심하기

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 8

int R, C;
int area = 0, cctv_count;
int arr[MAX][MAX];
int best_area;

class CCTV {
public:
    int r, c;
    int model; // 모델 번호 1~5
    int model_type; //현 도델의 감시 타입 번호
    int model_type_count[5] = { 4,2,4,4,1 }; //모델에 따른 타입의 총 갯수;
    CCTV() {}

    void setting(int _r, int _c, int _m) {
        r = _r; c = _c; model = _m - 1;
    }

    int getModelTypeCount() {
        return model_type_count[model];
    }

    void surveillance(bool srv[][MAX]) {
        switch (model){
        case 0:
            switch (model_type){
            case 0: Up(srv); break;
            case 1: Down(srv); break;
            case 2: Left(srv); break;
            case 3: Right(srv); break;
            }
            break;
        case 1:
            switch (model_type) {
            case 0: Up(srv); Down(srv); break;
            case 1: Left(srv); Right(srv); break;
            }
            break;
        case 2:
            switch (model_type) {
            case 0: Up(srv);  Left(srv); break;
            case 1: Left(srv); Down(srv); break;
            case 2: Down(srv); Right(srv); break;
            case 3: Right(srv); Up(srv); break;
            }
            break;
        case 3:
            switch (model_type) {
            case 0: Up(srv);  Left(srv); Down(srv); break;
            case 1: Left(srv); Down(srv); Right(srv); break;
            case 2: Down(srv); Right(srv); Up(srv); break;
            case 3: Right(srv); Up(srv); Left(srv); break;
            }
            break;
        case 4:
            Up(srv); Down(srv); Right(srv); Left(srv);
        }
    }

    void Left(bool srv[][MAX]) {
        for (int i = c; i >= 0 && arr[r][i] != 6; i--) {
            srv[r][i] = true;
        }
    }
    void Right(bool srv[][MAX]) {
        for (int i = c; i < C && arr[r][i] != 6; i++) {
            if (arr[r][i] == 6) cout << "!";
            srv[r][i] = true;
        }
    }
    void Up(bool srv[][MAX]) {
        for (int i = r; i >= 0 && arr[i][c] != 6; i--) {
            srv[i][c] = true;
        }
    }
    void Down(bool srv[][MAX]) {
        for (int i = r; i < R && arr[i][c] != 6; i++) {
            srv[i][c] = true;
        }
    }
};
CCTV cctv[MAX];

int surveillanceArea(){
    int srv_area = area;
    bool srv[MAX][MAX] = {false};

    for (int i = 0; i < cctv_count; i++) {
        cctv[i].surveillance(srv);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (srv[i][j] == true) {
                srv_area--;
            }
        }
    }
    srv_area += cctv_count;
    return srv_area;
}

void caseOfSurveillance(int count) {
    if (count == cctv_count) {
        best_area = min(surveillanceArea(), best_area);
        return;
    }
    for (int i = 0; i < cctv[count].getModelTypeCount(); i++) {
        cctv[count].model_type = i;
        caseOfSurveillance(count + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> R >> C;
    int index = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0, t; j < C; j++) {
            cin >> t;
            arr[i][j] = t;
            if (t > 0 && t < 6) {
                cctv[index++].setting(i,j,t);
            }
            else if (t == 0) {
                area++;
            }
        }
    }
    cctv_count = index;
    best_area = area;
    caseOfSurveillance(0);
    cout << best_area;
}