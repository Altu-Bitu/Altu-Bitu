#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int time = 0;
    int data = 0;
    for(int i=0;i<N;i++){
        data += arr[i];
        time += data;
    }

    cout << time;

    return 0;
}
