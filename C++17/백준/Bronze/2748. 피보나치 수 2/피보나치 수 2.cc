#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n; cin >> n;
    vector<long> v = {0, 1, 1};
    
    for (int i = 3; i <= n; i++) {
        v.push_back(v[i-1] + v[i-2]);
    }
    
    cout << v.back();
    return 0;
}