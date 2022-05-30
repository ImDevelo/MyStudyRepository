//치킨배달
//https://www.acmicpc.net/problem/15686
#include<iostream>
#include<utility>
#include<vector>
#include<math.h>
using namespace std;
#define MAX 50

class Home;
int N,M;
vector<pair<int,int>> shop;
vector<Home> h;
int list[14];
int citydistace;

class Home{
public:
    Home(int r, int c){
        point = {r,c};
    }

    void setDistace(const vector<pair<int,int>> p, int size){    
        int disX, disY;
        for(int i=0; i < size;i++){
            disX = abs(point.first - p[i].first);
            disY = abs(point.second - p[i].second);
            distance.push_back(disX + disY);
        }
    }
    int getCloserStore(int arr[]){
        int smaller = distance[arr[0]];
        for(int i=1; i<M;i++){
            if(distance[arr[i]] < smaller){
                smaller = distance[arr[i]];
            }
        }
        return smaller;
    }
private:
    pair<int,int> point;
    vector<int> distance;
};



void select(int count, int start, int end){
    if(count == M){
        //뽑아낸 치킨집을 기준으로 가장 최적의 도시치킨거리 계산
        int sum = 0;
        for(int i=0; i<h.size();i++){
            sum += h[i].getCloserStore(list);
        }
        if(sum < citydistace){
            citydistace = sum;
        }
    }else{
        for(int i=start; i<end;i++){
            list[count] = i;
            select(count + 1, i+1, end+1);
        }
    }
    return;
}

void MySolution(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0, input; j<N;j++){
            cin >> input;
            if(input == 2){
                shop.push_back({i,j});  
            }else if(input == 1){
                h.push_back(Home(i,j));        
            }
        }
    }

    for(int i=0; i<h.size(); i++){
        //i번째 집과 모든 치킨집과의 거리 저장
        h[i].setDistace(shop,shop.size());
    }
    // m개의 가게 조합 선택
    select(0, 0, M);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();

}