#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<string, int> map;

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s.size() < m) continue;
        map[s]++;
    }

    vector<pair<string, int>> v(map.begin(), map.end());
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second) {
            if (a.first.size() == b.first.size()) {
                return a.first < b.first;
            }
            return a.first.size() > b.first.size();
        }
        return a.second > b.second;
    });

    for (auto i: v) {
        cout << i.first << '\n';
    }
    return 0;
}