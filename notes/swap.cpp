#include "swap.h"   //双引号表示自定义头文件
#include<iostream>
using namespace std;

void swap(int num1,int num2){
    cout << "交换前" << endl;
    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "交换后" << endl;
    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;
    //不需要返回值时，可不写return
}