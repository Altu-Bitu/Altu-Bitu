//
// Created by 관리자 on 2021-09-08.
//

#include <iostream>
#include <vector>

using namespace std;

// 배열
vector<int> arr;

// 버블 정렬 (일반)
// => '맨 뒤'(=가장 큰 것) 것들부터 정하고 본다
void bubbleSort(int N)  {
    int count = 0;

    for(int i = 0;i < N;i++){
        for(int j=1;j<N;j++){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1], arr[j]);
            }
            count++;
        }
    }

    cout << "Count : " << count << "\n";
}

// 버블 정렬 (향상; Adv)
// +) 이미 잘 정렬되어있는 경우
void bubbleSortAdv(int N)   {
    int count = 0;

    // 추가된 부분
    bool flag = true;

    for(int i = 0;i < N;i++){
        for(int j=1;j<N;j++){
            if(arr[j-1]>arr[j]){
                // 추가된 부분
                flag = false;
                swap(arr[j-1], arr[j]);
            }
            count++;
        }

        // 추가된 부분
        if(flag){
            break;
        }
    }

    cout << "Count : " << count << "\n";
}

int main(void){
    int N;

    //입력
    cin >> N;
    arr.assign(N, 0);
    for(int i = 0;i<N;i++){
        cin >> arr[i];
    }

    // 연산
    //bubbleSort(N);
    bubbleSortAdv(N);

    // 출력
    for(int i=0;i<N;i++){
        cout << arr[i] << "\n";
    }

    return 0;
}
