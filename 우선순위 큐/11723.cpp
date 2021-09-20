#include <iostream>
#include <string>

using namespace std;

bool S[20] = {0,};

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie();
    cout.tie();

    int M;
    cin >> M;

    string str;
    int x;

    while(M--){
        cin >> str >> x;

        if (str == "add")
            S[x] = true;
        else if (str == "remove")
            S[x] = false;
        else if (str == "check")
            S[x] ? (puts("1")) : (puts("0"));
        else if (str == "toggle")
            S[x] ? (S[x] = false) : (S[x] = true);
        else if (str == "all")
            memset(S, true, sizeof(S));
        else
            memset(S, false, sizeof(S));
    }

    return 0;
}
