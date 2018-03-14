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
    printf("请输入您的姓名(英文）\n");
scanf("%s",card[n].name);
printf("请输入您的ID(数字)\n");
scanf("%s",card[n].ID);
printf("请输入初始金额\n");
scanf("%f",&card[n].account);
printf("请输入初始积分\n");
scanf("%d",&card[n].integral);
printf("请输入您的密码\n");
scanf("%s",card[n].password);
printf("请再次输入您的密码\n");
scanf("%s",temp2);
if(strcmp(temp2,card[n].password)==0)
{
    printf("申请成功\n您申请的卡号为%ld\n",temp1);
}
else{
    printf("密码不一致，请重新输入\n");
}
printf("信息已存入文件\n");

card[n].carno=temp1;
card[n].flag=1;
 fwrite(&card[n],sizeof(struct crecard),1,fp1);
n++;
temp1++;
};
void inquiry()
{
    int i;
    printf("卡号        姓名       身份证号     是否启用    账户金额      积分       \n");
    for(i=0;i<n;i++)
    { printf("已从文件中提取\n");
        fread(&card[i],sizeof(struct crecard),1,fp2);
        printf("%ld%10s%10s%10d%12.2f%12d\n",card[i].carno,card[i].name,card[i].ID,card[i].flag,card[i].account,card[i].integral);
    }
}
void search()
{
    int i;
    long int temp4;
    printf("请输入卡号\n");
    scanf("%ld",&temp4);

     for(i=0;i<n;i++)
    {if(card[i].carno==temp4)
    {fread(&card[i],sizeof(struct crecard),1,fp2);
      printf("卡号        姓名       身份证号     是否启用    账户金额      积分       \n");
        printf("%ld%10s%10s%10d%12.2f%12d\n",card[i].carno,card[i].name,card[i].ID,card[i].flag,card[i].account,card[i].integral);
    }
    }
}
void load()
{long int temp5;
char temp6[20];
int i, temp7;
    printf("请输入您的卡号\n");
    scanf("%ld",&temp5);
    for(i=0;i<n;i++)
    {
        if(card[i].carno==temp5)
        {
            printf("请输入您的密码\n");
            scanf("%s",temp6);
            if(strcmp(card[i].password,temp6)==0)
            {
                printf("登陆成功\n");
                printf("请输入交易金额\n");
                scanf("%d",&temp7);
                if(card[i].account>=temp7)
                {
                card[i].account=card[i].account-temp7;
                card[i].integral=card[i].integral+temp7;
                printf("操作成功\n");
                }
                else{
                    printf("金额不足，无法完成该操作\n");
                }
            }
        }

    }
}
void add()
{long int temp8;
int i;
    printf("请输入您要查询的账号\n");
    scanf("%ld",&temp8);
    for(i=0;i<n;i++)
    {
        if(card[i].carno==temp8)
        {
            printf("您当前账户积分为%d\n",card[i].integral);
        }
    }
}
int main()
{int k;
int j;
if((fp1=fopen("c.dat","wb"))==NULL)
{
    printf("无法代开此文件\n");
    exit(0);
}
if((fp2=fopen("c.dat","rb"))==NULL)
{
    printf("无法代开此文件\n");
    exit(0);
}
    system("color 46");
for(j=1;j>0;j++)
{
    printf("                ***************************\n");
    printf("                        0:结束             \n");
    printf("                        1:注册和发卡       \n");
    printf("                        2:按账户查询       \n");
    printf("                        3:全部账户查询     \n");
    printf("                        4:登录和交易       \n");
    printf("                        5:积分功能         \n");
    printf("                ***************************\n");
    printf("请输入您要执行的操作\n");
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
