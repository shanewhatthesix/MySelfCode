#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n!=1){
		if(n%2==1){
			cout<<n<<"*3+1=";
			n=n*3+1;
			cout<<n<<endl;
		}
		else{
			cout<<n<<"/2=";
			n/=2;
			cout<<n<<endl;
		}
	}

	return 0;
}
/*
角谷猜想
描述

角谷猜想是由日本数学家角谷静夫发现，是指对于每一个正整数，如果它是奇数，则对它乘3再加1；如果他是偶数，则对它除以2。如此循环，最终都能得到1。

也就是说，给定正整数n ，要进行如下操作：

1）若n为1，操作结束。

2）若n为偶数，则n变成n/2.

3）若n为大于1的奇数，则n变成n*3+1。

请编程验证此猜想。

*/
