#include <iostream>

using namespace std;

#define CMax 100001

long long dis[CMax];
long long price[CMax];

int main(){
    int N;
    long long ans = 0;
    long long minCost;

    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        cin >> dis[i];
    }
    for(int i=0;i<N;i++){
        cin >> price[i];
    }

    ans += dis[0]*price[0];
    minCost = price[0];

    for(int i =1;i<N-1;i++){
        if(price[i] > minCost){
            ans += dis[i]*minCost;
        }
        else{
            minCost = price[i];
            ans += dis[i]*minCost;
        }
    }

    cout << ans << "\n";

    return 0;
}
