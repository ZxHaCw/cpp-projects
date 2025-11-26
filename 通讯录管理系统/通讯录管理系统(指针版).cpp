#include<iostream>
using namespace std;
#include<string>
#define MAX 500

//创建联系人结构体
struct Person
{
    //姓名
    string p_Name;
    //性别
    int p_Sex;
    //年龄
    int p_Age;
    //电话号码
    string p_Num;
    //住址
    string p_Addr;
};

//建立通讯录结构体
struct Addressbooks 
{
    //创建联系人数组
    Person personArray[MAX];

    //记录联系人个数等相关操作
    int p_Size;
};

//封装添加联系人的函数
void addPerson(Addressbooks *abs)
{
    if(abs->p_Size == MAX)
    {
        cout << "通讯录已满，不可添加！" << endl;
        return;
    }
    else
    {
        // 添加姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;

        abs->personArray[abs->p_Size].p_Name = name;

        //添加性别
        int sex = 0;
        cout <<"请输入性别" << endl;
        cout << "1 -- 男   2 -- 女" << endl;
        while(true)
        {
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[abs->p_Size].p_Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新填写！" << endl;
            }
        }

        //添加年龄
        int age;
        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personArray[abs->p_Size].p_Age = age;

        //添加电话号码
        string num;
        cout << "请输入电话号码" << endl;
        cin >> num;
        abs->personArray[abs->p_Size].p_Num = num;

        //添加地址
        string addr;
        cout << "请输入家庭住址" << endl;
        cin >> addr;
        abs->personArray[abs->p_Size].p_Addr = addr;
    }
    abs->p_Size++;//更新通讯录人数

    system("pause");
    system("cls");
}

//封装显示联系人函数
void showPerson(Addressbooks *abs)
{
    if(abs->p_Size == 0)
    {
        cout << "通讯录目前还未添加联系人！" << endl;
    }
    else
    {
        for (int i = 0; i < abs->p_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].p_Name << "\t\t";
            cout << "性别：" << (abs->personArray[i].p_Sex == 1 ? "男" : "女") << "\t\t";
            cout << "年龄：" << abs->personArray[i].p_Age << "\t\t";
            cout << "电话号码：" << abs->personArray[i].p_Num << "\t\t";
            cout << "家庭住址：" << abs->personArray[i].p_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

//封装判断联系人是否存在的函数
int isExsit(Addressbooks *abs,string name)
{
    for (int i = 0; i < abs->p_Size; i++)
    {
        if(name == abs->personArray[i].p_Name)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}

//封装修改联系人的函数
void modifyPerson(Addressbooks *abs)
{
    string name;
    cout << "请输入要修改的联系人姓名" << endl;
    cin >> name;

    int ret = isExsit(abs, name);
    
    if(ret != -1)
    {
        //修改姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[ret].p_Name = name;

        //修改性别
        int sex = 0;
        cout << "请输入性别" << endl;

        while(true)
        {
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs->personArray[ret].p_Sex = sex;
                break;
            }
            else
            {
                cout << "请输入正确的格式！" << endl;
            }
        }

        // 修改年龄
        int age;
        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personArray[ret].p_Age = age;

        //修改电话
        string num;
        cout << "请输入电话号码" << endl;
        cin >> num;
        abs->personArray[ret].p_Num = num;

        //修改住址
        string addr;
        cout << "请输入家庭住址" << endl;
        cin >> addr;
        abs->personArray[ret].p_Addr = addr;

        cout << "修改成功，已保存！" << endl;
    }
    else
    {
        cout << "您未添加联系人！" << endl;
    }
    system("pause");
    system("cls");
}

//封装查找联系人的函数
void findPeson(Addressbooks *abs)
{
    string name;
    cout << "请输入要查找的联系人的姓名" << endl;
    cin >> name;

    // 先判断联系人是否存在
    int ret = isExsit(abs, name);
    if (ret != -1)
    {
        
        cout << "姓名：" << abs->personArray[ret].p_Name << "\t\t";
        cout << "性别：" << abs->personArray[ret].p_Sex << "\t\t";
        cout << "年龄：" << abs->personArray[ret].p_Age << "\t\t";
        cout << "电话号码：" << abs->personArray[ret].p_Num << "\t\t";
        cout << "家庭住址：" << abs->personArray[ret].p_Addr << endl;
    }
    else
    {
        cout << "您未添加该联系人" << endl;
    }
    system("pause");
    system("cls");
}

//封装删除联系人的函数
void deletePerson(Addressbooks *abs)
{
    string name;
    cout << "请输入要删除的联系人姓名" << endl;
    cin >> name;

    int ret = isExsit(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->p_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
            abs->p_Size--;
        }
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "您的通讯录里没有此人！" << endl;
    }
    system("pause");
    system("cls");
}

//封装清空通讯录函数
void cleanPerson(Addressbooks *abs)
{
    cout << "确定要清空通讯录？" << endl;
    cout << "是请按 1   取消请按 2" << endl;
    int confirmation = 0;
    cin >> confirmation;
    
    //判断用户输入的指令是否正确
    while(true)
    {
        if(confirmation == 1)
        {
            abs->p_Size = 0;
            cout << "通讯录已清空！" << endl;
            break;
        }
        else if(confirmation == 2)
        {
            system("pause");
            system("cls");
            break;
        }
       else
        {
            cout << "请输入有效数字！" << endl;
        }
    }
    system("pause");
    system("cls");
}

//封装显示菜单函数
void showMenu()
{
    cout << "***************************" << endl;
    cout << "****** 1、添加联系人 ******" << endl;
    cout << "****** 2、显示联系人 ******" << endl;
    cout << "****** 3、修改联系人 ******" << endl;
    cout << "****** 4、查找联系人 ******" << endl;
    cout << "****** 5、删除联系人 ******" << endl;
    cout << "****** 6、清空通讯录 ******" << endl;
    cout << "****** 0、退出通讯录 ******" << endl;
    cout << "***************************" << endl;
}



int main()
{
    //创建一个通讯录
    Addressbooks abs;
    abs.p_Size = 0;

    while(true)
    {
        //调用显示菜单函数
        showMenu();

        //创建用户输入的接受变量
        int select = 0;
        cin >> select;

        switch(select)
        {
           case 1://添加联系人
               addPerson(&abs);
               break;

            case 2://显示联系人
                showPerson(&abs);
                break;

            case 3://修改联系人
                modifyPerson(&abs);
                break;

            case 4://查找联系人
                findPeson(&abs);
                break;

            case 5://删除联系人
                deletePerson(&abs);
                break;

            case 6://清空通讯录
                cleanPerson(&abs);
                break;

            case 0://退出通讯录
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