#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cp_str(string A, string B){
    int size_A = A.size();
    int size_B = B.size();
    if (size_A != size_B){
        return size_A < size_B;
    }

    int sum_A = 0;
    int sum_B = 0;
    for (int i=0; i < size_A; i++){
        if ('0' <= A[i] && A[i] <= '9')
            sum_A += A[i] - '0';
        if ('0' <= B[i] && B[i] <= '9')
            sum_B += B[i] - '0';
    }
    if (sum_A != sum_B)
        return sum_A < sum_B;

    return A < B;
}

int main(void){
    int N;
    cin >> N;
    string str[1000];
    for(int i=0;i<N;i++){
        cin >> str[i];
    }
    sort(str, str+N, cp_str);

    // 출력
    for(int i=0;i<N;i++){
        cout << str[i] << "\n";
    }

    return 0;
}
