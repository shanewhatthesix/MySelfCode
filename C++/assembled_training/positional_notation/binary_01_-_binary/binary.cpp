#include<bits/stdc++.h>
using namespace std;
/*
*-------------------------------------------------------------------*
|	             |       千		百		十		个	 				|
|----------------|--------------------------------------------------|
|数字	         |       3		8		7		5	 				|
|----------------|--------------------------------------------------|
|对应的大小      |       3000	800		70		5	 				|
|----------------|--------------------------------------------------|
|拆分 	         |       3*10^3	8*10^2	7*10^1	5*10^0	 			|
*-------------------------------------------------------------------*
*/

/*
*-------------------------------------------------------------------------------------------------------*
|		| 7		6		5		4		3		2		1		0										|
|-------|-----------------------------------------------------------------------------------------------|
|		| 1		1		1		1		1		1		1		1										|
|-------|-----------------------------------------------------------------------------------------------|
|2^n	| 2^7	2^6		2^5		2^4		2^3		2^2		2^1		2^0										|
|-------|-----------------------------------------------------------------------------------------------|
|大小	| 128	64		32		16		8		4		2		1										|
*-------------------------------------------------------------------------------------------------------*

10101101 = 128 + 32 + 8 + 4 + 1 =173

-1	-2	-3
1/2	1/4	1/8

*/


/*
十进制转二进制的方法也分整数和小数
*-----------------------------------*
|整数				| 小数			|
|-------------------|---------------|
|除2取余，逆序排列	| 乘2取1		|
*-----------------------------------*

整数：
182/2=91......0
91/2=45........1
45/2=22........1
22/2=11........0
11/2=5..........1
5/2=2............1
2/2=1............0
1/2=0............1

所以，182=01101101

小数(3.304)：

0.304 * 2 = 0.608	11.0
0.608 * 2 = 1.216	11.01
0.216 * 2 = 0.432	11.010
0.432 * 2 = 0.864	11.0100
0.864 * 2 = 1.728	11.01001
0.729 * 2 = 1.456	11.010011
...

*/

/*
5.7 = 101.10110011 

*/

/*
2的1次方：2
2的2次方：4
2的3次方：8
2的4次方：16
2的5次方：32
2的6次方：64
2的7次方：128
2的8次方：256
2的9次方：512
2的10次方：1024
2的11次方：2048
2的12次方：4096
2的13次方：8192
2的14次方：16384
2的15次方：32768
2的16次方：65536

*/




