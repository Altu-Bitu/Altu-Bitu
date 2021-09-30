#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
char check[10];
char a[20];
vector<string> result;

bool good(char x, char y, char op){
    if(x < y && op == '<')
        return true;
    if(x > y && op == '>')
        return true;
    return false;
}

void go(int idx, string num){
    if(idx == n + 1){
        result.push_back(num);
        return;
    }

    for(char i = 0; i <= 9; i++){
        if(check[i])
            continue;
        if(idx == 0 || good(num[idx - 1], i + '0', a[idx - 1])){
            check[i] = 1;
            go(idx + 1, num + to_string(i));
            check[i] = 0;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    go(0, "");
    sort(result.begin(), result.end());
    cout << result[result.size() - 1] << "\n" << result[0] << "\n";
}
