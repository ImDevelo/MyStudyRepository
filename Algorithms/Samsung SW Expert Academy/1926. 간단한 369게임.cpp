#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

	int N;

	cin >> N;

    for(int i=1; i<=N; i++){
        string str = to_string(i);
        int clip = 0;

        for(char c : str){
            if(c == '3' || c == '6' || c == '9'){
                clip += 1;
            }
        }
        if(clip == 0){
            cout << str << " ";
        }else{
            for(int p = 0; p < clip; p++){
                cout << "-";
            }
            cout << " ";
        }
    }


	return 0;
}