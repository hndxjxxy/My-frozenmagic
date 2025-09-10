//// 7. 指针 ////
//记录地址编号，可以通过指针直接访问内存，就是一个地址

#include<iostream>
using namespace std;
int main(){


//7.1 定义指针
//数据类型 * 指针变量名；
int a = 10;
int * p;
p = &a; //用指针p记录a的地址
cout << "a的地址" << &a<<endl;
cout << "指针p为:" << p << endl;
 


//7.2 使用指针
//通过解引用找到指针的内存，即*p
//*和&都有点像负号，只是指针只用*，变量只用&
*p = 1000;



//7.3 指针所占内存空间
//32位系统-4bit
//64位系统-8bit
int  * q = &a;
cout << sizeof(p) << endl;
cout << sizeof(int *) << endl;
cout << sizeof(float *) << endl;
cout << sizeof(double *) << endl;
cout << sizeof(char *) << endl;
//输出都是8



//7.4 空指针&野指针
//7.4.1 空指针——指向内存中编号为0的空间

//1.初始化指针变量。一开始不确定指向哪里
//2.*空指针无法访问
int  * p1 = NULL;

//会报错没有修改权限，因为0～255的空间是系统占用的
* p1 = 100;  
cout << *p1 << endl;


//7.4.2 野指针——指针变量指向非法的内存
int * p2 = (int *)0x1100;
cout << *p2 << endl;
//应避免在程序中出现


//7.5 const修饰指针
//1. 常量指针——指针指向可改，但指针指向值不可改
//a = 10
int b = 10;
const int * p3 = &a;
*p3 = 20;  
p3 = &b;

//2. 指针常量——指针的值可改，但指针指向不可改
//const后跟着变量
//a = 10
int * const p4 = &a;
*p4 = 20;
p4 = &b;  

//3. 修饰指针——指针指向和指针的值都不可改
const int * const p5 = &a;
*p5 = 20;
p5 = &b;


//7.6 指针和数组——利用指针访问数组中的元素

int arr[10] = {1,2,3,4,5,6,7,8,9,10};
int * q1 = arr; //数组名就是数组的首地址
cout << * q1  << endl;
q1++;
cout << "用指针访问第2个元素" << *q1 << endl;
//用指针遍历输出元素
int  * q2 = arr;
for(int i = 0;i < 10;i++){
    q2++;
    cout << "用指针访问第i个元素" << *q2 << endl;
}


//7.7 指针和函数——指针作为函数的形参
//1. 值传递：形参无法改变实参
void swap(int a,int b){
    int temp = a
    a = b;
    b = temp;
    cout << a << b <<endl;  //a=20,b=10
}
int mian(){
    int a = 10;
    int b = 20;
    swap(a,b);
    cout << a << b <<endl;  //a=10,b=20
}

//2.地址传递
void swap(int * q3,int * q4){
    int temp = *q3;
    *q3 = *q4;
    *q4 = temp;
}
int main(){
    int a = 10;
    int b = 20;
    swap(&a,&b);
    cout << a << b <<endl;  //a=20,b=10
}


//7.8 指针，数组，函数
//封装一个函数，利用冒泡排序实现对整数型的升序排序
void bubbleSort(int * arr,int len){ //int * arr=int arr[]
    for(int i = 0;i < len-1;i++){
        for(int j = 0;j < len-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(int * arr,int len){
    for(int i = 0;i< len;i++){
        cout << arr[i] << endl;
    }
}

int arr0[9] = {2,9,4,7,3,1,6,5,8};
int len = sizeof(arr)/sizeof(arr[0]);
int main(){
    bubbleSort(arr,len);
    printArray(arr,len);
}




}