/// 5. 数组 ///
//存放相同类型的数据元素
//要求内存连续

#include <cstdint>
#include<iostream>
#include<string>

using namespace std;
int main()
{

//5.1 一维数组——3种定义形式
//数组长度！=索引max
//5.1.1 定义方式
//1.数据类型 数组名[数组长度]；
int arr[5];
//通过索引赋值和引用
arr[0] = 10;
arr[1] = 20;
cout << arr[0] << endl;

//2.数据类型 数组命[数组长度] = {元素1,元素2，....}
int arr1[3] = {10,20,30};
//循环输出元素
for(int i = 0; i < 3; i++)
{
    cout << arr1[i] << endl;
}

//3. 数据类型 数组名[] = {元素1,元素2,...}
int arr2[] = {10,40,80,160};
//元素必须确定，决定数组长度


//5.1.2 一维数组数组名
//可以统计数组内存长度
sizeof(arr);
sizeof(arr[0]);
//可以获取数组在内存中的首地址
cout << arr <<endl;
cout << &arr[0] <<endl; //查看单个元素的内存地址
//数组名是常量，不能赋值


//案例1：查找最大元素并打印
int arr3[5] = {300,350,200,400,250};
int max = 0;
for(int i = 0;i<5;i++)
{
    if(max < arr3[i])
    {
        max = arr3[i];
    }
}
cout << max << endl;


//案例2：数组元素倒置
int arr4[5] = {5,6,8,7,9};
int start = 0;      //起始下标
int end = sizeof(arr4)/sizeof(arr4[0])-1;   //终止下标，由总长度/元素长度-1得到
while(start < end){         
    int temp = arr4[start];     //采用变量来暂存靠前的元素
    arr4[start] = arr4[end];
    arr4[end] = temp;
    start++;    //前后索引都开始往中间靠拢
    end--;
}
for(int i = 0;i<sizeof(arr4)/sizeof(arr4[0]);i++){
    cout << arr4[i];
}



//5.1.3 冒泡排序——最常用的排序算法
//对数组做升序排序，相邻两数做对比交换，对比次数为n-1
int arr5[8] = {5,3,8,6,9,7,2,4};
while(true){
    int i = 0;
    for(int n = 0;n<sizeof(arr5)/sizeof(arr5[0])-1;n++){
        if(arr5[n]>arr5[n+1]){
            int temp = arr5[n+1];
            arr5[n+1]=arr5[n];
            arr5[n]=temp;
            i++;
        }
    }
    for(int h = 0;h<sizeof(arr5)/sizeof(arr5[0]);h++){
        cout << arr5[h];    
    }
    cout << endl;
    if(i == 0){
        break;
    } 
}

//下面这个更简单
// int i = 0;
// for(int n = 0;n<sizeof(arr5)/sizeof(arr5[0])-1;n++){
//     for(int n =0;n<sizeof(arr5)/sizeof(arr5[0])-i-1;n++)
// {
//     if(arr5[n]>arr5[n+1]){
//             int temp = arr5[n+1];
//             arr5[n+1]=arr5[n];
//             arr5[n]=temp;
//         }
// }
// }    


///5.2 二维数组——矩阵
//5.2.1 定义方式
//1. 数据类型 数组名[行数][列数]；
int arr6[2][3];
arr6[0][0]=1;
arr6[0][1]=2;
arr6[0][2]=3;
arr6[1][0]=4;
arr6[1][1]=5;
arr6[1][2]=6;
//循环外层打印行数，内层打印列数
for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
        cout << arr6[i][j] << endl;
    }
}

//2. 数据类型 数组名[行数][列数] = { {元素1,元素2},{...,...},...}
int arr7[2][3] = 
{
    {1,2,3},
    {4,5,6}
};

//3. 数据类型 数组名[行数][列数] = {元素1,元素2,...}
int arr8[2][3] = {1,2,3,4,5,6};

//4. 数据类型 数组名[][列数] = {元素1,元素2,...}
int arr9[][3] = {1,2,3,4,5,6};


//5.2.2 二维数组名
//1.查看所占空间
cout << sizeof(arr7) << endl;
cout << sizeof(arr7[0]) << endl;    //查看首行占用空间
cout << sizeof(arr7[0])/sizeof(arr7[0][0]) << endl; //计算列元素个数，行数同理
//2.获取数组首地址
cout << arr7 << endl;
cout << (intptr_t)arr7[0] << endl;  //使用64位指针转换
//cout << (long)arr7[0] << endl;
cout << (intptr_t)arr7[1] << endl;
cout << (intptr_t)&arr7[0][0] << endl;  //第一个元素首地址


//案例：考试成绩统计
int score[3][3] = {
    {100,100,100},
    {90,50,100},
    {60,70,80}
};
string names[3] = {"张三","李四","王五"};   //c++使用字符串需要声明#include
for(int i = 0 ;i < 3;i++){
    int sum = 0;
    for (int j = 0;j <3;j++){
        sum += score[i][j];
        
    }
    cout << names[i] << "的总分是" << sum << endl;
}


//













































    system("pause");
    return 0;
}

