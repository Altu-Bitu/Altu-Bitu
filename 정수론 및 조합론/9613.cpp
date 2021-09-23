#include <iostream>

using namespace std;

int arr[100];

int GCD(int a, int b){
    if(a%b==0)
        return b;

    return GCD(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int n;
        cin >> n;

        for(int j=0;j<n;j++)
            cin >> arr[j];

        long long sum = 0;
        for(int w=0;w<n-1;w++){
            for(int x=w+1;x<n;x++)
                sum += GCD(arr[w], arr[x]);
        }

        cout << sum << "\n";
    }

    return 0;
}
