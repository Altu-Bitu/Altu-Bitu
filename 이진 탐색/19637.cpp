/* 참고 :
 * https://dbstndi6316.tistory.com/33
 * https://psychoria.tistory.com/709
 * */

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

string name[100000];
int ability[100000];
int str_cnt1 = 0;
int str_cnt2 = 0;
int N, M;   // N : 칭호의 개수, M : 캐릭터의 개수

int binarySearch(int target) {
    int left = 0, right = N-1, mid = 0;
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        mid = (left + right) / 2; //중간값
        if (ability[mid] >= target) //target을 찾음
            right = mid-1;
        else //중간값이 target보다 작다면 target은 오른쪽에 있음
            left = mid+1;
    }
    if(target>ability[mid]){
        return mid+1;
    }
    else{
        return mid;
    }
}

int main(){

    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> name[i] >> ability[i];
    }

    /*
    for(int n=0;n<N;n++){
        cout << name[n] << " " << ability[n] << "\n";
    }
     */
    int power[100000] = {0,};
    for(int i=0;i<M;i++){
        cin >> power[i];
    }
    for(int i=0;i<M;i++){
        cout << name[binarySearch(power[i])] << "\n";
    }
/*
    vector<int> power;
    for(int i=0;i<M;i++){
        cin >> power[i];
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(power[i]<=ability[j]){
                cout << name[j] << "\n";
                break;
            }
        }
    }

    /*
    for(int n=0;n<N;n++){
        cout << name[n] << " " << ability[n] << "\n";
    }
     */

    return 0;
}
