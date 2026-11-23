#include <iostream>

using namespace std;

template <int N>
struct Square {
    static const int result = 3 * Square<N - 1>::result;
};

template <>
struct Square<1> {
    static const int result = 3;
};

int square_array[] = {
    1,
    Square<1>::result,
    Square<2>::result,
    Square<3>::result,
    Square<4>::result,
    Square<5>::result,
    Square<6>::result,
    Square<7>::result,
    Square<8>::result,
    Square<9>::result,
    Square<10>::result,
    Square<11>::result,
    Square<12>::result,
};

void cantor_set(string &s, int n, int start = 0) {
    if (n == 0) return;
    int i = 0;
    for (; i < square_array[n-1]; i++) {
        s[i + start + square_array[n-1]] = ' ';
    }
    cantor_set(s, n-1, start);
    cantor_set(s, n-1, i + start + square_array[n-1]);
}

int main() {
    int n;
    while (cin >> n) {
        string s; for (int i = 0; i < square_array[n]; i++) {
            s.push_back('-');
        }
        cantor_set(s, n);
        cout << s << '\n';
    }
    return 0;
}