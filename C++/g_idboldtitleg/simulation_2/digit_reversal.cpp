#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// ��ת����
long long reverseNumber(long long n) {
    long long m = 0;
    while (n > 0) {
        m = m * 10 + n % 10;
        n /= 10;
    }
    return m;
}

// ������
long long calculateResult(long long n) {
    long long m = reverseNumber(n);
    long long diff = abs(n - m);
    if (diff % 2 == 1) {
        return n * m;
    } else {
        return diff;
    }
}

int main() {
    long long n;
    cin >> n;
    cout << calculateResult(n) << endl;
    return 0;
}

