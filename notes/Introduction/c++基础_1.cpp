//0帧起手模版

#include<iostream>
using namespace std;

int main()
{
    cout << "hello world!" << endl;
    system("pause");
    return 0;
}  namespace name


//1.1 注释//
//单行注释//
/*多行
    注释*/


//1.2 变量---方便管理内存//
/*16进制内存编号0x0000
  变量语法： 数据类型 变量名 = 变量初始值*/
  int a = 10;


//1.3 常量---不可更改的数据
//    1. #define-宏常量（通常在文件上方定义）
//    2. const修饰的变量
#define Day 7
int main()
{
    const int Month = 7;
    cout << "一周共有" << Day << "天" << endl;
    cout << "一年共有" << Month << "月" << endl;
}


//1.4 关键字
//不可用于c++命名

//1.5 标识符起名规则
/*
1. 不可为关键字
2. 只能包含字母，数字，下划线
3. 首字符必须为字母或下划线
4. 区分大小写
*/
int _123abc = 6;
int 123abc =6;
int num1 = 4;
int num2 = 9;
int sum = num1 + num2; 
//起名要见名知意



