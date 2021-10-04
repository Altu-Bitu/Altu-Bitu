#include <iostream>

#define MAX 1001

using namespace std;

int N, Answer;
int MAP[MAX][3];
int DP[MAX][3];

int Min(int A, int B) = (A < B) ? A : B;

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        DP[i][0] = Min(DP[i - 1][1], DP[i - 1][2]) + MAP[i][0];
        DP[i][1] = Min(DP[i - 1][0], DP[i - 1][2]) + MAP[i][1];
        DP[i][2] = Min(DP[i - 1][0], DP[i - 1][1]) + MAP[i][2];
    }
    Answer = Min(Min(DP[N][0], DP[N][1]), DP[N][2]);
    cout << Answer << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> MAP[i][j];
        }
    }
    DP[0][0] = DP[0][1] = DP[0][2] = 0;
    MAP[0][0] = MAP[0][1] = MAP[0][2] = 0;

    Solution();

    return 0;
}
