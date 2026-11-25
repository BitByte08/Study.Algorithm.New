#include <iostream>
#include <stack>

using namespace std;

int main() {
    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break;

        stack<char> st;
        for (char c : s) {
            if (c == '[' || c == '(') {
                st.push(c);
            }
            else if (c == ')' || c == ']') {
                if (st.empty()) {
                    st.push(c);
                    break;
                }
                if ((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']')) {
                    st.pop();
                } else {
                    st.push(c);
                    break;
                }
            }
        }
        cout << (st.empty() ? "yes" : "no") << endl;
    }
}