#include<bits/stdc++.h>
using namespace std;

struct kh
{
	int top=0;
	char k[300];

	//ÈëÕ»
	void push(char c)
	{
		top++;
		k[top]=c;
	}
	//³öÕ»
	char pop()
	{
		if(top==0) return '0';
		char t=k[top];
		top--;
		return t;
	}
	//²éÑ¯
	char ztop()
	{
		return k[top];
	}
};

int main()
{
	string s;
	cin>>s;
	
	kh khs;
	
	for(int i=0;i<s.size();++i){
		char c=s[i];
		if(c=='['||c=='('){
			khs.push(c);
		}
		else {
			char t=khs.pop();
			if(c==']' && t=='['  ||  c==')' && t=='('){
				
			}
			else{
				cout<<"Wrong";
				return 0;
			}
		}
	}
	cout<<"OK";
}

