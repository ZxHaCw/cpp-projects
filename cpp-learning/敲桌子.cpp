#include<iostream>
using namespace std;

int main()
{
    //敲桌子案例
    for (int i = 1; i <= 100; i++)
    {
        //如果是7的倍数，个位有7或者十位有7，就打印敲桌子
        if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
        {
            cout << "敲桌子" << endl;
        }
        else
        {
            //如果不是特殊数字，就打印它
            cout << i << endl;
        }
    }
}