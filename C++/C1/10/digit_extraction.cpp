#include<bits/stdc++.h>
using namespace std;
int main()
{
	int input;
	cin>>input;
	int big = input/10;
	int small = input%10;
	cout<<big+small-1;
	return 0;
}

