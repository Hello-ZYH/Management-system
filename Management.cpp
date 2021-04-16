#include<iostream>
#include<string>
#define MAX 1000
using namespace std;


//��ϵ�˽ṹ��
struct Person
{
    //����
    string m_Name;

    //�Ա�   1 ��    2 Ů
    int m_Sex;

    //����
    int m_Age;

    //�绰
    string m_Phone;

    //סַ
    string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
    //��ϵ������
    struct Person personArray[MAX];

    //��ϵ�˸���
    int m_Size;
};


void AddPerson(Addressbooks* abs);                              //1.�����ϵ��
void ShowPerson(Addressbooks* abs);                            //2.��ʾ������ϵ��
void DeletePerson(Addressbooks* abs);                          //3.ɾ����ϵ��
void FindPerson(Addressbooks* abs);                             //4.������ϵ��
void ModifyPerson(Addressbooks* abs);                        //5.�޸���ϵ����Ϣ
void CleanPerson(Addressbooks* abs);                          //6.�����ϵ��
void ShowMenu();                                                           //�˵�����
int IsExist(Addressbooks* abs, string name);                  //�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1





//1.�����ϵ��
void AddPerson(Addressbooks* abs)
{
    //�ж�ͨѶ¼������������˾Ͳ������
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }
    else
    {
        //�����ϵ��

        //����
        string name;
        cout << "������������ " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //�Ա�
        cout << "�������ձ� " << endl;
        cout << "1 --- ��" << endl;
        cout << "2 --- Ů" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;

            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }

        //����
        cout << "���������䣺 " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //�绰
        cout << "������绰�� " << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //סַ
        cout << "�������ַ�� " << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //����ͨѶ¼����
        abs->m_Size++;

        cout << "��ӳɹ�" << endl;

        system("cls");
    }
}





//2.��ʾ������ϵ��
void ShowPerson(Addressbooks * abs)
{
    //�ж�ͨѶ¼�е������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
    //�����Ϊ0����ʾ��¼����ϵ����Ϣ
    if (abs->m_Size == 0)
    {
        cout << "��ǰ��¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "������ " << abs->personArray[i].m_Name << "\t";
            cout << "�Ա� " << (abs->personArray[i].m_Sex == 1? "��":"Ů") << "\t";
            cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
            cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
            cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
            cout << endl;
        }

        system("pause");
        system("cls");
    }

}





//3.ɾ����ϵ��
void DeletePerson(Addressbooks* abs)
{
    cout << "��������Ҫɾ������ϵ������" << endl;

    string name;
    cin >> name;

    //ret == -1  δ�鵽
    //ret != -1    �鵽��
    int ret = IsExist(abs, name);

    if (ret != -1)
    {
        //�鵽���ˣ�����ɾ������
        for (int i = ret; i < abs->m_Size -1 ; i++)
        {
            //����ǰ��
            abs->personArray[i] = abs->personArray[i + 1];
            abs->m_Size--;
        }
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}





//4.������ϵ��
void FindPerson(Addressbooks* abs)
{
    cout << "��������Ҫ���ҵ���ϵ��" << endl;
    
    string name;
    cin >> name;

    int ret = IsExist(abs, name);

    if (ret != -1)  //�ҵ���ָ����ϵ��
    {
        cout << "������ " << abs->personArray[ret].m_Name << "\t";
        cout << "�Ա� " << (abs->personArray[ret].m_Sex == 1? "��":"Ů") << "\t";
        cout << "���䣺 " << abs->personArray[ret].m_Age << "\t";
        cout << "�绰�� " << abs->personArray[ret].m_Phone << "\t";
        cout << "סַ�� " << abs->personArray[ret].m_Addr << endl;
    }
    else //δ�ҵ�ָ����ϵ��
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}





//5.�޸���ϵ����Ϣ
void ModifyPerson(Addressbooks* abs)
{
    cout << "��������Ҫ�޸ĵ���ϵ��" << endl;

    string name;
    cin >> name;

    int ret = IsExist(abs, name);

    if (ret != -1)  //�ҵ���ָ����ϵ��
    {
        //����
        string Newname;
        cout << "������������ " << endl;
        cin >> Newname;
        abs->personArray[ret].m_Name = Newname;

        //�Ա�
        cout << "�������ձ� " << endl;
        cout << "1 --- ��" << endl;
        cout << "2 --- Ů" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;

            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }

        //����
        cout << "���������䣺 " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        //�绰
        cout << "������绰�� " << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //סַ
        cout << "�������ַ�� " << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "�޸ĳɹ�" << endl;
    }
    else //δ�ҵ�ָ����ϵ��
    {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}





//6.�����ϵ��
void CleanPerson(Addressbooks* abs)
{
    abs->m_Size = 0;  //����ǰ��¼����ϵ��������Ϊ0�����߼���ղ���
    cout << "ͨѶ¼�����" << endl;

    system("pause");
    system("cls");
}




//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int IsExist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        //�ҵ��û������������
        if (abs->personArray[i].m_Name == name)
        {
            return i;  //�ҵ��ˣ����ش����������е��±���
        }
    }

    //�������������û���ҵ��û���������-1
    return -1;

}





//�˵�����
void ShowMenu()
{
    cout << "*****************************" << endl;
    cout << "*****   1�������ϵ��   *****" << endl;
    cout << "*****   2����ʾ��ϵ��   *****" << endl;
    cout << "*****   3��ɾ����ϵ��   *****" << endl;
    cout << "*****   4��������ϵ��   *****" << endl;
    cout << "*****   5���޸���ϵ��   *****" << endl;
    cout << "*****   6�������ϵ��   *****" << endl;
    cout << "*****   0���˳�ͨѶ¼   *****" << endl;
    cout << "*****************************" << endl;
}





int main()
{
    //����ͨѶ¼�ṹ�����
    Addressbooks abs;

    //��ʼ��ͨѶ¼�е�����
    abs.m_Size = 0;

    int select = 0; // �����û�ѡ������ı���

    while (true)
    {

        //�˵�����
        ShowMenu();

        cin >> select;

        switch (select)
        {
        case 1:      //1�������ϵ��
            AddPerson(&abs);
            break;

        case 2:      //2����ʾ��ϵ��
            ShowPerson(&abs);
            break;

        case 3:      //3��ɾ����ϵ��
            DeletePerson(&abs);
            break;

        case 4:      //4��������ϵ��
            FindPerson(&abs);
            break;

        case 5:      //5���޸���ϵ��
            ModifyPerson(&abs);
            break;

        case 6:      //6�������ϵ��
            CleanPerson(&abs);
            break;

        case 0:      //0���˳�ͨѶ¼
            cout << "��ӭ�´�ʹ��" << endl;
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
