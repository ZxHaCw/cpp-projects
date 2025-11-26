#include<iostream>
using namespace std;
#include<ctime>


int main()
{
    cout << "欢迎您玩“猜数字”小游戏" << endl;
    cout << "请输入任意数字以开始" << endl;

    srand((signed int)time(NULL));

    int num = rand() % 100 +1;

    int guess = 0;

    while(true)
    {
        cin >> guess;
        if(guess == num)
        {
            cout << "恭喜你猜对了！" << endl;
            break;
        }
        else if(guess > num)
        {
            cout << "猜大了！" << endl;
        }
        else if(guess < num)
        {
            cout << "猜小了" << endl;
        }
    }
    
    return 0;
}