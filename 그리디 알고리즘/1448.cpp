#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N;
    int sides[1000001];

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> sides[i];
    }

    sort(sides, sides+N, greater<>());

    int total;
    for(int i=0;i<N-2;i++){
        total =0;
        if(sides[i+1] + sides[i+2] > sides[i]){
            total = sides[i] + sides[i+1] + sides[i+2];
            break;
        }
        else{
            total = -1;
        }
    }
    cout << total << "\n";
    return 0;
}
