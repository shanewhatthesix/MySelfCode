#include<bits/stdc++.h>
using namespace std;

struct Queue
{
	/*  ͷ      β     ��С   */
	int front=0,rear=-1,size=0;
	int a[1000];

	//��һ����Ҫ���Ŷ�
	void push(int n)
	{
		rear++;
		a[rear]=n;
		size++;
	}

	//��һ����Ҫ����
	void pop()
	{
		front++;
		size--;
	}

};
