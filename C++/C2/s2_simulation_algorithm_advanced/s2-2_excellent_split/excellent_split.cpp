#include<bits/stdc++.h>
using namespace std;
int main()
{

	//把一个数拆分成2的正整数次方

	//但凡是奇数，一定不是优秀的拆分

	int n;
	cin>>n;
	

	if(n%2!=0)
	{
		cout<<-1;
		return 0;
	}
	
	if(n>=8388608)
	{
		cout<<8388608<<" ";
		n-=8388608;
	}
	if(n>=4194304)
	{
		cout<<4194304<<" ";
		n-=4194304;
	}
	if(n>=2097152)
	{
		cout<<2097152<<" ";
		n-=2097152;
	}
	if(n>=1048576)
	{
		cout<<1048576<<" ";
		n-=1048576;
	}
	if(n>=524288)
	{
		cout<<524288<<" ";
		n-=524288;
	}
	if(n>=262144)
	{
		cout<<262144<<" ";
		n-=262144;
	}
	if(n>=131072)
	{
		cout<<131072<<" ";
		n-=131072;
	}
	if(n>=65536)
	{
		cout<<65536<<" ";
		n-=65536;
	}
	if(n>=32768)
	{
		cout<<32768<<" ";
		n-=32768;
	}
	if(n>=16384 )
	{
		cout<<16384 <<" ";
		n-=16384 ;
	}
	if(n>=8192)
	{
		cout<<8192<<" ";
		n-=8192;
	}
	if(n>=4096)
	{
		cout<<4096<<" ";
		n-=4096;
	}
	if(n>=2048)
	{
		cout<<2048<<" ";
		n-=2048;
	}
	if(n>=1024)
	{
		cout<<1024<<" ";
		n-=1024;
	}
	if(n>=512)
	{
		cout<<512<<" ";
		n-=512;
	}
	if(n>=256)
	{
		cout<<256<<" ";
		n-=256;
	}
	if(n>=128)
	{
		cout<<128<<" ";
		n-=128;
	}
	if(n>=64)
	{
		cout<<64<<" ";
		n-=64;
	}
	if(n>=32)
	{
		cout<<32<<" ";
		n-=32;
	}
	if(n>=16)
	{
		cout<<16<<" ";
		n-=16;
	}
	if(n>=8)
	{
		cout<<8<<" ";
		n-=8;
	}
	if(n>=4)
	{
		cout<<4<<" ";
		n-=4;
	}
	if(n>=2)
	{
		cout<<2<<" ";
		n-=2;
	}



	return 0;
}


/*
描述

一般来说,一个正整数可以拆分成若干个正整数的和。例如,1 = 1,10 =1 + 2 + 3 + 4 等。

对于正整数 n 的一种特定拆分,我们称它为“优秀的”,当且仅当在这种拆分下,n 被分解为了若干个不同的 2 的正整数次幂。
注意,一个数 x 能被表示成 2 的正整数次幂,当且仅当 x 能通过正整数个 2 相乘在一起得到。

例如,10 = 8 + 2 = 2^3 + 2^1 是一个优秀的拆分。但是,7 = 4 + 2 + 1 =2^2 + 2^1 + 2^0 就不是一个优秀的拆分,因为 1 不是 2 的正整数次幂。

现在,给定正整数 n,你需要判断这个数的所有拆分中,是否存在优秀的拆分。若存在,请你给出具体的拆分方案。


输入
输入文件名为 power.in。

输入文件只有一行,一个正整数 n,代表需要判断的数。


输出
输出文件名为 power.out。

如果这个数的所有拆分中,存在优秀的拆分。那么,你需要从大到小输出这个拆分中的每一个数,相邻两个数之间用一个空格隔开。
可以证明,在规定了拆分数字的顺序后,该拆分方案是唯一的。

若不存在优秀的拆分,输出“-1”(不包含双引号)。


输入样例 1

6
输出样例 1

4 2
输入样例 2

7
输出样例 2

-1
提示

对于 20% 的数据,n ≤ 10。

对于另外 20% 的数据,保证 n 为奇数。

对于另外 20% 的数据,保证 n 为 2 的正整数次幂。

对于 80% 的数据,n ≤ 1024。

对于 100% 的数据,1 ≤ n ≤ 1 × 10^7 。

*/
