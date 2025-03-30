#include<bits/stdc++.h>
using namespace std;
int main()
{
	// 逻辑关系  运算符           说明
	//    与       &&       可以简单理解为并且
	//    或       ||       可以简单理解为或者
	//    非       !              取反
	int mark,poem;
	cin>>mark>>poem;
	if (mark>=425 && poem>=300){
		printf("qualified");
	}
	else {
		printf("unqualified");
	}
	
	return 0;
}
