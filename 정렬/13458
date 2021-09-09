#include <iostream>

using namespace std;

int N;
int A[1000000];
int B, C;

long long minSV(void){
    long long result = 0;

    for(int i=0;i<N;i++){
        A[i] -= B;
        result++;

        if(A[i]>0){
            if (A[i] % C == 0){
                result += A[i] / C;
            }
            else{
                result += A[i] / C + 1;
            }
        }
    }

    return result;
}

int main(void){
    // 입력
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    cin >> B >> C;

    // 출력
    cout << minSV();

    return 0;
}
