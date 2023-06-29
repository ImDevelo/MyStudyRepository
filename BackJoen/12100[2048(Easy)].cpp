//2048(Easy)
//https://www.acmicpc.net/problem/12100
#include<iostream>
#include<utility>
using namespace std;
#define MAX 20

int N;
int map[MAX][MAX][6];
int ans;

void pushNumber(int direct, int count) {
    if (direct == 0) {
        for (int i = 0; i < N; i++) {
            int start_check_number = 0;
            for (int j = 0; j < N; j++) {
                bool finded_number = false;
                int finded_push_number = 0;
                int result = 0;
                for (int n = start_check_number; n < N; n++) {
                    if (map[i][n][count] != 0) {
                        if (!finded_number) {
                            finded_number = true;
                            result = map[i][n][count];
                            finded_push_number = result;
                            start_check_number = min(n + 1, N);
                        }
                        else if (finded_number) {
                            if (map[i][n][count] == finded_push_number) {
                                result *= 2;
                                ans = max(result, ans);
                                start_check_number = min(n + 1, N);
                            }
                            break;
                        }
                    }
                }
                map[i][j][count + 1] = result;
            }
        }
    }
    if (direct == 1) {
        for (int i = 0; i < N; i++) {
            int start_check_number = N-1;
            for (int j = N-1; j >= 0; j--) {
                bool finded_number = false;
                int finded_push_number = 0;
                int result = 0;
                for (int n = start_check_number; n >= 0; n--) {
                    if (map[i][n][count] != 0) {
                        if (!finded_number) {
                            finded_number = true;
                            result = map[i][n][count];
                            finded_push_number = result;
                            start_check_number = max(n - 1, -1);
                        }
                        else if (finded_number) {
                            if (map[i][n][count] == finded_push_number) {
                                result *= 2;
                                ans = max(result, ans);
                                start_check_number = max(n - 1, -1);
                            }
                            break;
                        }
                    }
                }
                map[i][j][count + 1] = result;
            }
        }

    }
    if (direct == 2) {
        for (int i = 0; i < N; i++) {
            int start_check_number = 0;
            for (int j = 0; j < N; j++) {
                bool finded_number = false;
                int finded_push_number = 0;
                int result = 0;
                for (int n = start_check_number; n < N; n++) {
                    if (map[n][i][count] != 0) {
                        if (!finded_number) {
                            finded_number = true;
                            result = map[n][i][count];
                            finded_push_number = result;
                            start_check_number = min(n + 1, N);
                        }
                        else if (finded_number) {
                            if (map[n][i][count] == finded_push_number) {
                                result *= 2;
                                ans = max(result, ans);
                                start_check_number = min(n + 1, N);
                            }
                            break;
                        }
                    }
                }
                map[j][i][count + 1] = result;
            }
        }
    }
    if (direct == 3) {
        for (int i = 0; i < N; i++) {
            int start_check_number = N - 1;
            for (int j = N - 1; j >= 0; j--) {
                bool finded_number = false;
                int finded_push_number = 0;
                int result = 0;
                for (int n = start_check_number; n >= 0; n--) {
                    if (map[n][i][count] != 0) {
                        if (!finded_number) {
                            finded_number = true;
                            result = map[n][i][count];
                            finded_push_number = result;
                            start_check_number = max(n - 1, -1);
                        }
                        else if (finded_number) {
                            if (map[n][i][count] == finded_push_number) {
                                result *= 2;
                                ans = max(result, ans);
                                start_check_number = max(n - 1, -1);
                            }
                            break;
                        }
                    }
                }
                map[j][i][count + 1] = result;
            }
        }
    }
}

void MySolution(int count, int bestnumber) {
    if (count >= 5) {   
        return;
    }
    for (int i = 0; i < 4; i++) {
        pushNumber(i,count);
        MySolution(count + 1, bestnumber);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0, input_num; j < N; j++) {
            cin >> input_num;
            ans = max(ans, input_num);
            map[i][j][0] = input_num;
        }
    }
    MySolution(0,0);
    cout << ans;
}
