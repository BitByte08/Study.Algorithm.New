#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, result = 0; cin >> n;
    set<string> set;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "ENTER") {
            set.clear();
            continue;
        }
        if (set.find(s) == set.end()) {
            set.insert(s);
            result++;
        }
    }

    cout << result;
    return 0;
}