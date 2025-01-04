#include<iostream>
#include <numeric> // std::gcd 사용을 위함
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int N;
    cin >> N;

    long long upper = 0, lower = 1;
    for(int i = 0 ; i< N;i++) {
        int item;
        cin >> item;
        long long GCD = gcd(lower, item);
        long long LCM = lower * item / GCD;
        upper = upper * (LCM / lower) + (LCM / item);
        GCD = gcd(upper, LCM);
        upper /= GCD;
        lower = LCM / GCD;
    }
    cout << lower << '/' << upper << endl;
    return 0;
}