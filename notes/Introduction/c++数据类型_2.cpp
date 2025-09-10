/// 2 数据类型 ///
//意义：给变量分配一个合适的内存空间

//2.1 整型

/*1. 短整型
    short 2bit -2^15~2^15-1*/
    short num1 = 10;

//2. 整型
    
    int num2 = 10;
//3. 长整型
    long num3 = 10;
//4. 长长整型
    long long num4 = 10;


//2.2 sizeof关键字——统计数据类型所占内存大小
//语法： sizeof（数据类型/变量） 单位：字节
cout << "num1占用的内存空间为" << sizeof(num1) << endl;
//补充：sizeof是一个操作符，而非函数。
// 返回长度的单位是字节，该长度属于size_t(size type)类型



//2.3 实型/浮点型
//1.单精度float-4bit-7位有效数字
float f1 = 3.14f; //一般后面要带f，否则会识别成double

//2.双精度double-8bit-15～16位
double d1 = 3.14159265;
//但默认情况下，输出的小数都是6位

//3.科学计数法
float f2 =3e2; //3*10^2
float f3 =3e-2; //3*0.1^2


//2.4 字符型——用于表示单个字符

//语法： 
char ch = 'a';
/*
1.不是把字符本身存储，而是存储其ASCII编码
2.占1bit
3.常见错误*/
char ch2 = "b";  //需要单引号
char ch3 = 'dadw';  //引号内只能有1个字符
//4.对应ASCII编码
cout<< (int)ch << endl;  //a-97,b-98.....,A-65...


//2.5 转义字符
/*
\n  换行符
\\  反斜杠
\t  水平制表符——将不足8bit的补足，使输出更美观
*/
cout << "hello world\n";
cout << "\\";
cout << "aaa\thelloworld";
cout << "a\thelloworld";
cout << "aaaaa\thelloworld";


//2.6 字符串型
//1.c风格
char str1[] = "helloworld";
//2.c++风格
#include<string>
string str2 = "helloworld";


//2.7 布尔型bool-占1bit
//true-1
//false-0,只有0为false，其他都为真
bool flag = true;
flag = false;


//2.8 数据的输入——从键盘获取数据
//需要先初始化变量
//cin >> 变量
int a = 0;
cout << "请输入一个整型" << endl;
cin >> a;
cout << a <<endl;






















