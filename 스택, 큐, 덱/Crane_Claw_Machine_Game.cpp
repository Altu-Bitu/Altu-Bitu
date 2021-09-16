#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves){
    int answer = 0;
    stack<int> bag;

    for(int i=0;i<moves.size();i++){
        int row = moves[i] - 1;
        for(int j=0;j<board.size();j++){
            if (board[j][row] != 0){
                if(!bag.empty() && bag.top() == board[j][row]){
                    bag.pop();
                    answer += 2;
                }
                else
                    bag.push(board[j][row]);

                board[j][row] = 0;
                break;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> board = {
            {0,0,0,0,0},
            {0,0,1,0,3},
            {0,2,5,0,1},
            {4,2,4,4,2},
            {3,5,1,3,1}
    };
    vector<int> moves = {1,5,3,5,1,2,1,4};

    solution(board, moves);

    return 0;
}
