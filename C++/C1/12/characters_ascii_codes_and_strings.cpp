#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s = "WD-34750";
	//中括号里加数,可以获取字符串中的字符
	//数---下标,下标从0开始
	char c = s[1];//获取下标为1的字符
	cout<<"c="<<c<<endl;
	
	//字符可以运算,用ASCII运算
	cout<<c+2<<endl;
    c+=2;
	cout<<"c="<<c;
	
	//char 类型在运算的时候是数值,在显示的时候是字符
	//改变字符:变量名+[下标]=新字符的ASCII码表;

	return 0;
}

