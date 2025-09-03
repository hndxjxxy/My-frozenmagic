/// 4. 程序流程结构 ///
//顺序结构，选择～，循环～
#include<iostream>
#include<cmath>

using namespace std;
int main()
{

//4.1 选择结构
//4.1.1 if语句（单行，多行，多条件）
//1.单行if
int score = 0;
//if条件后不能加分号
if (score > 600){
    cout << "....." << endl;
}

//2.多行if
if (score > 600){
    cout << "...." <<endl;
}
else{
    cout <<",,,,"<<endl;
}

//3.多条件if
if (score > 600){
    cout << "...." << endl;
}
else if(score > 500){
    cout << ",,,," << endl;
}
else{
    cout << "````" << endl;
}

//4.嵌套if（可达到更精确的细分条件）
//>600一本,>650清华,>700北大，其余人大
if(score > 600){
    cout << "...." << endl;
    if(score >700){
        cout << "考上北大" << endl;
    }
    else if(score >650){
        cout <<"考上清华" <<endl;
    }
}
else if(score > 500){
    cout << ",,,," << endl;
}

//案例：有abc3个数，找到最大值
int a = 0;
int b = 0;
int c = 0;
cin >> a;
cin >> b;
cin >> c;
if(a > b){
    if(a > c){
        cout << "max=a" << endl;
    }
    else{
        cout << "max=c" <<endl;
    }
}
else{
    if(b > c){
        cout << "max=b" << endl;
    }
    else{
        cout << "max=c" << endl;
    }
}


//4.1.2 三目运算符
//有def，de比较，更大的赋值给f
int d = 10;
int e = 5;
int f = 0;

f = (d > e ? d : e);    //顺延判断，先判断a>b，那么a，否则b
//而且得到的f是变量，可以继续赋值
f = (d > e ? d : e)=100;    //f=100


//4.1.3 switch语句——用于执行多分支语句
//电影打分，10～9,8～7,6～5,<5
int scale = 0;
cin >> scale;
switch(scale)
{
    case 10:
    cout << "经典" << endl;
    break;  //退出当前分支
    case 9:
    //...
    break;
    //.....
    default :   //相当于else
    //...
}
    //if & switch的主要区别是，switch的条件只能是int/char
    //优点是执行效率高


///4.2 循环结构
//4.2.1 while循环
//打印0～9
int num = 0;
while(num < 10){        //while(1),避免死循环
    cout << num << endl;
    num++;
}

//案例：猜数字，随即生成0～100的数，未猜中系统提示过大/过小，直到猜中
int num1 = rand()%101;  //rand是随即生成函数，%代表生成范围
int num2 = 0;
cin >> num2;
while(num2 != num1){
    if(num2 < num1){
        cout << "生成数大于输入数,请重新输入" << endl;
    }
    else{
        cout << "生成数小于输入数,请重新输入" << endl;
    }
    cin >> num2;
}
cout << "芜湖，猜中了" << endl;     //也可以用break退出循环


//4.2.2 do...while循环
// 先执行循环语句一次，再判断是否满足条件
//打印0～9返场
do{
    cout << num << endl;
    num++;
}
while(num < 10);


///案例：水仙花数///
//水仙花数：每位数的3次幂值之和等于它本身，用do...while求出所有3位水仙花数
//使用pow函数记得#include<cmath>
int num3 = 100;
int sum = 0;
do{
    sum = pow(num3%10,3)+pow((num3/10)%10,3)+pow(num3/100,3);
    if (sum == num3){
        cout << "找到一个水仙花数：" << num3 << endl;
    }
    num3++;
}
while(num3 < 1000);



//4.2.3 for循环
//循环打印0～9
//创建变量初始条件+循环条件+末尾结束语句
//执行顺序：初始条件-循环条件-循环语句-结束语句-循环条件-...
for(int i = 0;i < 10;i++){
    cout << i << endl;
}

//案例：从0～100报数，数到包含7或者是7的倍数的数字，敲桌子
for(int num4 = 0;num4 < 101;num4++)
{
    if (num4%10==7){
        cout << "敲桌子" << endl;
    }
    else if (num4/10==7){
        cout << "敲桌子" << endl;
    }
    else if (num4%7==0){
        cout << "敲桌子" << endl;
    }
    else{
        cout << num4 << endl;
    }
}


//4.2.4 嵌套循环
//打印*形图
int n = 10;
for(int l = 1;n >= l;l++)
{
    for(int h = 1;n >= h;h++){
        cout << "* " ;
    }
    //cout <<""<<endl;
    cout << endl;
}
// int n = 10;
// for(int i = 1;n >= i;i++)
// {
//     for(int i = 1;n >= i;i++){
//内外循环都用i不影响，外层走一步，内层走一周
//         cout << "* " ;
//     }
//     //cout <<""<<endl;
//     cout << endl;
// }

//99乘法表
int n1 = 9;
for(int i= 1;n1 >= i;i++)
{
    for(int j = 1;n1 >= j;j++){
        cout << i <<"x"<< j << "=" << i*j <<" \t" ;
    }
    cout << endl;
}
//阶梯形
// for(int i= 1;n1 >= i;i++)
// {
//     for(int j = 1;i >= j;j++){
//         cout << i <<"x"<< j << "=" << i*j <<" \t" ;
//     }
//     cout << endl;
// }


///4.3 跳转语句
//4.3.1 break
//跳出选择结构——switch,在4.1.3中有示例
//跳出循环结构
for(int i = 0;i < 10;i++){
    if (i==5){
        break;
    }
    cout << i << endl;
}
//跳出嵌套循环的内外层
for(int l = 1;n >= l;l++)
{
    for(int h = 1;n >= h;h++){
        cout << "* " ;
        if (h==5){
            break;
        }
    }
    cout << endl;
}


//4.3.2 continue——跳过本次循环中未执行的语句，直接执行下一次循环
//输出0～100的奇数
for(int i = 0; i <= 100; i++)
{
    if(i%2 == 0)    //0,2,4...
    {
        continue;   //可筛选条件，break直接退出循环
    }
    else {
        cout << i << endl;
    }
}


//4.3.3 goto——无条件跳转代码
cout << "1.xxx" << endl;
cout << "2.xxx" << endl;
goto FLAG;  //跳转的标记一般全大写
cout << "3.xxx" << endl;
cout << "4.xxx" << endl;
FLAG:   //标记后加冒号
cout << "5.xxx" << endl;



























    system("pause");
    return 0;

}