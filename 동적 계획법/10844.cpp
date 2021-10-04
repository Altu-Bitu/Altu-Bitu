#include <iostream>
 
#define MAX 101
#define Moduler 1000000000

using namespace std;
 
int N;
long long Answer;
long long DP[MAX][11];
 
void Solution()
{
    for (int i = 1; i <= 9; i++)
    {
        DP[1][i] = 1;
    }
    DP[1][0] = 0;
 
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0) DP[i][j] = DP[i - 1][j + 1] % Moduler;
            else if (j == 9) DP[i][j] = DP[i - 1][j - 1] % Moduler;
            else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % Moduler;
        }
    }
 
    for (int i = 0; i < 10; i++)
    {
        Answer = Answer + DP[N][i];
    }
    cout << Answer % 1000000000 << "\n";
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> N;
  
    Solution();
 
    return 0;
}
