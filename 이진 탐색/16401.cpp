#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> snacks;
    int x;
    for(int i=0;i<N;i++){
        cin >> x;
        snacks.push_back(x);
    }

    while(1){
        sort(snacks.begin(), snacks.end());
        if(M<=N){
            cout << snacks[N-M];
            return 0;
        }
        else{
            //cout << snacks[N-1];
            int d = snacks[N-1] / 2;
            snacks.erase(snacks.begin()+(N-1));
            snacks.insert(snacks.begin()+(N-1),d);
            snacks.insert(snacks.begin()+(N-1),d);
            N++;
        }
    }

    /*
    for(int i=0;i<N;i++){
        cout << snacks[i];
    }
     */
}
