#include <iostream>
#include <vector>

using namespace std;

int solution(int* x, int* y, int* d, int* g) {
    vector<int> r_angle;
}

int main() {
    vector<vector<int>> direction = {{1, 0},    // 0 : →
                                     {0, -1},   // 1 : ↑
                                     {-1, 0},   // 2 : ←
                                     {0, 1}};   // 3 : ↓
    int N;
    cin >> N;

    while(N>0) {
        int x, y, d, g; // 시작점, 시작 방향, 세대
        cin >> x >> y >> d >> g;

        solution(&x, &y, &d, &g);
        N--;
    }

    int result;
    cout << result << "\n";
    return 0;
}
