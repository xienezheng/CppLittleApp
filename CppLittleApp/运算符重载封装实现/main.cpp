#include <iostream>

using namespace std;
class complex
{
    int a;
    int b;
public:
    complex(int x,int y)
    {a=x;
    b=y;

    }
    void display()
    {
        cout<<a<<"+i"<<b;
    }
    friend complex& operator+(const complex & x1,const complex & x2)
    {
        class complex fou(0,0);
        fou.a=x1.a+x2.a;
    fou.b=x1.b+x2.b;
        return(fou);
    }
    friend complex operator-(const complex & x1,const complex & x2)
    {
       int a,b;
       a=x1.a-x2.a;
       b=x1.b-x2.b;
       return complex(a,b);
    }
};
int main()
{
    class complex one(3,4),two(4,5);
    class complex thr(0,0);
    thr=one-two;
    thr.display();
}

