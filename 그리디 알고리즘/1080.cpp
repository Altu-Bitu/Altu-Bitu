#include <iostream>
#include <string>

using namespace std;

int A[51][51];
int B[51][51];

int main() {

    int N, M;
    cin >> N >> M;

    string s1, s2;
    for (int i = 0; i < N; i++) {
        cin >> s1;
        for (int j = 0; j < M; j++) {
            A[i][j] = s1[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> s2;
        for (int j = 0; j < M; j++) {
            B[i][j] = s2[j] - '0';
        }
    }

    int result = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (A[i][j] != B[i][j]) {
                for (int x = i; x <= i + 2; x++) {
                    for (int y = j; y <= j + 2; y++) {
                        A[x][y] = 1 - A[x][y];
                    }
                }
                result += 1;
            }
            else {
                continue;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                cout << "-1" << "\n";
                return -1;
            }
        }
    }

    cout << result;

    return 0;
}
