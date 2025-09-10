#include <cstddef>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Student{
    //访问权限
public:

    //属性
    string m_name;
    string m_number;

    //行为
    string namStudent(){
        // cout << "学生姓名： " << m_name << "\t";
        // cout << "学生学号： " << m_number << "\t";
        return m_name;
    }
    string numStudent(){
        return m_number;
    }

};

int main(){
    //实例化
    Student stu;
    //赋值给属性
    stu.m_name = "小丽";
    stu.m_number = "120453";
    // cout << stu.msgStudent() << endl;   //不能输出一个没有返回的函数
    cout << "学生姓名： " << stu.namStudent() << "\t";
    cout << "学生学号： " << stu.numStudent() << "\t";

    system("pause");
    return 0;
}