#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    stack<int> via;
    stack<int> to;

    to.push(0);

    for (auto i : v) {
        if (to.top()+1 == i) {
            to.push(i);
        } else if (via.empty() || via.top() > i) {
            via.push(i);
        } else {
            cout << "Sad";
            return 0;
        }
        while (!via.empty()) {
            if (to.top()+1 == via.top()) {
                to.push(via.top());
                via.pop();
            } else {
                break;
            }
        }
    }
    cout << "Nice";
    return 0;
}