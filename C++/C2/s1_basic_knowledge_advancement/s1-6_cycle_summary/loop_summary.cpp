/*
3种循环：for，while，do while



循环的基本逻辑:

for：
for(int i=1;i<10;i+=1){
    我是代码;
}
for(循环变量;循环执行条件;循环变量怎么变){
    我是代码；
}
for循环，先判断条件，如果成立就循环，并且循环变量只在for的作用域内起效果


while:
int i=0;
while (i<10){
	我是代码;
}
while循环，先判断条件，成立的话就执行循环，循环变量在作用域外定义


do while:
int i=0;
do{
    我是代码;
}while(i<10);
do while循环，先执行一次再判断是否成立，循环变量在作用域外定义
