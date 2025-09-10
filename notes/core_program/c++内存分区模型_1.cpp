//c++核心编程阶段主要介绍面向对象的变成技术

//// 1. 内存分区模型 ////
//c++执行程序时将内存划分为4个区域，让编程更灵活
/*
代码区：操作系统管理，存放二进制代码
全局区：存放全局变量，静态变量和常量
栈区：编译器自动分配释放，存放函数参数值，局部变量等
堆区：程序员分配和释放，不主动释放，程序结束时会由操作系统回收
*/


//1.1 程序运行前，程序编译后，生成了exe可执行文件，这时存在两个区域
//1. 代码区：存放cpu执行的机器命令
    //特点：共享&只读，允许频繁引用和执行代码，并且防止修改

//2. 全局区：存放全局变量，静态变量和常量（字符串常量&const常量）
    //该区域数据在程序结束后由操作系统释放

#include <cstdlib>
#include <iostream>
using namespace std;

//全局变量
int g_a = 20;
int g_b = 10;

//const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 20;

int main(){
    //局部变量
    int a = 1;
    int b = 2;
    cout << size_t(&a) << endl;
    cout << size_t(&b) << endl;
    cout << size_t(&g_a) << endl;
    cout << size_t(&g_b) << endl;
    // 140721106227792
    // 140721106227796
    // 105596332544016
    // 105596332544020

    //静态变量
    static int s_a = 5;
    static int s_b = 6;
    cout << size_t(&s_a) << endl;
    cout << size_t(&s_b) << endl;    
    // 111102036983824
    // 111102036983828
    // 111102036983832
    // 111102036983836
    //全局&静态

    //常量
    //字符串常量
    cout << (size_t)&"hello world" << endl;
    // 94725819191312
    // 94725819191316
    // 94725819191320
    // 94725819191324
    // 94725819183108

    //const修饰
    //const修饰的全局变量
    cout << (size_t)&c_g_a << endl;
    cout << (size_t)&c_g_b << endl;

    //const修饰的局部变量（不在全局区中）
    const int c_a = 10;
    const int c_b = 20;
    cout << (size_t)&c_a << endl;
    cout << (size_t)&c_b << endl;
    // 98324049305604
    // 98324049305608
    // 140726098700576
    // 140726098700580

    system("pause");
    return 0;
}


//1.2 程序运行后
//此时4个区域都存在
//1. 栈区：注.不要返回局部变量的地址，栈区
int* func(){
    int a = 10; //存放在栈区，在函数执行完就自动释放了
    return &a;
}

int* func1(int b){  //形参也存放在栈区
    b = 100; 
    return &b;
}

int main(){
    int * p = func();
    cout << *p <<endl;  //首打印是因为编译器保留1次
    cout << *p << endl; //编译器不会一直保存
    system("pause");
    return 0;
}


//2. 堆区
//用new关键字开辟数据
int* func2(){
    //指针本质也是局部变量，放在栈上，指针保存的数据放在堆区
    int * p = new int(10);
    return p;
}

int main(){
    int* p = func2();
    cout << *p << endl;
    //释放堆区
    delete p;
    cout << *p << endl;  //报错
}

//在堆区开辟一个数组
void test(){
    int* arr = new int[10];
    for (int i = 0;i<10;i++){
        arr[i] = i+100;
    }
    for (int i = 0;i<10;i++){
        cout << arr[i] << endl;
    }
    delete [] arr;  //释放数组时加入中括号
}

































    
