#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=0;i<10;++i)
	{
		cout<<"你好"<<i<<endl;
	}
	//for 循环结构(累加算法):
	//for(循环变量;循环执行条件;循环变量怎么变)
	//{
	//    要执行的代码;
	//}
	//循环变量、在循环大括号中所定义的变量，只能在这个循环中使用，他们起作用的范围就是作用域

	//运算符         作用           示例                 说明
	//自增++   作用类似于 i+=1      ++i    先把i的值+1，再用I去做运算。效率最高
	//                              i++    先用i的值做运算，然后再给i+一。效率仅次于 前++
	//自减--   作用类似于 i-=1      --i    先把i的值-1，再用I去做运算。效率最高
	//                              i--    先用i的值做运算，然后再给i-一。效率仅次于 前--
	return 0;
}
