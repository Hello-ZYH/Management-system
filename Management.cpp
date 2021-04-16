#include<iostream>
#include<string>
#define MAX 1000
using namespace std;


//联系人结构体
struct Person
{
    //姓名
    string m_Name;

    //性别   1 男    2 女
    int m_Sex;

    //年龄
    int m_Age;

    //电话
    string m_Phone;

    //住址
    string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
    //联系人数组
    struct Person personArray[MAX];

    //联系人个数
    int m_Size;
};


void AddPerson(Addressbooks* abs);                              //1.添加联系人
void ShowPerson(Addressbooks* abs);                            //2.显示所有联系人
void DeletePerson(Addressbooks* abs);                          //3.删除联系人
void FindPerson(Addressbooks* abs);                             //4.查找联系人
void ModifyPerson(Addressbooks* abs);                        //5.修改联系人信息
void CleanPerson(Addressbooks* abs);                          //6.清空联系人
void ShowMenu();                                                           //菜单界面
int IsExist(Addressbooks* abs, string name);                  //检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1





//1.添加联系人
void AddPerson(Addressbooks* abs)
{
    //判断通讯录已满，如果满了就不再添加
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        //添加联系人

        //姓名
        string name;
        cout << "请输入姓名： " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //性别
        cout << "请输入姓别： " << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;

            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        //年龄
        cout << "请输入年龄： " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //电话
        cout << "请输入电话： " << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //住址
        cout << "请输入地址： " << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //更新通讯录人数
        abs->m_Size++;

        cout << "添加成功" << endl;

        system("cls");
    }
}





//2.显示所有联系人
void ShowPerson(Addressbooks * abs)
{
    //判断通讯录中的人数是否为0，如果为0，提示记录为空
    //如果不为0，显示记录的联系人信息
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名： " << abs->personArray[i].m_Name << "\t";
            cout << "性别： " << (abs->personArray[i].m_Sex == 1? "男":"女") << "\t";
            cout << "年龄： " << abs->personArray[i].m_Age << "\t";
            cout << "电话： " << abs->personArray[i].m_Phone << "\t";
            cout << "住址： " << abs->personArray[i].m_Addr << endl;
            cout << endl;
        }

        system("pause");
        system("cls");
    }

}





//3.删除联系人
void DeletePerson(Addressbooks* abs)
{
    cout << "请输入您要删除的联系人姓名" << endl;

    string name;
    cin >> name;

    //ret == -1  未查到
    //ret != -1    查到了
    int ret = IsExist(abs, name);

    if (ret != -1)
    {
        //查到此人，进行删除操作
        for (int i = ret; i < abs->m_Size -1 ; i++)
        {
            //数据前移
            abs->personArray[i] = abs->personArray[i + 1];
            abs->m_Size--;
        }
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}





//4.查找联系人
void FindPerson(Addressbooks* abs)
{
    cout << "请输入您要查找的联系人" << endl;
    
    string name;
    cin >> name;

    int ret = IsExist(abs, name);

    if (ret != -1)  //找到了指定联系人
    {
        cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
        cout << "性别： " << (abs->personArray[ret].m_Sex == 1? "男":"女") << "\t";
        cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
        cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
        cout << "住址： " << abs->personArray[ret].m_Addr << endl;
    }
    else //未找到指定联系人
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}





//5.修改联系人信息
void ModifyPerson(Addressbooks* abs)
{
    cout << "请输入您要修改的联系人" << endl;

    string name;
    cin >> name;

    int ret = IsExist(abs, name);

    if (ret != -1)  //找到了指定联系人
    {
        //姓名
        string Newname;
        cout << "请输入姓名： " << endl;
        cin >> Newname;
        abs->personArray[ret].m_Name = Newname;

        //性别
        cout << "请输入姓别： " << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;

            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        //年龄
        cout << "请输入年龄： " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //电话
        cout << "请输入电话： " << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //住址
        cout << "请输入地址： " << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "修改成功" << endl;
    }
    else //未找到指定联系人
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}





//6.清空联系人
void CleanPerson(Addressbooks* abs)
{
    abs->m_Size = 0;  //将当前记录的联系人数量记为0，做逻辑清空操作
    cout << "通讯录已清空" << endl;

    system("pause");
    system("cls");
}




//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int IsExist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        //找到用户输入的姓名了
        if (abs->personArray[i].m_Name == name)
        {
            return i;  //找到了，返回此人在数组中的下标编号
        }
    }

    //如果遍历结束都没有找到用户名，返回-1
    return -1;

}





//菜单界面
void ShowMenu()
{
    cout << "*****************************" << endl;
    cout << "*****   1、添加联系人   *****" << endl;
    cout << "*****   2、显示联系人   *****" << endl;
    cout << "*****   3、删除联系人   *****" << endl;
    cout << "*****   4、查找联系人   *****" << endl;
    cout << "*****   5、修改联系人   *****" << endl;
    cout << "*****   6、清空联系人   *****" << endl;
    cout << "*****   0、退出通讯录   *****" << endl;
    cout << "*****************************" << endl;
}





int main()
{
    //创建通讯录结构体变量
    Addressbooks abs;

    //初始化通讯录中的人数
    abs.m_Size = 0;

    int select = 0; // 创建用户选择输入的变量

    while (true)
    {

        //菜单调用
        ShowMenu();

        cin >> select;

        switch (select)
        {
        case 1:      //1、添加联系人
            AddPerson(&abs);
            break;

        case 2:      //2、显示联系人
            ShowPerson(&abs);
            break;

        case 3:      //3、删除联系人
            DeletePerson(&abs);
            break;

        case 4:      //4、查找联系人
            FindPerson(&abs);
            break;

        case 5:      //5、修改联系人
            ModifyPerson(&abs);
            break;

        case 6:      //6、清空联系人
            CleanPerson(&abs);
            break;

        case 0:      //0、退出通讯录
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
