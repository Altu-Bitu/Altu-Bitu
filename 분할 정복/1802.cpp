#include <iostream>
#include <string>

using namespace std;

int T;
char info[1001][3000];


string result(char st[]){
    if(strlen(st) == 1)
        return "Yes";
    else{
        int mid = strlen(st)/2;
        return "No";
    }
}

int main(){
    cin >> T;

    // 0 = in, 1 = out
    for(int i=0;i<T;i++){
        cin >> info[i];
        cout << result(info[i]);
    }
    return 0;
}
