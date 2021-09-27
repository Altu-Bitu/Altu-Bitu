#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int coordinate[500001];
int cnt[8001];
int N, mean, median, mode, range;
int sum = 0;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> coordinate[i];
        sum += coordinate[i];
        cnt[coordinate[i]+4000]++;
    }

    sort(coordinate, coordinate+N);

    int flag;
    int max = 0;

    for (int i = 0; i < 8001; i++)
    {
        if (cnt[i] > max)
        {
            max = cnt[i];
            flag = i;
        }
    }

    for (int i = flag + 1; i < 8001; i++)
    {
        if (cnt[i] == max)
        {
            flag = i;
            break;
        }
    }

    mean = round(double(sum) / N);
    median = coordinate[(N - 1) / 2];
    mode = flag - 4000;
    range = coordinate[N - 1] - coordinate[0];

    cout << mean << "\n";
    cout << median << "\n";
    cout << mode << "\n";
    cout << range << "\n";

    return 0;
}
