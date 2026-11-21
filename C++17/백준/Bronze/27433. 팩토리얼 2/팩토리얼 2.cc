#include <iostream>

using namespace std;

template <int N>
struct Factorial {
    static const long result = Factorial<N-1>::result * N;
};

template <>
struct Factorial<1> {
    static const long result = 1;
};

template <>
struct Factorial<0> {
    static const long result = 1;
};

long factorial_array[] = {
    Factorial<0>::result,
    Factorial<1>::result,
    Factorial<2>::result,
    Factorial<3>::result,
    Factorial<4>::result,
    Factorial<5>::result,
    Factorial<6>::result,
    Factorial<7>::result,
    Factorial<8>::result,
    Factorial<9>::result,
    Factorial<10>::result,
    Factorial<11>::result,
    Factorial<12>::result,
    Factorial<13>::result,
    Factorial<14>::result,
    Factorial<15>::result,
    Factorial<16>::result,
    Factorial<17>::result,
    Factorial<18>::result,
    Factorial<19>::result,
    Factorial<20>::result,
};

int main() {
    int n; cin >> n;
    cout << factorial_array[n];
}