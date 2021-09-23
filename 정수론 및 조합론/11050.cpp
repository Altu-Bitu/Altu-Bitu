#include <iostream>

using namespace std;

int Combination(int N, int K){
    int numerator = 1;  // 분자
    int denominator = 1; // 분모

    for(int i=N;i>N-K;i--)
        numerator *= i;
    for(int i=1;i<=K;i++)
        denominator *= i;

    return numerator/denominator;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int N, K;
    cin >> N >> K;
    cout << Combination(N, K) << "\n";

    return 0;
}
