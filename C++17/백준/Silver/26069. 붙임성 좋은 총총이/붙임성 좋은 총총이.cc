#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> s;
    int n; cin >> n;

    s.insert("ChongChong");

    for (int i = 0; i < n; i++) {
        string p1, p2; cin >> p1 >> p2;
        if (s.find(p1) != s.end()) {
            s.insert(p2);
        }
        if (s.find(p2) != s.end()) {
            s.insert(p1);
        }
    }

    cout << s.size();
    
    return 0;
}