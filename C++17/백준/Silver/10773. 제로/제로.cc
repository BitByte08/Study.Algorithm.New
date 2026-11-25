#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n; cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) s.push(x);
        else s.pop();
    }
    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}