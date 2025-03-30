#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e8 + 10;  // ����һ������ N����ʾ�����ܵ���ֵ
int n, q;  // ����� n �� q��n ������ֵ��q �ǲ�ѯ������
bool book[N];  // �������ÿ�����Ƿ�������������

// ��ȡС�ڵ���n����������
vector<int> get_primes(int n) {
    vector<int> v;
    // ��2��ʼ�����ÿ�����Ƿ�������
    for (int i = 2; i <= n; i++) {
        if (!book[i]) v.push_back(i);  // �����ǰ�������������뵽v��
        for (int j = 0; v[j] <= n / i; j++) {
            book[v[j] * i] = true;  // �������v[j]�ı���Ϊ������
            if (i % v[j] == 0) break;  // ֻҪ��һ��С�ڵ���sqrt(n)����������i��ֹͣ
        }
    }
    return v;  // ������������
}

// �ж�һ�����Ƿ�������
bool is_prime(int n) {
    if (n < 2) return false;  // С��2������������
    for (int i = 2; i <= n / i; i++) {  // ��2��sqrt(n)�ж��Ƿ���Լ��
        if (n % i == 0) return false;  // ���n�ܱ�i��������������
    }
    return true;  // ���û���ҵ�Լ��������true����ʾ������
}

// ������ֵ�ÿһλ�Ƿ�Ϊ����
bool check(int n) {
    while (n) {  // ��n��ÿһλ���м��
        if (!is_prime(n)) return false;  // �������һλ�����������򷵻�false
        n /= 10;  // ȥ����ǰ�����һλ
    }
    return true;  // ����λ��Ϊ����
}

int main() {
    cin >> n;  // ���������ֵn
    auto primes = get_primes(n);  // ��ȡС�ڵ���n����������
    int res = 0;  // ��������������洢������������������
    for (auto x : primes) {  // ������������
        if (check(x))  // �����������ÿһλ��Ϊ����
            res++;  // ���ӽ������
    }
    cout << res;  // ������
    return 0;  // �������
}
