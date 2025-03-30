#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	char signal;
	cin>>a>>b>>signal;
	if (signal=='+'){
		cout<<a+b;
	}
	else if (signal=='-'){
		cout<<a-b;
	}
	else if (signal=='*'){
		cout<<a*b;
	}
	else if (signal=='/'){
		cout<<a/b;
	}

	return 0;
}
