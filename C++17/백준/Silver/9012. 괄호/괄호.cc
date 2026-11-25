#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        stack<char> st;
        string s; cin >> s;
        for (auto c : s) {
            if (c == '(') st.push('(');
            else if (c == ')' && !st.empty()) st.pop();
            else {
                st.push(c);
                break;
            }
        }
        cout << (st.empty() ? "YES" : "NO") << '\n';
    }
    return 0;
}