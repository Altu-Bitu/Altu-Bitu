/*
 * N : 이닝의 횟수
 * 공격/수비
 * 이닝 종료 & 공격/수비 교체 조건 : 3 아웃
 * 타순 : 경기 시작 "전"에 정함 / 순서 절대 변경 X
 * 득점 : '공격' 선수가 '홈'에 도착
 * 0 -> 1루 -> 2루 -> 3루 -> 홈
 *
 * 선수 1~9번 -> 타순 정하기
 * 1번 선수 => 4번 타자
 * 가장 많은 득점을 하는 타순 & 그때의 득점
 * */


#include <iostream>

using namespace std;

#define MemberNum 9
int N;  // 이닝의 횟수
int outcomes[50][MemberNum];    // 각 선수가 각 이닝에서 얻는 결과
int order[MemberNum];   // 선수들의 타순
int totalScore = 0; // 답(최대 득점)
bool done[MemberNum] = {false, };
int out = 0;

int main() {

    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0; j < MemberNum; j++){
            cin >> outcomes[i][j];
        }
    }

    // '선수들의 타순' 정하기 (1번 선수는 이미 지정됨) (순서 변경 x)
    order[1-1] = 4;
    done[1-1] = true;


    // 게임 (종료 및 교체 조건 고려) (득점)
    while(N-- > 0){
        for(int j =0;j<MemberNum;j++){
            if(out>=3){
                N--;
                break;
            }
            else{
                // 아직 안 씀
            }
        }
    }


    return 0;
}
