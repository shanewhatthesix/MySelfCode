#include<bits/stdc++.h>
using namespace std;

struct Queue
{
	/*  头      尾     大小   */
	int front=0,rear=-1,size=0;
	int a[1000];

	//有一个人要来排队
	void push(int n)
	{
		rear++;
		a[rear]=n;
		size++;
	}

	//有一个人要出队
	void pop()
	{
		front++;
		size--;
	}

};
