
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>      //����\b���˵������������г����漴���沼�֣������Ż�������ɾ��
#include<string.h>
#define M 100
struct credicard
{
    int number;
	char cardNO[20];//����
	char name[20];//�ֿ�������
    char ID[20];//�ֿ������֤����
	char password[20];//����
	int flag;//��־�ÿ��Ƿ�����
	float account;//�˻����
	int integal;//����
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
	printf("\t\t*********************���п�����ϵͳ************************\n");
	printf("\n\n\n\t\t �����������............");
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
		 printf("\t\t||                    (1) �� �� �� ��                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
         printf("\t\t||                    (2) �� �� �� ��                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (3) �� �� �� ½                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (4) �� �� �� ��                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (5) �� ��                         ||\n");
		 printf("\t\t||______________________________________________________||\n");
		 printf("\n\n\t\t ��ѡ�����(1--5):< >\b\b");
		 scanf("%d",&v);
		 if(v<1||v>5)
		 {
			 printf("\n\n\t\t**********�� �� �� �� !************");
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
		printf("\n\n\t������Ҫ����ĺ���(��λ):<\t\t\t>\b\b\b\b\b\b\b");
		scanf("%s",h);
        if(strlen(h)!=6)
		{
			printf("\n\n\n\t\t**************������������������***************\n\n");
			continue;
		}
		for(i=0;i<n;i++)
			if(strcmp(card[i].ID,h)==0)
			{
				printf("\n\n\t\t**********�ú����Ѿ����ڣ�����������**********\n\n");
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
	printf("\n\n\n\t\t********************�� �� �� �� !**********************\n\n");
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
		printf("\n\n\n\t\t************�ɹ�����!!!************");
}
void life()
{
	int k=-1;
	char h[20];
	if(n==0)
		printf("\n\n\t\t****************�� �� �� ��*********************\n");
	else
	{
		printf("\n\n\t���������п�����:<\t\t\t>\b\b\b\b\b\b\b");
		scanf("%s",h);
		k=search(h);
		if(k==-1)
			printf("\n\n\t\t\t*****************�ú��벻����!****************\n");
		else
		{
			if(card[k].flag==1)
				printf("\n\n\t\t****************�ÿ��Ѿ�����!*****************\n");
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
	 printf("\n\n\t\t �Ƿ񼤻�ÿ�?  (1) ��     (2) ��  \n");
	 printf("\n\t\t ��ѡ��ѡ��:< >\b\b");
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
	 printf("\n\n\t\t����������:<\t\t\t>\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	 scanf("%s",m);
	 strcpy(card[k].name,m);
	 printf("\n\n\t\t��������λ������:<      >\b\b\b\b\b\b\b");
	 scanf("%s",p);
	 strcpy(card[k].password,p);
	 card[k].flag=1;
	 printf("\n\n\n\t\t*******************�� �� �� ��!**********************\n\n");
	 print_one(k);
	 add();
 }
}
void enter()
{
	int k=-1;
    char h[20];
    if(n==0)
    printf("\n\n\t\t****************�� �� �� ��*********************\n");
    else
{
	printf("\n\n\t���������п�����:<\t\t\t>\b\b\b\b\b\b\b");
	scanf("%s",h);
	k=search(h);
	if(k==-1)
		printf("\n\n\t\t\t*****************�ú��벻����!****************\n");
	else
	{
		if(card[k].flag=0)
			printf("\n\n\t\t************�ÿ���δ������ȼ���!************\n");
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
		printf("\n\n\t\t*******����������:<      >\b\b\b\b\b\b\b");
		scanf("%s",p);
		if(strcmp(card[k].password,p)!=0)
		{
			printf("\n\n\t\t********���벻��ȷ������������!**********\n");
			c++;
			continue;
		}
		else
		{
			printf("\n\n\t\t**********�� �� �� ȷ !***********\n");
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
		printf("\t\t||                    (1)  ��    ѯ                     ||\n");
		printf("\t\t||------------------------------------------------------||\n");
		printf("\t\t||                    (2)  ��    ��                     ||\n");
		printf("\t\t||------------------------------------------------------||\n");
		printf("\t\t||                    (3)  ȡ    ��                     ||\n");
		printf("\t\t||------------------------------------------------------||\n");
		printf("\t\t||                    (4) �� �� �� ��                   ||\n");
		printf("\t\t||------------------------------------------------------||\n");
		printf("\t\t||                    (5) �������˵�                    ||\n");
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
	printf("\n\n\t\t*************�� �� �� �� !***************");
	print_one(k);
	menu1(k);
}
void deposit(int k)
{
	float a=0.00;
	printf("\n\n\t\t����������:<\t\t>\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%f",&a);
	card[k].account+=a;
	printf("\n\n\t\t**********�� �� �� �� !***********");
	print_one(k);
	add();
	menu1(k);
}
void fetch(int k)
{
	float b=0.00;
	printf("\n\n\t\t������ȡ����:<\t\t>\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%f",&b);
	if(b>card[k].account)
	printf("\n\n\t\t**********�� �� �� �� !*************");
	else
	{
		card[k].account-=b;
		card[k].integal=b;
        printf("\n\n\t\t**********л л ʹ �� !***********");
		print_one(k);
		add();
}
	menu1(k);
}
void change(int k)
{  char a[8],b[8];
printf("\n\n\t\t����������λ������:<      >\b\b\b\b\b\b\b");
scanf("%s",a);
printf("\n\t\t���ٴ���������λ������:<      >\b\b\b\b\b\b\b");
scanf("%s",b);
if(strcmp(a,b)==0)
{
	printf("\n\n\t\t**********�����޸ĳɹ�!*************");
	add();
}
else
printf("\n\n\t\t�����������벻һ�£������޸�ʧ��!");
menu1(k);
}
void browse()
{
	int i;
	if(n==0)
		printf("\n\n\t\t**********�޼�¼�������ƿ�!***********");
	else
	{
		printf("\n\n\t\t*************�� �� �� �� !**************\n");
		printf("\n|----|--------------------|--------------------|----|----------|----------|");
		printf("\n|NO. |    ��    ��        |     ��    ��       |flag| account  |  integal |");
		printf("\n|----|--------------------|--------------------|----|----------|----------|");
		for(i=0;i<n;i++)
	    printf("\n|%4d|%20s|%20s|%4d|%10.2f|%10d|",card[i].number,card[i].name,card[i].ID,card[i].flag,card[i].account,card[i].integal);
		printf("\n|----|--------------------|--------------------|----|----------|----------|");
}
	menu();
}
