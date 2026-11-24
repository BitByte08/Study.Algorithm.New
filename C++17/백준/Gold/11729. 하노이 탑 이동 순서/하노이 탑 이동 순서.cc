#include <iostream>

using namespace std;

void hanoi(int n, int from, int via, int to) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    hanoi(n-1, from, to, via);
    cout << from << ' ' << to << '\n';
    hanoi(n-1, via, from, to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int count = 1;
    for (int i = 0; i < n; i++) count*=2;
    cout << count-1 << '\n';

    hanoi(n, 1, 2, 3);
}