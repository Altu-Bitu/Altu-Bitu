#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N, number, strike, ball;
    bool arr[1000];
    string tmp, one, two;
    int count_s, count_b, result;

    cin >> N;

    memset(arr, true, sizeof(arr));

    for(int i=123;i<=999;i++){
        tmp = to_string(i);
        if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
            arr[i] = false;
        if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0)
            arr[i] = false;
    }

    for (int i = 1; i <= N; i++) {
        cin >> number >> strike >> ball;
        for (int j = 123; j <= 999; j++) {
            count_s = 0;
            count_b = 0;

            if (arr[j]) {
                one = to_string(number);
                two = to_string(j);
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (x == y && one[x]==two[y])
                            count_s ++;
                        if (x != y && one[x] == two[y])
                            count_b++;
                    }
                }

                if (count_s != strike || count_b != ball)
                    arr[j] = false;
            }
        }
    }

    for (int i = 123; i <= 999; i++) {
        if (arr[i])
            result++;
    }

    cout << result << endl;

    return 0;
}
