#include <iostream>
#include <algorithm>

using namespace std;

int testcase[20];
int T, N;
pair<int, int> score[100000];

int main(void){
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> N;
        for(int j=0;j<N;j++){
            cin >> score[j].first >> score[j].second;
        }

        sort(score, score+N);

        int max = score[0].second;
        int count = 0;
        for(int i=0;i<N;i++){
            if(score[i].second <= max){
                count++;
                max = score[i].second;
            }
        }

        testcase[i] = count;
    }

    for(int i=0;i<T;i++){
        cout << testcase[i] << "\n";
    }

    return 0;
}
