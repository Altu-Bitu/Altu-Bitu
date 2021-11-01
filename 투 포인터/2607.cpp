// https://www.acmicpc.net/problem/2607

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string word1;
    cin >> word1;

    int alpha[] = {0,};
    int i = 0, idx = 0;
    while(word1[i]){
        idx = word1[i] - 65;
        alpha[idx]++;
        i++;
    }

    int cnt = 0;

    for(int t = 0;t<n-1;t++){
        string word_cmp;
        cin >> word_cmp;
        int cmp[] = {0,};
        memcpy(cmp, alpha, sizeof(int)*26);
        int s = 0;

        for(int i=0;i<word_cmp.length();i++){
            idx = word_cmp[i] - 65;
            if(cmp[idx] > 0){
                s++;
                cmp[idx]--;
            }
        }

        if(word_cmp.length() - word1.length() == -1 && s - word_cmp.length() == 0){
            cnt++;
        }
        else if(word_cmp.length() - word1.length() == 0){
            if(s - word1.length() == -1 || s - word1.length() == 0){
                cnt++;
            }
        }
        else if(word_cmp.length() - word1.length() == 1){
            if(s - word1.length() == 0){
                cnt++;
            }
        }
    }
    cout << cnt;

    return 0;
}
