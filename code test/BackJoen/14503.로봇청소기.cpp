//로봇 청소기
//https://www.acmicpc.net/problem/14503

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int r;
    int c;

    Node(int r, int c):r(r), c(c);
};

void bfd(const vector<vector<int>>& room, int start_r, int start_c){

    queue<Node> q;
    q.push(new Node())

}


void MySolution(){

    int R, C;
    int start_r, start_c, direct;

    vector<vector<int>> room (N, vector<int>(M,0));

    cin >> start_r >> start_c >> direct;



}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    MySolution();
}