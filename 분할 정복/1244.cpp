/*
 * 스위치의 상태 : 켜짐/꺼짐
 * 학생의 성별 : 남/여
 * 답 : 스위치들의 마지막 상태
 * */

#include <iostream>

using namespace std;

int N;  // 0 < N <= 100
int condition[101] = {0, };
int studentNum;    // 0<student<=100
int students[101][2];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> condition[i+1];
    }
    cin >> studentNum;
    for(int i=0;i<studentNum;i++){
        for(int j=0;j<2;j++){
            cin >> students[i][j];
        }
    }

    for(int i;i<studentNum;i++){
        if(students[i][0] == 1){    // 남자
            for(int j=1;j*students[i][1]<=N;j++){
                condition[j*students[i][1]] = (condition[j*students[i][1]]+1)%2;
            }
        }
        else{   // 여자
            int low = students[i][1]-1;
            int high = students[i][1]+1;

            condition[students[i][1]] = (condition[students[i][1]]+1)%2;
            while(low>0||high<=N){
                if(low == high){
                    condition[low] = (condition[low]+1)%2;
                    condition[high] = (condition[high]+1)%2;
                    low--;
                    high--;
                }
                else{
                    break;
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        cout << condition[i];
    }

    return 0;
}
