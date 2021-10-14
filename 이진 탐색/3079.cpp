#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1e9+1
long long N, M;
long long *T = (long long*)(malloc(sizeof(long long)*MAX));   // 잉? 왜 빨간 줄이 그어지지...?
// 참고 : https://m.blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=tipsware&logNo=221325651422&categoryNo=50&proxyReferer=
int main(){
    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> T[i];
    }
    sort(T, T+N);

    long long lowerBound = 0;
    long long upperBound = T[N-1] * M;
    long long mid = 0;
    long long sum;
    long long answer = 0;

    while(lowerBound<=upperBound){
        sum = 0;
        mid = (lowerBound+upperBound)/2;
        for(int i=0;i<N;i++){
            sum += mid / T[i];
        }
        if(sum >= M){
            answer = min(mid, answer);
            upperBound = mid -1;
        }
        else{
            lowerBound = mid +1;
        }
    }

    cout << answer;
    return 0;
}
