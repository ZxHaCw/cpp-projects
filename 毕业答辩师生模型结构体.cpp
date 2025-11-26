#include <iostream>
using namespace std;
#include<string>
#include<ctime>

//项目描述：一名导师，带领五名学生，一共三名老师
//老师存放在同一数组之中
//要求老师要有姓名属性，学生要有姓名以及分数属性

struct Student
{
    //学生姓名
    string sName;

    // 学生分数
    int score;
};

struct Teacher
{
    //姓名
    string tName;
    //学生的数组
    Student sArray[5];
};

//定义一个给老师和学生赋值的函数
void allocateSpace(Teacher tArray[], int len)
{
     string nameSeed = "ABCDE";
    //外侧循环给老师赋值
    for (int i = 0; i < len; i++)
    {
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSeed[i];

        //内侧循环给学生赋值
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].sName = "Student_";
            tArray[i].sArray[j].sName += nameSeed[j];

            tArray[i].sArray[j].score = 60;
        }
    }
}

void printInfo(Teacher tArray[3], int len)
{
    //外侧打印老师的信息
    for (int i = 0; i < len; i++)
    {
        cout << "老师的姓名：" << tArray[i].tName << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生：" << tArray[i].sArray[j].sName
             << "\t" << "\t分数：" << tArray[i].sArray[j].score
             << endl;
        }
    }
}

int main()
{
    Teacher tArray[3];

    int len = sizeof(tArray) / sizeof(tArray[0]);

    //调用命名函数
    allocateSpace(tArray, len);

    //调用打印函数
    printInfo(tArray, len);

    return 0;
}
