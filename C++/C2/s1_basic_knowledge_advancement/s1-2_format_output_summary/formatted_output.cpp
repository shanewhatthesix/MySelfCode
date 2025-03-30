/*
//////////////////////////////////////////////////////////////////////////////////////////////////////
// 数据类型          / 格式化字符                                                                   //
// int               / %d                                                                           //
// long long		 / %lld                                                                         //
// float、double     / %F（通常只用来保留指定位小数）                                               //
// 					 / %g（当不指定保留几位小数时，用%g，但超过7位就不行了，%g实际上表示科学计数法）//
// char 			 / %c                                                                           //
// % %% 			 / 两个%就可以正常识别为%了                                                     //
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////
// 转义字符    /     用途   //
// \n          /     换行   //
// \r          /     回车   //
// \\          /     反斜杠 //
// \?          /     问号   //
// \'          /     单引号 //
// \"          /     双引号 //
//////////////////////////////
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	printf("---% 3d---\n",3);//%和d用于调用逗号后面的数字，而它们之间的0或者空格是填充内容，第二位是填充位数
	printf("---% 3d---\n",33);
	printf("---% 20d---\n",384);
	printf("---%020d---\n",3);
	//补空格：
	//注意倒霉补空格有个倒霉bug 下面两行代码执行的结果是一样的（补0没有这个bug ）
	printf("---% 2d---\n",35);
	printf("---% 3d---\n",35);
}
*/


/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	string w;
	cin>>w;
	int l = w.size();
	if (l==1){
		cout<<"'"<<w<<"'"<<endl;
	}
	else{
		cout<<"\""<<w<<"\"";
	}
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int aa=a,bb=b,cc=c,many=0;
	for(int i=0;aa>0;++i){many++;aa/=10;}
	if(many>=10){printf("\'%d\'\n",a);}
	else{printf("\'% 10d\'\n",a);}
	many=0;
	for(int i=0;bb>0;++i){many++;bb/=10;}
	if(many>=10){printf("\'%d\'\n",b);}
	else{printf("\'% 10d\'\n",b);}
	many=0;
	for(int i=0;cc>0;++i){many++;cc/=10;}
	if(many>=10){printf("\'%d\'\n",c);}
	else{printf("\'% 10d\'\n",c);}
	return 0;
}
*/
