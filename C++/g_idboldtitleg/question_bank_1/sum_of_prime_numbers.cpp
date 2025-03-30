#include<bits/stdc++.h> // 包含所有标准库头文件
using namespace std; // 使用标准命名空间

// 判断一个数是否为素数的函数
bool prime(int n) {
    // 从2开始到n的平方根进行遍历
	for(int i = 2 ; i <= n / i ; i++)
		// 如果n能被i整除，则n不是素数，返回false
		if(n % i == 0)
			return false;

	// 如果没有找到能整除n的数，则n是素数，返回true
	return true;
}

int main() {

	int num; // 定义一个整数变量num
	cin >> num; // 从标准输入读取一个整数到num

	long long s = 0; // 定义一个长整型变量s，用于累加素数，初始化为0
	// 循环从2到num，包括num
	for(int i = 2; i <= num; i++)
		// 如果i是素数，则将其加到s上
		if(prime(i))
			s += i;

	// 输出从2到num的所有素数的和
	cout << s;

	return 0; // 程序结束，返回0
}
