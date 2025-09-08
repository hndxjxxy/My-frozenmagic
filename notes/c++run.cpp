#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
using namespace std;

struct hero
{
    string name;
    int age;
};

void bubbleSort(struct hero[],int len)
{
    for(int i =0;i < len-1;i++)
    {
        for(int j = 0;j<len -i-1;j++)
        {
            if(hero[j].age>hero[j+1].age)
            {
                struct temp = hero[j];
                hero[j] = hero[j+1];
                hero[j+1] = temp;
            }
        }
    }
}

void print(struct hero[],int len)
{
    for(int i= 0;i<len;i++)
    {
        cout << "\t姓名：" << hero[i].name << 
            "\t年龄"<< hero[i].age <<endl;
    }
}

int main(){
    struct hero[5]=
    {
        {"刘备",23},
        {"关羽",22},
        {"张飞",20},
        {"赵云",21},
        {"貂蝉",19}
    };

    int len = sizeof(hero) / sizeof(hero[0]);
    bubbleSort(hero,len);
    print(hero,len);



    system("pause");
    return 0;
}

