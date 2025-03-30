#include<bits/stdc++.h>
using namespace std;
/*用结构体写一个栈

栈是一种组织数据的方式，就像一个桶一样，其特点是我们只能操作最上面的数据

|   |
| D |
| C |
| B |
| A |
*---*

在上面这幅图中，想要对C做什么，就必须要先让D出来

因为操作C要让D出来，所以栈要有出栈的操作；这些东西是怎么进去的呢？肯定也要有一个入栈的操作

*/

struct Stack{
	char a[1000];
	int top=0;
	//入栈
	void push(char c){
		top++;
		a[top]=c;
	}
	//出栈
	char pop(){
		char t=a[top];
		--top;
		return t;
	}
	//查询
	char ztop(){
		return a[top];
	}
};

int main(){
	
	Stack zhan;
	zhan.push('x');
	zhan.push('h');
	cout<<zhan.pop()<<endl;/*输出：h*/
	cout<<zhan.ztop();
	
}
