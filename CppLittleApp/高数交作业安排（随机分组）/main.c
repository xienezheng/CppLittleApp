#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void random()//�������˳��ĺ���
{int i,j,temp;
   int ran[8];//�����ȡ


   ran[0]=rand()%4;//�����㷨
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
   for(i=0;i<4;i++)//�������
   {
       switch(ran[i])
       {

           case 0:printf("192151:�Ű�һ��\n");break;
           case 1:printf("192152:�Ű�����\n");break;
           case 2:printf("193151:����һ��\n");break;
           case 3:printf("193152:��������\n");break;
       }

   }
   printf("\n\n\n");//�������У�������
}
int main()
{system("color 21");
    int temp1;
    printf("                             ********************\n");
    printf("                                       1����     \n");
    printf("                                       2�˳�     \n");
    printf("                             ********************\n");//�˵�����Ļ��ɫ
while(scanf("%d",&temp1)&&temp1!=2)
{
 system("cls");//����
     printf("                              ********************\n");
    printf("                                        1����     \n");
    printf("                                        2�˳�     \n");
    printf("                              ********************\n");
    if(temp1==1)//���ú���
    {
        random();

    }

}
}
