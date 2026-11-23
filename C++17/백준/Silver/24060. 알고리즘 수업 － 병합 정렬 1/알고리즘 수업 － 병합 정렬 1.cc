#include <iostream>
#include <vector>

using namespace std;

vector<int> save;

void merge(vector<int> &a, int left, int mid, int right) {
    int i = left, j = mid + 1, t = 0;
    vector<int> tmp(right - left + 1);
    while (i <= mid && j <= right) {
        if (a[i] < a[j]) {
            tmp[t++] = a[i++];
        } else {
            tmp[t++] = a[j++];
        }
    }
    while (i <= mid) {
        tmp[t++] = a[i++];
    }
    while (j <= right) {
        tmp[t++] = a[j++];
    }
    for (i = left, t = 0; i <= right; i++, t++) {
        save.push_back(tmp[t]);
        a[i] = tmp[t];
    }
}

void merge_sort(vector<int> &a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    vector<int> a;
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    merge_sort(a, 0, a.size() - 1);

    if (k > save.size()) cout << -1;
    else cout << save[k - 1];

    return 0;
}