#include<iostream>
using namespace std;

int main()
{
    //先打印100～999这些数字
    cout << "请输入100～999的任意数字" << endl;
    int num = 100;
    cin >> num;
    if(num<100)
    {
        cout << "请输入规定的数字！" << endl;
    }
    else if(num > 999)
    {
        cout << "请输入规定的数字" << endl;
    }

    do
    {
        int a = 0;//个位
        int b = 0;//十位
        int c = 0;//百位

        a = num % 10;//获取个位上的数字
        b = num / 10 % 10;//获取十位上的数字
        c = num / 100;//获取百位上的数字

        if(a*a*a+b*b*b+c*c*c == num)
        {
            cout << num << endl;
        }

        num++;

    } while (num < 1000);
}