#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
using namespace std;


using namespace std;
int main()
{
int a[]={1,2,5,4,3,5,2,1,3,1,4,3,3,3,2,3,3,2,2,5};//给出一堆数，但不知道多少个
int b[6]={0};//将b数组中所有数初始化为0
for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)//这里把a数组中的个数给表示出来了
++b[a[i]];
for(int i=1;i<6;i++)
cout<<i<<" "<<b[i]<<endl;
}

