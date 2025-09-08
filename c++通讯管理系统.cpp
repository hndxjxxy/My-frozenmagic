//封装函数显示界面showMenu()
#include <cstdlib>
#include<iostream>
#include<string>
#define Max 1000
using namespace std;


struct person
{
    string name;
    int sex;  //男1,女2
    int age;
    string phone;
    string addr;
};

struct addressBooks
{
    struct person[Max];
    int size;
};


//菜单界面
void showMenu()
{
    cout << "**********************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "**********************" << endl;

}

//添加联系人函数
void addPerson(addressBooks * abs)
{
    //检查通讯录是否已满
    if (abs->size == Max)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    } 
    //添加联系人
    else 
    {
        string Name;
        cout << "请输入姓名：" << endl;
        cin >> Name;
        abs->person[abs->size].name = Name
    }
}


int main()
{
    //创建通讯录结构体变量
    addressBooks abs;
    //变量初始化当前人员数
    abs.size = 0;

    int select = 0; //初始化用户输入变量

    while(true)
    {
        //菜单调用
        showMenu();

        cin >> select;
        switch (select)
        {
            case 1:     //添加联系人
                addPerson(&abs);
                break;
            case 2:     //显示联系人
                break;
            case 3:     //删除联系人
                break;
            case 4:     //查找联系人
            break;
            case 5:     //修改联系人
            break;
            case 6:     //清空联系人
            break;
            case 0:     //退出通讯录
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break;
            default:
            break;
            
        }
    }
    
    system("pause");
    return 0;
}