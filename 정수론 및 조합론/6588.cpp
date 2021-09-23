#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int min[MAX];

vector<int> prime;

//에라토스테네스의 체
void eratosthenes(void){
    min[0] = min[1] = -1;
    for (int i = 2; i < MAX; i++)
        min[i] = i;
    
    for (int i = 2; i*i < MAX; i++){
        if (min[i] == i){
            for (int j = i * i; j < MAX; j += i)
                if (min[j] == j)
                    min[j] = i;
        }
    }

    for (int i = 3; i < MAX; i++)
        if (min[i] == i)
            prime.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    eratosthenes();
    
    while(1){
        int N;
        cin >> N;
        
        if (N == 0)
            break;
        
        for(int i=0; i<prime.size(); i++) {
            if (min[N - prime[i]] == N - prime[i]) {
                cout << N << " = " << prime[i] << " + " << N - prime[i] << "\n";
                break;
            }
        }
    }

    return 0;
}
