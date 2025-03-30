#include<bits/stdc++.h>
using namespace std;

struct S{
	int top=0,a[7000];
	void push(int n){
		top++;
		a[top]=n;
	}
	int pop(){
		int t=a[top];
		top--;
		return t;
	}
};

int stonum(string s){
	int r=0;
	for(int i=0;i<s.size();++i){
		int t=s[i]-'0';
		r=r*10+t;
	}
	return r;
}

int main(){
	S z;
	cout<<1;
	string s;
	while (cin>>s){
		if(s[0]<'0' || s[0]>'9'){
			//符号
			if(s=="+"){
				int a=z.pop();
				int b=z.pop();
				z.push(a+b);
			}
			else if(s=="*"){
				int a=z.pop();
				int b=z.pop();
				z.push(a*b);
			}
			else if(s=="-"){
				int a=z.pop();
				int b=z.pop();
				z.push(b-a);
			}
		}
		else{
			//s变成数值，存栈
			int t=stonum(s);
			z.push(t);
		}
	}
	cout<<z.pop();
	
	return 0;
}
/*

中缀表达式，就是我们平时所用的表达式
6*(3+2)

前缀表达式，也叫波兰式，运算符在数值的前面
*6+32

后缀表达式，也叫逆波兰式，是运算符在数值的后面
632+*


转中缀：
前缀要从后往前看，后缀要从前往后看。都是遇到符号在计算

这里我们以前缀表达式为例，看看它的计算过程

- * a + b c d
= a*(b+c)-d

a b c + * d -

表达式的前后缀转换要根据优先级来，把符号放在数值的前后

符号和数值分别像左括号和右括号一样框住更高一级的运算

9+(3-1)*3+10/2
= + + * 3 - 3 1 9 / 10 2

*/

