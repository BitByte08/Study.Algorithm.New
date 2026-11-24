#include <iostream>
#include <vector>

using namespace std;

void solver(vector<vector<char>> &result, int n, int start = 0, int end = 0) {
    int sqrt = n/3;
    for (int i = sqrt; i < sqrt*2; i++) {
        for (int j = sqrt; j < sqrt*2; j++) {
            result[i+start][j+end] = ' ';
        }
    }
    if (n / 3 == 1) return;

    solver(result, sqrt, start, end);
    solver(result, sqrt, start, end + sqrt);
    solver(result, sqrt, start, end + sqrt*2);
    solver(result, sqrt, start + sqrt, end);
    solver(result, sqrt, start + sqrt*2, end);
    solver(result, sqrt, start + sqrt, end + sqrt);
    solver(result, sqrt, start + sqrt, end + sqrt*2);
    solver(result, sqrt, start + sqrt*2, end + sqrt);
    solver(result, sqrt, start + sqrt*2, end + sqrt*2);
}

int main() {
    int n; cin >> n;
    vector<vector<char>> result(n, vector<char>(n, '*'));

    solver(result, n);

    for (auto i : result) {
        for (auto j : i) {
            cout << j;
        }
        cout << '\n';
    }
    return 0;
}
