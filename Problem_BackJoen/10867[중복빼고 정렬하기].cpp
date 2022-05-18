// 중복빼고 정렬하기
// https://www.acmicpc.net/problem/10867
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 100000
int N;
int arr[MAX];

void MySolution(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(&arr[0],&arr[N]);

    cout << arr[0] << " ";
    for(int i=1; i<N; i++){
        if(arr[i] != arr[i-1] ){
            cout << arr[i] << " ";
        }
        
    }

}

void AtherSolution()
{
	int n;
	vector<int> v;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end()); //동일 삭제

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MySolution();
    AtherSolution();
}