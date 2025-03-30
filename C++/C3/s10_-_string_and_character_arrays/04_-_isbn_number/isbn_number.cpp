#include<bits/stdc++.h>
using namespace std;
int main() {





	string s;
	cin>>s;

	int n = (s[0]-'0')*1 + (s[2]-'0')*2 + (s[3]-'0')*3 + (s[4]-'0')*4 + (s[6]-'0')*5 + (s[7]-'0')*6 + (s[8]-'0')*7 + (s[9]-'0')*8 + (s[10]-'0')*9;

	if(n%11==10) {
		if(s[12]=='X') {
			cout<<"Right";
		}
		else {
			s[12]='X';
			cout<<s;
		}
	}
	else if(n%11<10) {
		if(s[12]-'0'==n%11) {
			cout<<"Right";
		}
		else {
			s[12]=n%11+'0';
			cout<<s;
		}
	}

	return 0;
}
