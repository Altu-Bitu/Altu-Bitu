#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n, m;

    cin >> n >> m;

    vector<int> mileage(n);
    for(int i=0;i<n;i++){
        int p, l;
        cin >> p >> l;

        int m_list[p];

        for(int x =0;x<p;x++){
            scanf_s("%d %d",&m_list[x],&m_list[x+1]);
        }

        for(int x =0;x<p;x++){
            cout << m_list[x];
        }

        if(p<l)
            mileage.push_back(1);
        else {
            sort(m_list.rbegin(), m_list.rend());
            mileage.push_back(m_list[l - 1]);
        }
    }
    for(int i =0;i<n;i++){
        cout << mileage[i];
    }
    sort(mileage.begin(), mileage.end());
    cout << mileage[2];
//    for(int i =0;i<n;i++){
//        cout << mileage[i];
//    }

    int sum = 0;
    int answer = 0;
    for(int x=0;x<n;x++){
        sum += mileage[x];
        answer++;
    }
    cout << answer << "\n";

    return 0;
}
