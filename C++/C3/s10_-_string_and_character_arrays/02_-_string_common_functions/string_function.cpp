#include<bits/stdc++.h>
using namespace std;
int main() {

	/*1.
	插入字符串
	insert(size_t pos,const string& str)
	pos表示要插入的位置，也就是下标；str表示要插入的字符串
	string s1_1,s1_2,s1_3;
	s1="0123456789";
	s3="aaa";
	s1.insert(5,s3);
	cout<<s1<<endl;
	输出：01234aaa56789
	*/

	/*2.
	删除字符串
	erase() 函数可以删除 string 中的一个子字符串。它的一种原型为：
	erase (size_t pos = 0, size_t len = npos);
	pos 表示要删除的子字符串的起始下标，len 表示要删除子字符串的长度。如果不指明len的话，那么直接删除从pos到字符串结束处的所有字符
	string s1,s2,s3;
	s1=s2=s3="1234567890";
	s2.erase(5);
	s3.erase(5,3);
	cout<<s1<<" "<<s2<<" "<<s3;
	输出：1234567890 12345 1234590
	*/

	/*3.
	提取子字符串
	substr() 函数用于从 string 字符串中提取子字符串，它的原型为：
	substr (size_t pos = 0 , size_t len = npos);
	pos 为要提取的子字符串的起始下标，len 为要提取的子字符串的长度。
	string s1="first second third";
	string s2;
	s2=s1.substr(6,6);
	cout<<s1<<endl<<s2;
	输出：
	first second third
	second*/
	
	/*4.
	字符串查找（左起）
	被查找字符串.find(查找字符,查找个数)
	字符串查找（右起）
	被查找字符串.rfind(查找字符,查找个数)
	*/
}
