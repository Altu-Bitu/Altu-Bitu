#include <iostream>

using namespace std;

bool check(string str){
    bool alpha[26] = {0};

    for(int i=0;i<str.length();i++){
        if (alpha[str[i]-97]){
            return false;
        }
        else{
            char data = str[i];
            alpha[str[i]-97] = true;

            while(true){
                if(data != str[++i]){
                    i--;
                    break;
                }
            }
        }
    }

    return true;
}

int main() {
    // 입력 및 연산(check() 함수)
    int N;
    cin >> N;

    int count = 0;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;

        if (check(str)) {
            count++;
        }
    }

    //출력
    cout << count;

    return 0;
}
