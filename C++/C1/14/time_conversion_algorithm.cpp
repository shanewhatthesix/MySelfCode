#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;

	int s=n%60,m=n/60,h=m/60;
	printf("%d:%d:%d",h%60+19,m%60,s);

	return 0;
}
