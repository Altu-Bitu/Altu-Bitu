#include<iostream>

using namespace std;

int red, brown;
int roomArea;
bool flag = false;

void Paint(int L, int W) {
    int R = 0;
    int B = 0;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < L; j++) {
            if (i == 0 || j == 0 || i == W - 1 || j == L - 1)
                R++;
            else
                B++;
        }
    }

    if (R == red && B == brown) {
        flag = true;
        return;
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> red >> brown;
    roomArea = red + brown;

    int len = 1;
    while (1){
        if (roomArea % len == 0) {
            int Tmp_L = len;
            int Tmp_W = roomArea / len;
            Paint(Tmp_L, Tmp_W);

            if (flag == true) {
                cout << Tmp_W << " " << Tmp_L << endl;
                break;
            }
        }
        len++;
    }

    return 0;
}
