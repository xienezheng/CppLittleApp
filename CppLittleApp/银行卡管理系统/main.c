#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int n=0;
long int temp1=12312434;
struct crecard
{
    long int carno;
    char name[20];
    char ID[20];
    char password[20];
    int flag;
    float account;
    int integral;

}card[10];
FILE *fp1,*fp2;
void apply()
{
    char temp2[20];
    printf("��������������(Ӣ�ģ�\n");
scanf("%s",card[n].name);
printf("����������ID(����)\n");
scanf("%s",card[n].ID);
printf("�������ʼ���\n");
scanf("%f",&card[n].account);
printf("�������ʼ����\n");
scanf("%d",&card[n].integral);
printf("��������������\n");
scanf("%s",card[n].password);
printf("���ٴ�������������\n");
scanf("%s",temp2);
if(strcmp(temp2,card[n].password)==0)
{
    printf("����ɹ�\n������Ŀ���Ϊ%ld\n",temp1);
}
else{
    printf("���벻һ�£�����������\n");
}
printf("��Ϣ�Ѵ����ļ�\n");

card[n].carno=temp1;
card[n].flag=1;
 fwrite(&card[n],sizeof(struct crecard),1,fp1);
n++;
temp1++;
};
void inquiry()
{
    int i;
    printf("����        ����       ���֤��     �Ƿ�����    �˻����      ����       \n");
    for(i=0;i<n;i++)
    { printf("�Ѵ��ļ�����ȡ\n");
        fread(&card[i],sizeof(struct crecard),1,fp2);
        printf("%ld%10s%10s%10d%12.2f%12d\n",card[i].carno,card[i].name,card[i].ID,card[i].flag,card[i].account,card[i].integral);
    }
}
void search()
{
    int i;
    long int temp4;
    printf("�����뿨��\n");
    scanf("%ld",&temp4);

     for(i=0;i<n;i++)
    {if(card[i].carno==temp4)
    {fread(&card[i],sizeof(struct crecard),1,fp2);
      printf("����        ����       ���֤��     �Ƿ�����    �˻����      ����       \n");
        printf("%ld%10s%10s%10d%12.2f%12d\n",card[i].carno,card[i].name,card[i].ID,card[i].flag,card[i].account,card[i].integral);
    }
    }
}
void load()
{long int temp5;
char temp6[20];
int i, temp7;
    printf("���������Ŀ���\n");
    scanf("%ld",&temp5);
    for(i=0;i<n;i++)
    {
        if(card[i].carno==temp5)
        {
            printf("��������������\n");
            scanf("%s",temp6);
            if(strcmp(card[i].password,temp6)==0)
            {
                printf("��½�ɹ�\n");
                printf("�����뽻�׽��\n");
                scanf("%d",&temp7);
                if(card[i].account>=temp7)
                {
                card[i].account=card[i].account-temp7;
                card[i].integral=card[i].integral+temp7;
                printf("�����ɹ�\n");
                }
                else{
                    printf("���㣬�޷���ɸò���\n");
                }
            }
        }

    }
}
void add()
{long int temp8;
int i;
    printf("��������Ҫ��ѯ���˺�\n");
    scanf("%ld",&temp8);
    for(i=0;i<n;i++)
    {
        if(card[i].carno==temp8)
        {
            printf("����ǰ�˻�����Ϊ%d\n",card[i].integral);
        }
    }
}
int main()
{int k;
int j;
if((fp1=fopen("c.dat","wb"))==NULL)
{
    printf("�޷��������ļ�\n");
    exit(0);
}
if((fp2=fopen("c.dat","rb"))==NULL)
{
    printf("�޷��������ļ�\n");
    exit(0);
}
    system("color 46");
for(j=1;j>0;j++)
{
    printf("                ***************************\n");
    printf("                        0:����             \n");
    printf("                        1:ע��ͷ���       \n");
    printf("                        2:���˻���ѯ       \n");
    printf("                        3:ȫ���˻���ѯ     \n");
    printf("                        4:��¼�ͽ���       \n");
    printf("                        5:���ֹ���         \n");
    printf("                ***************************\n");
    printf("��������Ҫִ�еĲ���\n");
    scanf("%d",&k);
    system("cls");
    if(k==0)
    {
        break;
    }
switch(k)
{
    case 1:apply();break;
    case 2:search();break;
    case 3:inquiry();break;
    case 4:load();break;
    case 5:add();break;
}
}
return 0;
}
