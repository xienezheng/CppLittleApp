
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>      //输入\b，菜单做函数，换行出界面即界面布局，界面优化，界面删除
#include<string.h>
#define M 100
struct credicard
{
    int number;
	char cardNO[20];//卡号
	char name[20];//持卡人姓名
    char ID[20];//持卡人身份证号码
	char password[20];//密码
	int flag;//标志该卡是否启用
	float account;//账户金额
	int integal;//积分
}card[M];
void menu();
void made();
void add();
void life();
void enter();
void browse();
void huo(int k);
void hedui(int k);
void menu1(int k);
void fetch(int k);
void change(int k);
void deposit(int k);
void stat_one(int k);
void print_one(int j);
int search(char h[20]);
int n=0;
void main()
{
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t*********************银行卡管理系统************************\n");
	printf("\n\n\n\t\t 按任意键进入............");
	getchar();
	menu();
}
void menu()
{
     int v,w1;
	 do
	 {
		 printf("\n\n\n\n");
		 printf("\t\t<_______________________THE MENU_________________________>\n");
		 printf("\n");
		 printf("\t\t||                    (1) 制 卡 操 作                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
         printf("\t\t||                    (2) 帐 号 激 活                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (3) 帐 户 登 陆                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (4) 报 表 操 作                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (5) 退 出                         ||\n");
		 printf("\t\t||______________________________________________________||\n");
		 printf("\n\n\t\t 请选择操作(1--5):< >\b\b");
		 scanf("%d",&v);
		 if(v<1||v>5)
		 {
			 printf("\n\n\t\t**********输 入 有 误 !************");
			 w1=1;
			 getchar();
		 }
		 else w1=0;
	 }
	 while(w1==1);
	 switch(v)
	 {
	 case 1:made();break;
	 case 2:life();break;
	 case 3:enter();break;
	 case 4:browse();break;
	 case 5:exit(0);
	 }
}

void made()
{
	int i;
	char h[20];
	do
	{
		printf("\n\n\t请输入要申请的号码(六位):<\t\t\t>\b\b\b\b\b\b\b");
		scanf("%s",h);
        if(strlen(h)!=6)
		{
			printf("\n\n\n\t\t**************输入有误，请重新输入***************\n\n");
			continue;
		}
		for(i=0;i<n;i++)
			if(strcmp(card[i].ID,h)==0)
			{
				printf("\n\n\t\t**********该号码已经存在，请重新输入**********\n\n");
				break;
			}
	}
	while(((strlen(h))!=6)||strcmp(card[i].ID,h)==0);
	card[n].number=n;
	strcpy(card[n].name,"***");
    strcpy(card[n].ID,h);
	strcpy(card[n].password,"000000");
	card[n].flag=0;
	card[n].account=0.00;
	card[n].integal=0;
	printf("\n\n\n\t\t********************制 卡 成 功 !**********************\n\n");
	print_one(n);
	n++;
	add();
	menu();
}
void print_one(int j)
 {
	printf("\n|----|--------------------|--------------------|----|----------|----------|");
	printf("\n|NO. |        name        |         ID         |flag| account  |  integal |");
	printf("\n|----|--------------------|--------------------|----|----------|----------|");
	printf("\n|%4d|%20s|%20s|%4d|%10.2f|%10d|",card[j].number,card[j].name,card[j].ID,card[j].flag,card[j].account,card[j].integal);
	printf("\n|----|--------------------|--------------------|----|----------|----------|");
}
void add()
{
	int i;
	FILE *fp;
	if((fp=fopen("score.txt","wb"))==NULL)
	{
		printf("\t\t Can not open the file \n");
		  return;
	}
	for(i=0;i<n;i++)
		if(fwrite(&card[i],sizeof(struct credicard),1,fp)!=1)
		{
			printf("\t\t File write error \n");
			return;
		}
		fclose(fp);
		printf("\n\n\n\t\t************成功保存!!!************");
}
void life()
{
	int k=-1;
	char h[20];
	if(n==0)
		printf("\n\n\t\t****************请 先 制 卡*********************\n");
	else
	{
		printf("\n\n\t请输入银行卡号码:<\t\t\t>\b\b\b\b\b\b\b");
		scanf("%s",h);
		k=search(h);
		if(k==-1)
			printf("\n\n\t\t\t*****************该号码不存在!****************\n");
		else
		{
			if(card[k].flag==1)
				printf("\n\n\t\t****************该卡已经激活!*****************\n");
			else huo(k);
		}
	}
	menu();
}
int search(char h[20])
{
	int i,k=-1;
	for(i=0;i<n;i++)
		if(strcmp(card[i].ID,h)==0)
			k=i;
		return(k);
 }
void huo(int k)
{
	char m[20],p[8];
	int x,w2;
 do
 {
	 printf("\n\n\t\t 是否激活该卡?  (1) 是     (2) 否  \n");
	 printf("\n\t\t 请选择选项:< >\b\b");
	 scanf("%d",&x);
	 if(x<1||x>2)
	 {
		 w2=1;getchar();
	 }
	     else w2=0;
 }
 while(w2==1);
 if(x==1)
 {
	 printf("\n\n\t\t请输入姓名:<\t\t\t>\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	 scanf("%s",m);
	 strcpy(card[k].name,m);
	 printf("\n\n\t\t请输入六位数密码:<      >\b\b\b\b\b\b\b");
	 scanf("%s",p);
	 strcpy(card[k].password,p);
	 card[k].flag=1;
	 printf("\n\n\n\t\t*******************激 活 成 功!**********************\n\n");
	 print_one(k);
	 add();
 }
}
void enter()
{
	int k=-1;
    char h[20];
    if(n==0)
    printf("\n\n\t\t****************请 先 制 卡*********************\n");
    else
{
	printf("\n\n\t请输入银行卡号码:<\t\t\t>\b\b\b\b\b\b\b");
	scanf("%s",h);
	k=search(h);
	if(k==-1)
		printf("\n\n\t\t\t*****************该号码不存在!****************\n");
	else
	{
		if(card[k].flag=0)
			printf("\n\n\t\t************该卡还未激活，请先激活!************\n");
		else
			hedui(k);
  }
}
menu();
}

void hedui(int k)
{
	int c=0,w3=0;
	char p[8];
	do
	{
		printf("\n\n\t\t*******请输入密码:<      >\b\b\b\b\b\b\b");
		scanf("%s",p);
		if(strcmp(card[k].password,p)!=0)
		{
			printf("\n\n\t\t********密码不正确，请重新输入!**********\n");
			c++;
			continue;
		}
		else
		{
			printf("\n\n\t\t**********密 码 正 确 !***********\n");
			w3=1;
			card[k].flag=1;
			menu1(k);
		}
	}
	while(w3==0&&c<3);
}

void menu1(int k)
 {
	int v,w4;
	do
	{
		printf("\n\n\n");
		printf("\t\t<_______________________THE MENU1________________________>\n");
		printf("\t\t||                    (1)  查    询                     ||\n");
		printf("\t\t||------------------------------------------------------||\n");
		printf("\t\t||                    (2)  存    款                     ||\n");
		printf("\t\t||------------------------------------------------------||\n");
		printf("\t\t||                    (3)  取    款                     ||\n");
		printf("\t\t||------------------------------------------------------||\n");
		printf("\t\t||                    (4) 修 改 密 码                   ||\n");
		printf("\t\t||------------------------------------------------------||\n");
		printf("\t\t||                    (5) 返回主菜单                    ||\n");
		printf("\t\t||______________________________________________________||\n");
        printf("\n\n\t\t Choice your number(1--5):< >\b\b");
		scanf("%d",&v);
		if(v<1||v>5)
		{
			w4=1;getchar();}
		else
			w4=0;
	}
	while(w4==1);
	switch(v)
	{
	case 1:stat_one(k);break;
	case 2:deposit(k);break;
	case 3:fetch(k);break;
	case 4:change(k);break;
	case 5:menu();
	}
}
void stat_one(int k)
{
	printf("\n\n\t\t*************操 作 成 功 !***************");
	print_one(k);
	menu1(k);
}
void deposit(int k)
{
	float a=0.00;
	printf("\n\n\t\t请输入存款金额:<\t\t>\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%f",&a);
	card[k].account+=a;
	printf("\n\n\t\t**********存 款 成 功 !***********");
	print_one(k);
	add();
	menu1(k);
}
void fetch(int k)
{
	float b=0.00;
	printf("\n\n\t\t请输入取款金额:<\t\t>\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%f",&b);
	if(b>card[k].account)
	printf("\n\n\t\t**********余 额 不 足 !*************");
	else
	{
		card[k].account-=b;
		card[k].integal=b;
        printf("\n\n\t\t**********谢 谢 使 用 !***********");
		print_one(k);
		add();
}
	menu1(k);
}
void change(int k)
{  char a[8],b[8];
printf("\n\n\t\t请输入新六位数密码:<      >\b\b\b\b\b\b\b");
scanf("%s",a);
printf("\n\t\t请再次输入新六位数密码:<      >\b\b\b\b\b\b\b");
scanf("%s",b);
if(strcmp(a,b)==0)
{
	printf("\n\n\t\t**********密码修改成功!*************");
	add();
}
else
printf("\n\n\t\t两次密码输入不一致，密码修改失败!");
menu1(k);
}
void browse()
{
	int i;
	if(n==0)
		printf("\n\n\t\t**********无记录，请先制卡!***********");
	else
	{
		printf("\n\n\t\t*************操 作 成 功 !**************\n");
		printf("\n|----|--------------------|--------------------|----|----------|----------|");
		printf("\n|NO. |    姓    名        |     卡    号       |flag| account  |  integal |");
		printf("\n|----|--------------------|--------------------|----|----------|----------|");
		for(i=0;i<n;i++)
	    printf("\n|%4d|%20s|%20s|%4d|%10.2f|%10d|",card[i].number,card[i].name,card[i].ID,card[i].flag,card[i].account,card[i].integal);
		printf("\n|----|--------------------|--------------------|----|----------|----------|");
}
	menu();
}
