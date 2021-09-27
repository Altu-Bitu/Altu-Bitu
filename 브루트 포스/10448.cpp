#include <iostream>

using namespace std;

bool flag;

int T, k, num[1001], idx, result[3];

void Result(int count) {
    if (flag)
        return;

    if (count == 3) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += num[result[i]];
        }

        if (sum == k)
            flag = true;
    }
    else {
        for (int i = 1; i <= idx; i++) {
            result[count] = i;
            Result(count + 1);
        }
    }
}

int main() {
    for (int i = 1; i <= 1000; i++) {
        num[i] = (i*(i + 1)) / 2;
        if (num[i] > 1000) {
            idx = i - 1;
            break;
        }
    }

    cin >> T;
    for (int t = 0; t < T; t++) {
        flag = false;
        cin >> k;
        Result(0);

        if (flag)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
