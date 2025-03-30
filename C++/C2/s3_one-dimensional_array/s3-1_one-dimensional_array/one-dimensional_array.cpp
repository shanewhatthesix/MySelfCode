#include<bits/stdc++.h>
using namespace std;
int main()
{
	/*
	一维数组

	数组是相同类型元素的有序集合，是一种数据格式

	语法:数据类型 数组名 [元素个数];

	例如:int array[10];

	定义一个int类型的数组， 数组名为array ，元素个数为十个

	*/

	//float price[100];//定义一个float类型，名为price，有100个元素的数组

	//long long distence[1000];//定义一个long long int类型，名为 distance，有1000个元素的数组

	//char level[9];//定义一个char类型，名为level，有9个元素的数组

	//string name[48];//定义一个string类型，名为name，有48个元素的数组


	/*
    读取数组元素
	
	想要使用数组中的元素,需要按照下面的格式来写：

	    数组名[下标]

	例如：

	    name[3]

	中括号中的3就是下标，指的是数组中元素的位置
	
	*/
	
	
	/*
	下标
	
	例如一个char类型，名为level，9个元素的数组
	*-----------------------------------------------------------------------------------------------------------------------*
	|下标  |  0 	  		1  	 		2 	 		3  	 		4  	 		5  	 		6  	 		7  	 		8           |
	|-----------------------------------------------------------------------------------------------------------------------|
	|level |  a   			a   		b   		b   		c   		c   		s   		s   		a           |
	|-----------------------------------------------------------------------------------------------------------------------|
	|使用  |  level[0]    	level[1]    level[2]    level[3]    level[4]    level[5]    level[6]    level[7]    level[8]    |
	*-----------------------------------------------------------------------------------------------------------------------*
	
	下标(也称为索引)，指的是元素在数组中的位置。计算机中数组的下标都是从零开始的，这点一定要记清楚
	
	下标从零开始，最后一个元素的使用为：元素名[元素总数-1]
	
	*/
	
	/*
	数组初始化
	
	类型名 + 数组名 [元素个数 ]= {值1,值2,直3 ... }
	
	1、 使用大括号把值括起来 ，值与值之间使用逗号分割
	
	2、大括号中值的数量可以小于元素个数，但不能大于元素个数
	
	3、想要在定义的时候初始化数组，只能用大括号，不能使用其他数组
	
	
	例如：
	
	int age[20]={1,2,3};初始化前3位,未初始化的都是0。并且在这一行之内,不能再定义或者初始化其他的数组
	cout<<age[2];
	
	*/
	
	//数组之所以使用方便，很重要的一个原因是遍历
	
	//比如有一个100个元素的数组
	
	int a[100];
	for(int i=0;i<100;++i){
		// i<100，而不是 i<=100 的原因：元素为100个的数组 ,下标只有99
		cin>>a[i];
		//cout<<a[i]<<endl;
	}
	
	/*
	int age[20];//定义一个int类型，名为age，有20个元素的数组

	float price[100];//定义一个float类型，名为price，有100个元素的数组

	long long distence[1000];//定义一个long long int类型，名为 distance，有1000个元素的数组

	char level[9];//定义一个char类型，名为level，有9个元素的数组

	string name[48];//定义一个string类型，名为name，有48个元素的数组
	*/
	
	return 0;

}

