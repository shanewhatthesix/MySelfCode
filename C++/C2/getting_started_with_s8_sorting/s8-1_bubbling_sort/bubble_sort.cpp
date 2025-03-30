#include<bits/stdc++.h>
using namespace std;
/*
0:  7   19  9   23  46  31  14

1:  7   9   19  23  31  14  46

2:  7   9	19  23  14  31  46

3:  7   9   19  14  23  31  46

4:  7   9   14  19  23  31  46

*/
int main(){
	int a[5]={7,19,9,23,46}
	cout<<a;
	for(int i=0;i<n-1;++i){
		if(a[i]>a[i+1]){
			swap(a[i],a[a[i+1]]);
		}
	}
}
