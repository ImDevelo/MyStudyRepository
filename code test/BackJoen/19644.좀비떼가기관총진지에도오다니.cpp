//좀비 떼가 기관총 진지에도 오다니
//https://www.acmicpc.net/problem/19644
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 



void MySolution() {
    long long L;
    long long ML, MK;
    int C;

    cin >> L;
    cin >> ML >> MK;
    cin >> C;

    long long damage = 0;
    long long shout_count = 0;
    long long zombie_hp = 0;
    for (int i = 0; i < L; i++) {
        //첫번쨰는 발사데미지로 잡을 수 있는가?
        cin >> zombie_hp;

        shout_count = min(shout_count + 1, ML);
        damage = shout_count * MK; //좀비에게 들어갈 기관총 데미지
        
        if (zombie_hp - damage <= 0) {
            //cout << "좀비:" << zombie_hp << " 에게 데미지 " << damage << "\n";
            continue;
        }

        if (C > 0) { // 최후의 보루 지뢰 사용!
            //cout << "지뢰사용\n";
            C--;
            shout_count = max((long long)0, shout_count - 2);
            continue;
        }

        cout << "No";
        return;
    }

    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}