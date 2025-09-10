//// 3. 函数提高 ////

#include <iostream>
using namespace std;

//3.1 函数默认参数
//形参可以有默认值
//语法：返回值类型 函数名 （形参 = 默认值）{} 
int func(int a,int b = 20,int c = 30){
    return a+b+c;
}

int main(){
    cout << func(10) << endl;   //60
    cout << func(10,30) << endl;    //70
}
/*
1.若某位置已有默认参数，后面的形参也必须有默认值
2.默认参数可以在调用的时候更改赋值
3.若函数声明有默认参数，函数实现就不能有默认参数,只能有一个
*/
int func1(int a = 10,int b =10);

int func1(int a = 20,int b = 20){   //a，b有歧义
    return a+b;
}

int main(){
    cout << func1(50,20) << endl;
}


//3.2 函数占位参数
//函数形参列表中可以有占位参数，用来占位，调用时必须补全
void func2(int a,int){
    cout << "this is function" << endl;
}

int main(){
    func2(10,10);
}
//只做说明


//3.3 函数重载——函数名可相同，提高复用性
//3.3.1 概述
/*满足条件
1.同一作用域（目前都是全局）
2.函数名相同
3.参数类型，个数，顺序不同
*/
//注：返回值不是条件之一
void func3(){
    cout << "func3的调用" << endl;
}

void func3(int a){
    cout << "func3(int a)的调用" << endl;
}

void func3(double b){
    cout << "func3(double b)的调用" << endl;
}

void func3(int a,double b){
    cout << "func3(int a,double b)的调用" << endl;
}

void func3(double b,int a){
    cout << "func3(double b,int a)的调用" << endl;
}

int func3(double b,int a){  
    //Functions that differ only in their return type cannot be overloaded
    cout << "func3(double b,int a)的调用" << endl;   
}

int main(){
    func3();    //调用上面
    func3(10);  //调用下面，根据输入参数来重载
}


//3.3.2 引用作为重载条件
void fun(int& a){   //参数相当于指针常量
    cout << "fun(int& a)重载" << endl;
}

void fun(const int& a){ //参数相当于修饰指针
    cout << "fun(const int& a)重载" << endl;
}

int main(){
    int a = 10;
    fun(a); //int& a = 10; 不合法
    fun(10);    //const int& a = 10; 合法
}


//3.3.3 重载时存在默认参数
void fun1(int a,int b = 10){
    cout <<"fun1(int a,int b = 10)" << endl;
}

void fun1(int a){
    cout <<"fun1(int a)" << endl;
}

int main(){
    fun1(10);    //出现二义性，重载时避免默认参数
}



