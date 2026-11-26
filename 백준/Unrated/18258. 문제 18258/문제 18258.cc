#include <iostream>

// push X: 정수 X를 큐에 넣는 연산이다.
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 큐에 들어있는 정수의 개수를 출력한다.
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

using namespace std;

class Queue {
private:
    int* data_;
    int front_;
    int back_;
public:
    Queue() : data_(new int[2000001]()), front_(0), back_(0) {}
    ~Queue() { delete[] data_; }
    void push(int x) {
        data_[back_++] = x;
    }
    void pop() {
        if (back_-front_ > 0) {
            cout << data_[front_] << '\n';
            data_[front_++] = 0;
        } else {
            cout << -1 << '\n';
        }
    }
    void size() {
        cout << back_-front_ << '\n';
    }
    void empty() {
        cout << (back_-front_ == 0) << '\n';
    }
    void front() {
        if (back_-front_ == 0) {
            cout << -1 << '\n';
        } else {
            cout << data_[front_] << '\n';
        }
    }
    void back() {
        if (back_-front_ == 0) {
            cout << -1 << '\n';
        } else {
            cout << data_[back_-1] << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    Queue q;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "push") {
            int x; cin >> x;
            q.push(x);
        }
        else if (s == "pop") {
            q.pop();
        }
        else if (s == "front") {
            q.front();
        }
        else if (s == "back") {
            q.back();
        }
        else if (s == "empty") {
            q.empty();
        }
        else if (s == "size") {
            q.size();
        }
    }
    return 0;
}