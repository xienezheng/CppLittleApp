#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;


void add()
{
    int add1,add2,sum1,sum2;
    int i=1;
    while(i)
    {
    add1=rand()%100;
    add2=rand()%100;
    cout<<add1<<"+"<<add2<<"=______?"<<endl;
    sum1=add1+add2;
    cin>>sum2;
    if(sum2==sum1)
    {
        cout<<"<-O->"<<"小朋友你太聪明啦，加油！"<<endl;

    }
    else
    {
        cout<<"小朋友不够细心啊，再仔细想想"<<"\a\a\a\a\a"<<endl;
    }
    cout<<"继续留在加法练习请按1"<<endl;
    cout<<"返回主菜单请按0"<<endl;
    cin>>i;
    }
     if(i!=1&&i!=0)
    {
        cout<<"输入有误,请重新输入"<<endl;
        cin>>i;
    }


}
void subtract()
{
    int add1,add2,sum1,sum2;
    int i=1;
    while(i)
    {
    add1=rand()%100;
    add2=rand()%100;
    cout<<add1<<"-"<<add2<<"=______?"<<endl;
    sum1=add1-add2;
    cin>>sum2;
    if(sum2==sum1)
    {
        cout<<"<-O->"<<"小朋友你太聪明啦，加油！"<<endl;

    }
    else
    {
        cout<<"小朋友不够细心啊，再仔细想想"<<"\a\a\a\a\a"<<endl;
    }
      cout<<"继续留在减法练习请按1"<<endl;
    cout<<"返回主菜单请按0"<<endl;
    cin>>i;
     if(i!=1&&i!=0)
    {
        cout<<"输入有误,请重新输入"<<endl;
        cin>>i;
    }

}
}
void mutply()
{
    int i=1;
    int add1,add2,sum1,sum2;
    while(i)
    {
    add1=rand()%100;
    add2=rand()%100;
    cout<<add1<<"X"<<add2<<"=______?"<<endl;
    sum1=add1*add2;
    cin>>sum2;
    if(sum2==sum1)
    {
        cout<<"<-O->"<<"小朋友你太聪明啦，加油！"<<endl;

    }
    else
    {
        cout<<"小朋友不够细心啊，再仔细想想"<<"\a\a\a\a\a"<<endl;
    }
      cout<<"继续留在乘法练习请按1"<<endl;
    cout<<"返回主菜单请按0"<<endl;
    cin>>i;
     if(i!=1&&i!=0)
    {
        cout<<"输入有误,请重新输入"<<endl;
        cin>>i;
    }

    }
}
void division()
{

int i=1;
float add1,add2,sum1,sum2;
while(i)
{
    add1=rand()%100;
    add2=rand()%100;
    cout<<add1<<"/"<<add2<<"=______?"<<endl;
    sum1=add1/add2;
    cin>>sum2;
    if(sum2==sum1)
    {
        cout<<"<-O->"<<"小朋友你太聪明啦，加油！"<<endl;

    }
    else
    {
        cout<<"小朋友不够细心啊，再仔细想想"<<"\a\a\a\a\a"<<endl;
    }
      cout<<"继续留在除法练习请按1"<<endl;
    cout<<"返回主菜单请按0"<<endl;
    cin>>i;
    if(i!=1&&i!=0)
    {
        cout<<"输入有误,请重新输入"<<endl;
        cin>>i;
    }
}
}
int main()
{ system("color 25");
    int open,j=1;
    while(j)
    {system("cls");
    cout<<"               ****************"<<endl;
    cout<<"                1:加法练习     "<<endl;
     cout<<"                2:减法练习     "<<endl;
      cout<<"                3:乘法练习     "<<endl;
       cout<<"                4:除法练习     "<<endl;
        cout<<"                0:结束        "<<endl;
    cout<<"               ****************"<<endl;
    cout<<"请选择您要进行训练的选项<-O->"<<endl;
    cin>>open;
    if(open>4||open<0)
    {
        cout<<"输入有误,请重新输入"<<endl;
        cin>>open;
    }
    switch(open)
    {
        case 1:add();break;
        case 2:subtract();break;
        case 3:mutply();break;
        case 4:division();break;
        case 0:break;

    }
    cout<<"继续请按1，退出程序请按0"<<endl;
    cin>>j;
    if(j!=1&&j!=0)
    {
        cout<<"输入有误,请重新输入"<<endl;
        cin>>j;
    }

}
}//控制结束与跳出
//输入检错，重新输入问题
//错误警报装置
