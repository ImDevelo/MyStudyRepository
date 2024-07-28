#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string str;
        cin >> str;

        string year = str.substr(0,4);
        string mouth = str.substr(4,2);
        string days = str.substr(6,2);

        int mouth_num = stoi(mouth);
        int day_num = stoi(days);

        bool currect = false;

        switch (mouth_num)
        {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day_num > 0 && day_num <= 31) currect = true;
            break;
        case 4: case 6: case 9: case 11:
            if(day_num > 0 && day_num <= 30) currect = true;
            break;
        case 2:
            if( day_num > 0 && day_num <= 28) currect = true;
        default:
            break;
        }

        string result;

        if(currect){
            result = year + "/" + mouth + "/" + days;
        }else{
            result = "-1";
        }

        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}