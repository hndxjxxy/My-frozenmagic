//封装函数显示界面showMenu()
#include <cstdlib>
#include<iostream>
#include<string>
#define Max 1000
using namespace std;


struct person
{
    string m_name;
    int m_sex;  //男1,女2
    int m_age;
    string m_phone;
    string m_addr;
};

struct addressBooks
{
    struct person person[Max];  //或者更简洁的person person[Max]
    //struct person才是一个完整的类型名
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

//1.添加联系人函数
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
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->person[abs->size].m_name = name;
        
        //性别
        cout << "请输入性别： " << endl;
        cout << "1 —— 男" << endl;
        cout << "2 —— 女" << endl;
        int sex = 0;
        cin >> sex;

        while (true)
        {
            //如果输入1||2,可以退出循环
            if (sex==1 || sex==2)
            {
                abs->person[abs->size].m_sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        
        //年龄
        cout << "请输入年龄： " << endl;
        int age = 0;
        cin >> age;
        abs->person[abs->size].m_age = age;

        //联系电话
        cout << "请输入电话： " << endl;
        string phone;
        cin >> phone;
        abs->person[abs->size].m_phone = phone;

        //家庭住址
        cout << "请输入家庭住址： " << endl;
        string address;
        cin >> address;
        abs->person[abs->size].m_addr = address; 

        //更新通讯录人数
        abs->size++;

        cout << "添加联系人成功！" << endl;
               
        system("pause");//按任意建继续
        system("cls");//清屏操作
    }
}


//2.显示联系人
void showPerson(addressBooks * abs){
    //判断通讯录中人数是否为0
    if (abs->size == 0){
        cout << "当前没有联系人" << endl;
    }
    //若人数不为0,显示联系人
    else{
        for (int i = 0;i < abs->size;i++){
            cout << "姓名： " << abs->person[i].m_name 
                 << "\t性别: " << (abs->person[i].m_sex == 1 ? "男":"女")
                 << "\t年龄: " << abs->person[i].m_age
                 << "\t电话: " << abs->person[i].m_phone
                 << "\t住址: " << abs->person[i].m_addr <<endl;
            // cout << "姓名： " << abs->person[i].m_name << "\t";
            // cout << "\t性别: " << abs->person[i].m_sex << "\t";
            // cout << "\t年龄: " << abs->person[i].m_age << "\t";
            // cout << "\t电话: " << abs->person[i].m_phone << "\t";
            // cout << "\t住址: " << abs->person[i].m_addr <<endl;
        }
        cout << "共有" << abs->size << "个联系人" << endl;
    }
    system("pause");
    system("cls");
}


//3.删除联系人
//先查找联系人,返回具体位置，不存在返回-1
//传入参数：通讯录，需要查找的名字
int isExist(addressBooks * abs,string name){
    for (int i = 0;i < abs->size;i++)
    {
        if (abs->person[i].m_name == name){
            return i;
        }
    }
    return -1;
}

void deletePerson(addressBooks * abs)
{
    cout << "请输入要删除的联系人： " << endl;

    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1){
        //需要前移删除联系人后面的数据
        for (int i = ret;i < abs->size;i++){
            abs->person[i] = abs->person[i+1];
        }
        abs->size--;
        cout << "删除成功" << endl;
    }
    else{
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}


//4.查找联系人
void findPerson(addressBooks * abs){
    cout << "请输入要查找的联系人： " << endl;
    string name;
    cin >> name;

    //通过已经定义的函数isExist查找
    int ret = isExist(abs,name);
    if(ret != -1){
        cout << "姓名： " << abs->person[ret].m_name << "\t";
        cout << "性别: " << abs->person[ret].m_sex << "\t";
        cout << "年龄: " << abs->person[ret].m_age << "\t";
        cout << "电话: " << abs->person[ret].m_phone << "\t";
        cout << "住址: " << abs->person[ret].m_addr <<endl;

    }
    else{
        cout << "查无此人" << endl;
    }
}


//5.修改联系人
//显示联系人信息
void showMassage()
{
    cout << "******************" << endl;
    cout << "***** 1.姓名 *****" << endl;
    cout << "***** 2.性别 *****" << endl;
    cout << "***** 3.年龄 *****" << endl;
    cout << "***** 4.电话 *****" << endl;
    cout << "***** 5.住址 *****" << endl;
    cout << "******************" << endl;

}

void modifyPerson(addressBooks * abs){
    cout << "请输入要修改的联系人： " << endl;
    string name;
    cin >> name;

    int ret = isExist(abs,name);    //找到指定联系人
    if(ret != -1){
        showMassage();
        cout << "请选择需要修改的信息： " << endl;
        int n = 0;
        cin >> n;

        switch (n){
            case 1:
            int choise = 0;
            // cout << "是否确定修改？" << endl;
            // cout << "1——是" << endl;
            // cout << "0——否" << endl;
            // cin >> choise;
            // if (choise){
            //     goto 
            // }
            

        };

    }
    else{
        cout << "查无此人" << endl;
    }
}


//6.清空联系人
//令size=0,做逻辑清空，让客户访问不到即可
void clean(addressBooks*abs){
    abs->size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
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
                showPerson(&abs);
                break;
            case 3:     //删除联系人
                // {
                // cout << "请输入删除联系人姓名： " << endl;
                // string name;
                // cin >> name;

                // if (isExist(&abs, name) == -1){
                //     cout << "查无此人" << endl;
                // }
                // else{
                //     cout << "找到此人" <<endl;
                // }
                // }在switch中，中间代码不能太长，
                // 要用一组括号括起来变成一个代码段，否则会报错
                break;
            case 4:
                findPerson(&abs);    //查找联系人
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