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
        cout<<"<-O->"<<"С������̫�����������ͣ�"<<endl;

    }
    else
    {
        cout<<"С���Ѳ���ϸ�İ�������ϸ����"<<"\a\a\a\a\a"<<endl;
    }
    cout<<"�������ڼӷ���ϰ�밴1"<<endl;
    cout<<"�������˵��밴0"<<endl;
    cin>>i;
    }
     if(i!=1&&i!=0)
    {
        cout<<"��������,����������"<<endl;
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
        cout<<"<-O->"<<"С������̫�����������ͣ�"<<endl;

    }
    else
    {
        cout<<"С���Ѳ���ϸ�İ�������ϸ����"<<"\a\a\a\a\a"<<endl;
    }
      cout<<"�������ڼ�����ϰ�밴1"<<endl;
    cout<<"�������˵��밴0"<<endl;
    cin>>i;
     if(i!=1&&i!=0)
    {
        cout<<"��������,����������"<<endl;
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
        cout<<"<-O->"<<"С������̫�����������ͣ�"<<endl;

    }
    else
    {
        cout<<"С���Ѳ���ϸ�İ�������ϸ����"<<"\a\a\a\a\a"<<endl;
    }
      cout<<"�������ڳ˷���ϰ�밴1"<<endl;
    cout<<"�������˵��밴0"<<endl;
    cin>>i;
     if(i!=1&&i!=0)
    {
        cout<<"��������,����������"<<endl;
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
        cout<<"<-O->"<<"С������̫�����������ͣ�"<<endl;

    }
    else
    {
        cout<<"С���Ѳ���ϸ�İ�������ϸ����"<<"\a\a\a\a\a"<<endl;
    }
      cout<<"�������ڳ�����ϰ�밴1"<<endl;
    cout<<"�������˵��밴0"<<endl;
    cin>>i;
    if(i!=1&&i!=0)
    {
        cout<<"��������,����������"<<endl;
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
    cout<<"                1:�ӷ���ϰ     "<<endl;
     cout<<"                2:������ϰ     "<<endl;
      cout<<"                3:�˷���ϰ     "<<endl;
       cout<<"                4:������ϰ     "<<endl;
        cout<<"                0:����        "<<endl;
    cout<<"               ****************"<<endl;
    cout<<"��ѡ����Ҫ����ѵ����ѡ��<-O->"<<endl;
    cin>>open;
    if(open>4||open<0)
    {
        cout<<"��������,����������"<<endl;
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
    cout<<"�����밴1���˳������밴0"<<endl;
    cin>>j;
    if(j!=1&&j!=0)
    {
        cout<<"��������,����������"<<endl;
        cin>>j;
    }

}
}//���ƽ���������
//������������������
//���󾯱�װ��
