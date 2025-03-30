#include<bits/stdc++.h>
using namespace std;

int n(int lx,int jc) {
	if(jc=='k')lx*=1e3;
	else if(jc=='M')lx*=1e6;
	return lx;

}

int main() {
	double v=0,s=0,t=0;
	char c,lastc;
	while(cin>>c) {
		if(c=='=') {
			if(lastc=='V') {
				cin>>v;
				cin>>c;
				if(c=='k')v*=1e3;
				else if(c=='M')v*=1e6;
			} else if(lastc=='T') {
				cin>>t;
				cin>>c;
				if(c=='k')t*=1e3;
				else if(c=='M')t*=1e6;
			} else if(lastc=='S') {
				cin>>s;
				cin>>c;
				if(c=='k')s*=1e3;
				else if(c=='M')s*=1e6;
			}
		}
		lastc=c;
	}

	if(v==0) {
		printf("V=%.2fm/s",s/t);
	}
	if(t==0) {
		printf("T=%.2fs",s/v);
	}
	if(s==0) {
		printf("S=%.2fm",v*t);
	}

	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

// 函数用于读取并转换数值，考虑'k'和'M'后缀
double readValueWithSuffix() {
    double value;
    char suffix;
    cin >> value >> suffix;
    if (suffix == 'k') value *= 1e3;
    else if (suffix == 'M') value *= 1e6;
    return value;
}

// 主函数
int main() {
    double v = 0, s = 0, t = 0;
    char c, lastc = '\0';

    while (cin >> c) {
        if (c == '=') {
            switch (lastc) {
                case 'V':
                    v = readValueWithSuffix();
                    break;
                case 'T':
                    t = readValueWithSuffix();
                    break;
                case 'S':
                    s = readValueWithSuffix();
                    break;
            }
        }
        lastc = c;
    }

    // 输出计算结果
    if (v == 0 && s != 0 && t != 0) {
        printf("V=%.2fm/s", s / t);
    }
    if (t == 0 && s != 0 && v != 0) {
        printf("T=%.2fs", s / v);
    }
    if (s == 0 && v != 0 && t != 0) {
        printf("S=%.2fm", v * t);
    }

    return 0;
}
*/
