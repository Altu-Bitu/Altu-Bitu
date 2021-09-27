#include <deque>
#include <iostream>

using namespace std;

deque<int> durability;
deque<bool> conveyor;

int N, K, step;

void rotate()
{
    conveyor.push_front(conveyor.back());
    conveyor.pop_back();

    durability.push_front(durability.back());
    durability.pop_back();
    conveyor[N - 1] = false;
}

void move()
{
    for (int i = N - 2; i >= 0; i--) {
        if ((!conveyor[i + 1]) && (durability[i + 1] > 0) && (conveyor[i])) {
            conveyor[i] = false;
            conveyor[i + 1] = true;
            durability[i + 1]--;
        }
    }
    conveyor[N - 1] = false;
}

void put_robot()
{
    if (!conveyor[0] && durability[0] > 0) {
        conveyor[0] = true;
        durability[0]--;
    }
}

int check()
{
    int count_ = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (durability[i] == 0)
            count_++;
    }
    return count_;
}

int main()
{
    step = 1;

    cin >> N >> K;
    for (int i = 0; i < 2 * N; i++) {
        int in;
        cin >> in;
        durability.push_back(in);
        conveyor.push_back(false);
    }

    while (true) {
        rotate();
        move();
        put_robot();

        int c = check();
        if (c >= K) {
            cout << step << "\n";
            return 0;
        }
        step++;
    }
}
