#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    vector<int> mode_count(8002, 0);
    int n; cin >> n;
    int mean = 0;
    int max = -4001;
    int min = 4001;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mean += x;
        v.push_back(x);
        max = std::max(x, max);
        min = std::min(x, min);
        mode_count[x+4000]++;
    }
    sort(v.begin(), v.end());
    cout << (int)round((double)mean/n) << '\n';
    cout << v[n/2] << '\n';

    vector<int> mode;
    int max_count = 0;
    for (int i = 0; i < mode_count.size(); i++) {
        if (max_count == mode_count[i]) {
            mode.push_back(i-4000);
        } else if (max_count > mode_count[i]) {
            continue;
        } else if (max_count < mode_count[i]) {
            max_count = mode_count[i];
            mode.clear();
            mode.push_back(i-4000);
        }
    }
    sort(mode.begin(), mode.end());
    if (mode.size() == 1) cout << mode[0] << '\n';
    else if (mode.size() >= 2) cout << mode[1] << '\n';
    cout << max - min;

    return 0;
}