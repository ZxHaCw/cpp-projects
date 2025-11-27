#include<iostream>
using namespace std;

//定义一个人类
//成员属性有 姓名 年龄 爱豆
class Person
{
    public:
    //设置姓名
    void setName(string name)
    {
        m_Name = name;
    }
    // 获取姓名
    string getName()
    {
        return m_Name;
    }

    // 设置年龄
    void setAge(int age)
    {
        if(age < 0 || age > 150)
        {
            cout << "输入的年龄不合规，保存失败！" << endl;
        }
        m_Age = age;
    }
    // 获取年龄
    int getAge()
    {
        return m_Age;
    }

    // 设置爱豆
    void setIdol(string idol)
    {
        m_Idol = idol;
    }

      private : 
      string m_Name;
      int m_Age;
      string m_Idol;
};

int main()
{
    Person p;
    p.setName("张三");
    p.setAge(18);
    p.setIdol("李四");

    return 0;
}