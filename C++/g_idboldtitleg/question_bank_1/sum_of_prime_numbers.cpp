#include<bits/stdc++.h> // �������б�׼��ͷ�ļ�
using namespace std; // ʹ�ñ�׼�����ռ�

// �ж�һ�����Ƿ�Ϊ�����ĺ���
bool prime(int n) {
    // ��2��ʼ��n��ƽ�������б���
	for(int i = 2 ; i <= n / i ; i++)
		// ���n�ܱ�i��������n��������������false
		if(n % i == 0)
			return false;

	// ���û���ҵ�������n��������n������������true
	return true;
}

int main() {

	int num; // ����һ����������num
	cin >> num; // �ӱ�׼�����ȡһ��������num

	long long s = 0; // ����һ�������ͱ���s�������ۼ���������ʼ��Ϊ0
	// ѭ����2��num������num
	for(int i = 2; i <= num; i++)
		// ���i������������ӵ�s��
		if(prime(i))
			s += i;

	// �����2��num�����������ĺ�
	cout << s;

	return 0; // �������������0
}
