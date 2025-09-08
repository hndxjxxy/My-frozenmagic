//// 8. 结构体 ////
//结构体属于自定义数据类型，允许用户储存不同的数据类型
#include <iostream>
#include <string>
using namespace std;

int main(){
//8.1 结构体的定义与使用
//1. 定义
struct Student{
    //成员列表

    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
}s3;

//2. 创建具体学生

//2.1 struct Student s1
//可以忽略关键字struct
    struct Student s1;
    //给s1属性赋值
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;
    cout << "姓名： " << s1.name << "年龄： " << s1.age << "分数： " << s1.score << endl;

//2.2 struct Student s2 = {...}
    struct Student s2 = {"李四",19,80};

//2.3.创建结构体时同时赋值
    s3.name = "王五";
    s3.age = 20;
    s3.score = 60;
//注意前面跟在结构体后的变量


//8.2 结构体数组
//1. 定义结构体(上面已经定义)

//2. 创建结构体数组
struct Student stuArray[8] =
{
    {"张三",18,100},
    {"李四",28,99},
    {"王五",38,66}
};

//3. 给结构体数组中的元素赋值
stuArray[2].name = "赵六";
stuArray[2].age = 80;
stuArray[2].score = 60;

//4. 遍历结构体数组中的元素赋值
for (int i =0;i < 3;i++)
{
    cout << "姓名： " << stuArray[i].name 
         << "年龄： " << stuArray[i].age
         << "分数： " << stuArray[i].score << endl;
}



//8.3 结构体指针——通过指针访问结构体中的成员
struct Student * p = &s1;
//指针必须用箭头才能访问结构体中的属性
cout << p->age << p->name << p->score << endl;


//8.4 嵌套结构体
struct teacher
{
    int id; //工号
    string name;
    int age;
    struct Student stu; //负责的学生
};
//必须先定义里面的结构体

teacher t;
t.id = 100000;
t.name = "老王";
t.age = 50;
t.stu.name = "小王";
t.stu.age = 20;
t.stu.score = 60;


//8.5 结构体做函数参数

//1.值传递
void printStudent(struct Student s1)
{
    cout << s1.name << endl;
}

//2. 地址传递
void printStudent1(struct Student * p){
    cout << p->name << endl;
}
printStudent1(&s1);     //这句写在main函数中



//8.6 结构体中const的使用场景
//使用const来防止误操作
struct Student s5 = {"张三",15,70};
void printStudent(Student s5)   //值传递，每调用一个数据就会复制一次所有数据
{

}
void printStudent(const Student *s5)   //所以改为指针节省内存。但是有可能会改变原结构体数据
{
    //所以要加上const，原数据就无法修改了
}


//案例1：学校做毕设项目，每名老师带领5名学生，总共有3名老师
//要设计学生和老师的结构体，老师的结构体包含老师姓名和学生数组
// 学生数组有姓名，考试分数。要求通过函数给老师及所带学生赋值，打印所有数据
struct student{
    string name;
    int score;
};
struct tenure
{
    string name;
    struct student p2[5];
};
void data(tenure p1[],int len)
{
    string nameSeed = "ABCDE";
    for(int i = 0;i<len ;i++)
    {
        p1[i].name = "Tenure_";
        p1[i].name += nameSeed[i];  //可以看成单个的char

        //给每个老师带的学生赋值
        for(int j = 0;j < 5;j++)
        {
            p1[i].p2[j].name = "Student_";
            p1[i].p2[j].name += nameSeed[j];
            int random = rand() %61+40;
            p1[i].p2[j].score = random;
        }
    }
}
void print(tenure p1[],int len)
{
    for(int i = 0;i<len;i++)
    {
        cout<< " 老师姓名：" << p1[i].name << endl;
        for(int j = 0;j <5;j++)
        {
            cout << "\t学生姓名：" << p1[i].p2[j].name << 
            "\t考试成绩"<< p1[i].p2[j].score <<endl;
        }
        
    }
}

int main(){
    //随机数种子
    srand((unsigned int)time(NULL));
    struct tenure p1[3];
    int len = sizeof(p1)/sizeof(p1[0]);
    data(p1,3);
    print(p1,3);
    system("pause");
    return 0;
}


//案例2：创建一个英雄的结构体，按英雄年龄冒泡排序并重新打印
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