#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void random()//产生随机顺序的函数
{int i,j,temp;
   int ran[8];//数组存取


   ran[0]=rand()%4;//核心算法
   for(i=1;i<4;)
   {temp=rand()%4;
       for(j=0;j<i;j++)
       {
           if(temp==ran[j])
           {
               break;
           }
           else
        {
            if(j==i-1)
            {
          ran[i]=temp;
          i++;
            }
        }
       }
   }
   for(i=0;i<4;i++)//输出部分
   {
       switch(ran[i])
       {

           case 0:printf("192151:信安一班\n");break;
           case 1:printf("192152:信安二班\n");break;
           case 2:printf("193151:网工一班\n");break;
           case 3:printf("193152:网工二班\n");break;
       }

   }
   printf("\n\n\n");//三个换行，更清晰
}
int main()
{system("color 21");
    int temp1;
    printf("                             ********************\n");
    printf("                                       1更新     \n");
    printf("                                       2退出     \n");
    printf("                             ********************\n");//菜单和屏幕颜色
while(scanf("%d",&temp1)&&temp1!=2)
{
 system("cls");//清屏
     printf("                              ********************\n");
    printf("                                        1更新     \n");
    printf("                                        2退出     \n");
    printf("                              ********************\n");
    if(temp1==1)//调用函数
    {
        random();

    }

}
}
