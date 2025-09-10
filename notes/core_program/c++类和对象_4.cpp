//// 4. 类和对象 ////
//类是具有相同性质的对象的集合
//c++面对对象3大特征：封装，继承，多态

#include <iostream>
#include <cmath>
using namespace std;

//4.1 封装

//4.1.1 封装的意义
//1. 将属性和行为作为一个整体（类），表现生活中的事物
//属性和行为一般同时存在

//e.g.1:设计一个圆类，求圆的周长
//公式：2*pi*r(r是属性)
class Circle{
    //访问权限
    //公共权限
public:

    //属性
    int m_r;

    //行为(函数)
    //获取圆周长
    double calculate_pem()
    {
        return 2*M_PI*m_r;  //使用cmath里的M_PI
    }
};
//类中的属性和行为统称成员
//属性/成员属性/成员变量
//行为/成员函数/成员方法

int main(){
    //实例化
    //通过圆类，创建具体的对象
    Circle cl;
    //给对象的属性赋值
    cl.m_r = 10;
    cout << "圆的周长为：" << cl.calculate_pem() << endl;
}


//e.g.2:设计一个学生类，属性有姓名，学号，能给属性赋值并显示
class Student{
    //访问权限
public:

    //属性
    string m_name;
    string m_number;

    //行为
    // string namStudent(){
    //     // cout << "学生姓名： " << m_name << "\t";
    //     // cout << "学生学号： " << m_number << "\t";
    //     return m_name;
    // }
    // string numStudent(){
    //     return m_number;
    // }
    void msgStudent(){
        cout << "学生姓名： " << m_name << "\t";
        cout << "学生学号： " << m_number << "\t";
    }
    //赋值行为
    void setid(string id){
        m_number = id;
    }
};

int main(){
    //实例化
    Student stu;
    //赋值给属性
    stu.m_name = "小丽";
    stu.m_number = "120453";
    // cout << stu.msgStudent() << endl;   //不能输出一个没有返回的函数
    // cout << "学生姓名： " << stu.namStudent() << "\t";
    // cout << "学生学号： " << stu.numStudent() << "\t";   
    stu.msgStudent();   //可以直接调用
    system("pause");
    return 0;
}


//意义2. 设计类时，可以把属性和行为放在不同的权限下来控制
/*3种权限
公共权限 public     成员类内可访问，类外也可以访问
保护权限 protected  类内可访问，类外不可访问    子类可以访问
私有权限 private    类内可访问，类外不可访问    子类不可访问
*/

class Person{
public:
    string m_name;

protected:
    string m_car;

private:
    int m_password;

public:
    void func(int m_password){
        m_password = 12345;
    }
};

int main(){
    Person per;
    per.m_car = "宝马";
}


//4.1.2 struct和class的区别
//唯一区别是默认的访问权限不同
//struct默认权限是公有public
//class默认权限是私有private

class Cl{
    int m_A;
};

struct St{
    int m_A;
};

int main(){
    Cl cl;
    St st;
    cl.m_A = 100;
    st.m_A = 

}





