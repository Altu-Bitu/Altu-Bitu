#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> inputs;
vector<int> answers;

void backTracking(int depth){
    if(depth == M){
        for(int i=0; i < answers.size(); i++){
            cout << answers[i];
        }
        cout << "\n";
        return ;
    }

    int mul = -1;
    for(int i=0; i < N; i++){
        if(mul == inputs[i])
            continue;
        mul = inputs[i];
        answers.push_back(inputs[i]);
        backTracking(depth + 1);
        answers.pop_back();
    }
    return ;
}

int main(){
    cin >> N >> M;
    int x;
    for(int i=0; i < N; i++){
        cin >> x;
        inputs.push_back(x);
    }
    sort(inputs.begin(), inputs.end());
    backTracking(0);
    return 0;
}
