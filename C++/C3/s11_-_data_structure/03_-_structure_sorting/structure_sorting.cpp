#include<bits/stdc++.h>
using namespace std;

struct Date {
	string name;
	int year,month,day;

	void printinfo() {
		cout<<name<<" ";
		printf("%d-%d-%d\n",year,month,day);
	}
};

bool cmp(Date a,Date b)
{
	if(a.year<b.year) {
		return true;
	} else if(a.year==b.year) {
		if(a.month<b.month) {
			return true;
		} else if(a.month==b.month) {
			if(a.day<b.day) {
				return true;
			} else {
				return false;
			}


		}
	}
	return false;
}

int main()
{
	Date sr[4];
	sr[0]= {"a",1999,9,9};
	sr[1]= {"c",2003,7,7};
	sr[2]= {"x",1998,8,8};
	sr[3]= {"y",2003,7,7};

	sort(sr,sr+4,cmp);

	for(int i=0; i<4; ++i) {
		sr[i].printinfo();
	}

}
