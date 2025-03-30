#include<bits/stdc++.h>
using namespace std;
int main() {
	int x = 101;
	int y = 201;
	int *p = &x;
	int *q = &y;
	p = q;
	cout<<"p="<<p<<endl<<"q="<<q;
}

