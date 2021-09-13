#include <iostream>

using namespace std;

void no_consider(int W0, int I0, int D, int I, int A){
    for(int i=0;i<D;i++){
        W0 += (I - (I0 + A));
    }

    if (W0 <= 0 || I0 <=0)
        printf("Danger Diet \n");

    else
        printf("%d %d \n", W0, I0);
}

void consider(int W0, int I0, int T, int D, int I, int A){
    int I_change = I0;
    int W_change = W0;
    for(int i=0;i<D;i++){
        W_change += (I - (I_change + A));
        if (abs(I - (I_change + A)) > T){
            I_change += floor((I - (I_change + A))/2);
        }
    }


    if (W_change <= 0 || I_change <=0)
        printf("Danger Diet");
    else{
        printf("%d %d ", W_change, I_change);
        W0 = W_change;
        for(int i=0;i<D;i++){
            W0 += (I0 - (I_change + 0));
        }

        if (W0 > W_change){
            printf("YOYO");
        }
        else{
            printf("NO");
        }
    }
}


int main(){
    // 입력
    int W0, I0, T;
    cin >> W0 >> I0 >> T;
    int D, I, A;
    cin >> D >> I >> A;

    no_consider(W0, I0, D, I, A);
    consider(W0, I0, T, D, I, A);

    return 0;
}
