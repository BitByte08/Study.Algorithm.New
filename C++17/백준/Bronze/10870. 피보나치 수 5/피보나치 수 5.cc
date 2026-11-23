#include <iostream>

using namespace std;

template <int N>
struct Fibonacci {
    static const long result = Fibonacci<N - 1>::result + Fibonacci<N - 2>::result;
};

template <>
struct Fibonacci<0> {
    static const long result = 0;
};

template <>
struct Fibonacci<1> {
    static const long result = 1;
};

long Fibonacci_sequence[] = {
    Fibonacci<0>::result,
    Fibonacci<1>::result,
    Fibonacci<2>::result,
    Fibonacci<3>::result,
    Fibonacci<4>::result,
    Fibonacci<5>::result,
    Fibonacci<6>::result,
    Fibonacci<7>::result,
    Fibonacci<8>::result,
    Fibonacci<9>::result,
    Fibonacci<10>::result,
    Fibonacci<11>::result,
    Fibonacci<12>::result,
    Fibonacci<13>::result,
    Fibonacci<14>::result,
    Fibonacci<15>::result,
    Fibonacci<16>::result,
    Fibonacci<17>::result,
    Fibonacci<18>::result,
    Fibonacci<19>::result,
    Fibonacci<20>::result,
};

int main() {
    int n; cin >> n;
    cout << Fibonacci_sequence[n];
    return 0;
}