#include <iostream>

using namespace std;

class Stack {
private:
    int* data;
    size_t size_;
public:
    Stack(const int size = 0): size_(size), data(new int[1000001]()) {}
    ~Stack() { delete[] data; }
    void push(const int& value) {
        data[size_++] = value;
    }
    void pop() {
        if (size_ > 0) {
            cout << data[--size_] << '\n';
            data[size_] = 0;
        } else {
            cout << -1 << '\n';
        }
    }
    void size() {
        cout << size_ << '\n';
    }
    void empty() {
        cout << !(size_ > 0) << '\n';
    }
    void top() {
        if (size_ > 0) {
            cout << data[size_ - 1] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    Stack s;
    for (int i = 0; i < n; i++) {
        int cmd; cin >> cmd;
        switch (cmd) {
            case 1:
                int param; cin >> param;
                s.push(param);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.size();
                break;
            case 4:
                s.empty();
                break;
            case 5:
                s.top();
                break;
        }
    }
    return 0;
}