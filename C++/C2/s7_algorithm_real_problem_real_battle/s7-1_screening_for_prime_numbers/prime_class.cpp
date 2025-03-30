/*
#include<bits/stdc++.h>
using namespace std;
int n=10000;
int a[10000];
int main() {
	int m;
	cin>>m;
	for(int i=0; i<m; ++i) {
		int h;
		cin>>h;
		for(int i=2; i<=n/2; ++i)
			if(a[i]==0)
				for(int j=2; j*i<=n; ++j)
					a[j*i]=1;
		for(int i=2; i<=100000; ++i)
			if(a[i]==0 && i==h)
				cout<<1<<endl;
			else if(i==h)
				cout<<0<<endl;

	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int h;
        cin >> h;
        bool isPrime = true;
        if (h <= 1) {
            isPrime = false; // 1 ��С��1�����ֶ���������
        } else {
            for (int j = 2; j <= sqrt(h); ++j) { // �����ж��߼�����
                if (h % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}

