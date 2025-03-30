#include<bits/stdc++.h>
using namespace std;
/*
筛法原理

先把N个自然数按次序排列起来

1不是质数，也不是合数，要划去

第二个数是2是质数留下来，而把2后面所有能被2整除的数都划去

2后面一个没划去的数是3，把3留下，再把3后面所有能被3整除的数都划去

3后面有第一个没划去的数是5，把5留下，再把5后面所有能被5整除的数都划去

就一直这样做下去，就会把不超过N的全部合数都划掉，留下的就是不超过N的全部质数

*/

/*
数组定义到外头

大家在写的时候有没有注意到一个问题：

数组里的元素一开始都是得一，也就是说我们得进行速度的 初始化。

这个时候我们可以这样写：

把数组定义在main外面，数组的元素就都是a

int a [10000];

int main(){
	...
}

注意这种写法，数组的元素个数最多是10^7

*/

int n=10000;
int a[10000];
int main() {
	for(int i=2; i<=n/2; ++i)
		if(a[i]==0)
			for(int j=2; j*i<=n; ++j)
				a[j*i]=1;
	for(int i=2;i<=100;++i)//显示前一百个看看结果
		if(a[i]==0)
		cout<<i<<" ";
		return 0;
}

