//// 6. 函数 ////
//封装的常用代码，一个较大程序中被分成的几块

#include<iostream>
using namespace std;


//6.1 函数定义
/*定义步骤
1.返回值类型（需要的数据类型）      int
2.函数名                        add
3.参数列表（传入数据）             (int num1,int num2)
4.函数体语句                     int sum = num1 + num2
5.return 表达式（反馈结果）        return sum
*/

//实现一个加法函数，传入两个整数型，返回相加结果
int add (int num1,int num2)
{
    int sum = num1 + num2;
    return sum;
}
//num1,num2没有实际值，是形式上的参数，形参


//6.2 函数调用
int main(){
    int a = 10;
    int b = 20;
    int c = add(a,b);
    cout << c << endl;
    cout << a << " " << b << endl;
    system("pause");
    return 0;
}
//a,b是实际参数，简称实参


//6.3 值传递
//验证：做值传递时，函数形参的改变不会影响实参(见上面的main函数)

//先定义函数，实现两个数字进行交换函数
//如果函数无需返回值，声明时写void
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


//6.4 常见函数形式

//1.无参无返
void test01()
{
    cout << "test01" << endl;
}
//2.有参无返
void test02(int a)
{
    cout << "test02" << endl;
}
//3. 无参有返
int test03()
{
    cout << "test04" << endl;
    return 10;
}
//4.有参有返
int test04()
{
    test01();
    test02(100);
    int num1 = test03();
    return 0;
}


//6.5 函数的声明
//比较函数，比较两个整型数，返回较大值
int max(int a,int b){
    return a>b? a:b;
}
//一般main函数放在最后，否则会报错，但是可以提前告诉main函数的存在
//声明可以多次，定义只能有1次
/*eg：
int max(int a, int b);

int main(){
...
}
*/

//6.6 函数分文件编写
//1. 创建.h头文件
//2.创建.cpp源文件
//3.在头文件中写函数声明
//4.在源文件中写函数定义



