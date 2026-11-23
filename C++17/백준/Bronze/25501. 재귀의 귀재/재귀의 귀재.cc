#include <iostream>
#include <string>

using namespace std;

pair<bool, int> recursion(string s, size_t left, size_t right, int count = 0) {
    count++;
    if (left >= right) return {true, count};
    else if (s[left] != s[right]) return {false, count};
    else {
        return recursion(s, left + 1, right - 1, count);
    }
}

pair<bool, int> isPalindrome(string s) {
    return recursion(s, 0, s.length() - 1);
}

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        auto result = isPalindrome(s);
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}