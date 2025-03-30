/*
*
**
***
****
*****

#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
	return 0;
}

*/



/*
*
**
***
****
*****
*****
****
***
**
*

#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=1;i<=5;i++){
		for(int j=5;j>=i;j--){
			cout<<"*";
		}
		cout<<endl;
	}

	return 0;
}
*/


/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			cout<<"*";
		}
		cout<<endl;
	}

	return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}

	return 0;
}

*/


/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int k=n-1;k>=i;k--){
			cout<<" ";
		}
		for(int j=1;j<=i*2-1;j++){
			cout<<"*";
		}
		cout<<endl;
	}

	return 0;
}
*/

/*
*****
****
***
**
*
**
***
****
*****
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			cout<<"*";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
	return 0;
}
*/


/*
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int k=n-1;k>=i;k--){
			cout<<" ";
		}
		for(int j=1;j<=i*2-1;j++){
			cout<<"*";
		}
	cout<<endl;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<" ";
		}
		for(int j=n;j>=i*2-(n-2);j--){
			cout<<"*";
		}
		
	cout<<endl;
	}
	
	return 0;
}
*/


/*
for(int i=1;i<=5;i++){
		
		cout<<endl;
	}
for(int i=1;i<=n;i++){
		
		cout<<endl;
	}
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int k=n-1;k>=i;k--){
			cout<<" ";
		}
		for(int j=1;j<=i*2-1;j++){
			cout<<"*";
		}
		for(int j=n-1;j>=i;j--){
			cout<<" ";
		}
		for(int k=n-1;k>=i;k--){
			cout<<" ";
		}
		for(int j=1;j<=i*2-1;j++){
			cout<<"*";
		}
	cout<<endl;
	}


	return 0;
}
