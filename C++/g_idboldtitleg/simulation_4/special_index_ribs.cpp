#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ʹ�ð�����˹����ɸ����������
vector<bool> generatePrimes(int maxNum) {
    vector<bool> isPrime(maxNum + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 �� 1 ��������

    for (int i = 2; i * i <= maxNum; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxNum; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// ���һ�����Ƿ�����������
bool isSpecialPrime(int num, const vector<bool>& isPrime) {
    int temp = num;
    while (temp > 0) {
        if (!isPrime[temp]) {
            return false; // ���ĳ����׺�������������� false
        }
        temp /= 10; // ȥ�����һλ����
    }
    return true; // ���к�׺��������
}

// �������г���Ϊ n ����������
void findSpecialPrimes(int n) {
    // �������ֵ
    int maxNum = pow(10, n) - 1; // 10^n - 1
    vector<bool> isPrime = generatePrimes(maxNum); // ������������

    // �������Ϊ n ����������
    for (int i = pow(10, n - 1); i <= maxNum; i++) {
        if (isPrime[i] && isSpecialPrime(i, isPrime)) { // ���ж��Ƿ�Ϊ�������ټ���Ƿ�Ϊ��������
            cout << i << endl;
        }
    }
}

int main() {
    int n;
    cin >> n; // �����߹ǵ�����
    findSpecialPrimes(n); // ������������
    return 0;
}

