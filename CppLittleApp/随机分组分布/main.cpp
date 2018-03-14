#include <iostream>
#include<time.h>
using namespace std;

int main()
{
    int a[100];
    int i,cnt=0,cnt1=0;
    int temp;
    for(i=0;i<100;i++)
    {
        temp=rand()%100;
        a[i]=temp;
    if(a[i]<50)
    {
        cnt++;
    }else
    {
        cnt1++;
    }
    }
    cout<<cnt<<endl<<cnt++;
}
