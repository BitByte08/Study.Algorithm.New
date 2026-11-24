#include <cstdint>
#include <iostream>

using namespace std;

class int128 {
private:
    int *arr;
    void upper(int size = 128) {
        for (int i = 0; i < size - 1; i++) {
            arr[i+1] += arr[i]/10;
            arr[i] %= 10;
        }
    }
public:
    int128() {
        arr = new int[128]();
    }
    int128(int num) {
        arr = new int[128]();
        arr[0] = num;
        upper(num/10);
    }
    ~int128() {
        delete[] arr;
    }
    void multi_two(){
        for (int i = 0; i < 128; i++) {
            this->arr[i] *= 2;
        }
        upper();
    }
    void print() {
        bool start = false;
        for (int i = 127; i > 0; i--) {
            if (!start && !arr[i]) continue;
            cout << arr[i];
            start = true;
        }
        cout << arr[0] - 1;
    }
};

void hanoi(int n, int from, int via, int to) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    hanoi(n-1, from, to, via);
    cout << from << ' ' << to << '\n';
    hanoi(n-1, via, from, to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n > 20) {
        int128 num = 1;
        for (int i = 0; i < n; i++) num.multi_two();
        num.print();
    } else {
        uint64_t count = 1;
        for (int i = 0; i < n; i++) count*=2;
        cout << count-1 << '\n';
        hanoi(n, 1, 2, 3);
    }

    return 0;
}