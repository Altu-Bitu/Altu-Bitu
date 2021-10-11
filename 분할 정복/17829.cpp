#include <iostream>
#include <algorithm>

using namespace std;

int N;
int table[1024][1024];

int second(int a, int b){
    int num[1024];
    for(int i=a;i<a+2;i++){
        for(int j=b;j<b+2;j++){
            for(int x=0;x<i*j;x++){
                num[x] = table[i][j];
            }
        }
    }
    sort(num, num+1024);
    return num[1];
}

void square(){
    while(N>1){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                table[i/2][j/2] = second(i,j);
                j++;
            }
            i++;
        }
        N /=2;
    }

    cout << table[0][0] << "\n";
}

int main(){
    cin >> N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> table[i][j];
        }
    }

    square();

    return 0;
}
