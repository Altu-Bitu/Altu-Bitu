#include <iostream>

using namespace std;

int N, K;
int cnt[100005];
int a[200005];

int main() {
    cin.tie(nullptr); 
    ios::sync_with_stdio(false);
  
    cin >> N >> K;
    for(int i=1;i<=N;++i) cin >> a[i];
    int s = 1, e = 1;
    int ans = 0;
    while(e <= N && s <= e) {
        while(e <= N && cnt[a[e]] <= K) {
            if(cnt[a[e]] == K) 
                break;
            cnt[a[e]]++;
            ans = max(ans, e-s+1);
            ++e;
        }
        while(s < e) {
            if(cnt[a[s]] == K) {
                --cnt[a[s++]];
                break;
            }
            --cnt[a[s++]];
        }
    }
    cout << ans << '\n';
    return 0;
}
