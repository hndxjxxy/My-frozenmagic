//// 2. 引用 ////

#include <iostream>
using namespace std;
int main(){

//2.1 基本使用
//引用——给变量起别名
//语法：数据类型 &别名 = 原名
int a = 10;
int &b = a;
b = 100;
cout << a << endl;
cout << b << endl;  //a=100,b=100


//2.2 注意事项
//1. 引用必须初始化
//int &b;   报错
//2.初始化后不可改变
int c = 20;
b = c;  //c的20赋值给b，而不是更改引用
}


//2.3 引用做函数参数
//简化指针的形参修饰实参
//交换函数
//1. 值传递
void swap(int a,int b){
    int temp = a;
    a = b;
    b = temp;
    cout << a << endl;
    cout << b << endl;
}
//2. 地址传递
void swap_a(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << a << endl;
    cout << b << endl;
}
//3. 引用传递——形参修饰实参， 
void swap_y(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
    cout << a << endl;
    cout << b << endl;
}

int main(){
    int a = 10;
    int b = 20;
    swap(a,b);
    cout << a << endl;
    cout << b << endl;
}


//2.4 引用做函数的返回值
//1.不要返回局部变量引用
int& test()
{
    int a = 10; //局部变量存放在栈区
    return a;
}
//2.函数调用可以作为左值
int& test1()
{
    static int a = 10; //静态变量存放在全局区
    return a;
}

int main(){
    int &ref = test();
    cout << ref << endl;

    test1() = 1000;
    int &ref1 = test1();
    cout << ref1 << endl;  
}


//2.5 引用的本质——指针常量,所有指针的操作编译器都代劳了，所以引用非常方便
void func(int& ref){
    ref = 100;
}

int main(){
    int a = 10;
    int& ref = a;   //自动转换为int* const ref = &a;
                    //指针常量不可更改地址，也说明引用不可更改
    ref = 20;   //发现ref是引用，自动转换为*ref = 20;

    cout << a <<endl;
    cout << ref << endl;

    func(a);
    return 0;
}


//2.6 常量引用
//修饰形参，防止误操作（结构体也可以）
//打印数据函数
void showPrint(const int& val){
    val = 1000; //加上const此处就会报错
    cout << val << endl;
}

int main(){
    // int a = 10;
    // int& ref = a;
    //int& ref = 10; 必须引用一段合法的内存空间
    const int& ref = 10;    //加上const后，编译器将代码优化为int temp = 10;
                            //const int& ref = temp;
    //ref = 20;此时ref为只读，无法修改
    int a = 100;
    showPrint(a);   //此时val会修改a的值
}
















