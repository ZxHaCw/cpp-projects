#include<iostream>
using namespace std;
//案例描述：定义一个立方体类，成员属性包含长、宽、高
//分别设置立方体的长宽高成员函数
//计算立方体的面积、体积
//分别使用全局函数和成员函数来比较两个立方体是否相等

//定义一个立方体类
class Cube
{
    public:
    //设置长
    void setL(int l)
    {
        m_L = l;
    }
    //获取长
    int getL()
    {
        return m_L;
    }

    //设置宽
    void setW(int w)
    {
        m_W = w;
    }
    //获取宽
    int getW()
    {
        return m_W;
    }

    //设置高
    void setH(int h)
    {
        m_H = h;
    }
    //获取高
    int getH()
    {
        return m_H;
    }

    //创建成员函数计算面积
    int CalculateS()
    {
        return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
    }
    //创建成员函数计算体积
    int CalculateV()
    { 
        return m_L * m_W * m_H;
    }

    //创建两个立方体是否相等的成员函数
    bool isSeemByclass(Cube &c)
    {
        if(m_L == c.getL()  && m_W == c.getW()  &&m_H == c.getH())
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    //创建立方体类的属性
    private:
        int m_L;
        int m_W;
        int m_H;
};

//创建一个全局函数，来比较两个立方体是否相等
bool isSeem(Cube &c1, Cube &c2)
{
    if(c1.getL() == c2.getL()  && c1.getW() == c2.getW()  &&c1.getH() == c2.getH())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    Cube c1;
    Cube c2;

    //分别写入长宽高
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);
    //打印输出立方体的面积和体积
    cout << "立方体的面积为：" << c1.CalculateS() << endl;
    cout << "立方体的体积为：" << c1.CalculateV() << endl;

    //实例化c2
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);

    //用全局函数比较两个立方体是否相等
    isSeem(c1, c1);
    bool ret = isSeem(c1, c2);
    if(ret == true)
    {
        cout << "相等" << endl;
    }
    else if(ret == false)
    {
        cout << "不相等" << endl;
    }

    
    //用成员函数来判断是否相等
    ret = c1.isSeemByclass(c2);
    if(ret == true)
    {
        cout << "相等" << endl;
    }
    else if(ret == false)
    {
        cout << "不相等" << endl;
    }
}