#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student
{
    int id;//ѧ��
    char name[20];//����
	int english;//Ӣ��ɼ�
	int marks;//���˼����ɼ�
	int laywer;//˼�޳ɼ�
	int geob;//����ѧ�ɼ�
	int celiangb;//����ѧ�ɼ�
	int math;//�����ɼ�
	int phyb;//����ʵ��ɼ�
	int phyc;//����c1
	int algebra;//���Դ����ɼ�
	int math2;//��ѧ�����ɼ�
	int matlab;//matlab�ɼ�
	int logic;//�����߼��ɼ�
	int celiang2;//����ѧʵϰ�ɼ�
	int clanguage2;//c����ʵ��

	int coursecnt;//�ܹ����޿γ���
	int scorecnt;//�ܷ�
	double creditcnt;//��ѧ��
	int lownum;//�������Ŀ��
	double lowcredit;//������ѧ��


	double gpa;//����
}student[100];
void GPA();
void menu();
void coursecnt();
void creditcnt();
void count();
void queryCountFirst();
void sortgpa();
void queryInformation();
void queryLow();//��ѯ�ҿ�����
void write();
 int flag=1;
  int main()
{
    FILE *fp;
	int i=0,j;
	fp=fopen("score1.txt","r+");
	if(fp==NULL)
    {
        printf("file open error\n");

    }
	for(i=0;i<31;i++)
    {

	      fscanf(fp,"%d %s %d %d %d %d %d  %d %d %d %d %d %d %d %d %d\n",&student[i].id,&student[i].name,&student[i].english,
              &student[i].marks,&student[i].laywer,&student[i].geob,&student[i].celiangb,&student[i].math,
              &student[i].phyb,&student[i].phyc,&student[i].algebra,&student[i].math2,&student[i].matlab,&student[i].logic,&student[i].celiang2,
              &student[i].clanguage2);

    }
	fclose(fp);

	/*for(i=0;i<31;i++)
    {
	      printf("%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",student[i].id,student[i].name,student[i].english,
              student[i].marks,student[i].laywer,student[i].geob,student[i].celiangb,student[i].math,
              student[i].phyb,student[i].phyc,student[i].algebra,student[i].math2,student[i].matlab,student[i].logic,student[i].celiang2,
              student[i].clanguage2);
    }*/

	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t*********************ѧ���ɼ�����ϵͳ************************\n");
	printf("\n\n\n\t\t �ļ���ȡ�У������������............");
	getchar();
	system("cls");
	printf("�ļ���ȡ���,��ѡ����Ҫ�Ĳ���\n");

	 while(flag)
     {

	menu();

     }
     return 0;
}
void coursecnt()//ͳ��ÿ��ѧ�����޿γ������ܷ�
{
    int i=0,j=0;
   int score[14];

    for(i=0;i<31;i++)
    {int cnt=0;
    int sum=0;
        score[0]=student[i].english;
               score[1]=student[i].marks;
               score[2]=student[i].laywer;
               score[3]=student[i].geob;
                score[4]=student[i].celiangb;
               score[5]=student[i].math;
                score[6]=student[i].phyb;
               score[7]=student[i].phyc;
                score[8]=student[i].algebra;
               score[9]=student[i].math2;
                score[10]=student[i].matlab;
               score[11]=student[i].logic;
                score[12]=student[i].celiang2;
                score[13]=student[i].clanguage2;

                for(j=0;j<14;j++)
                {
                    if(score[j]!=0)
                    {

                        cnt++;
                        sum=sum+score[j];
                    }

                }

                student[i].coursecnt=cnt;
                 student[i].scorecnt=sum;
    }

}
void creditcnt()//ͳ��ÿ��ѧ������ѧ������������ѧ����
{
    int i=0,j=0;
   int score[14];
double credit[14];
 credit[0]=4.0;
               credit[1]=3.0;
               credit[2]=1.5;
               credit[3]=3.0;
                credit[4]=2.5;
               credit[5]=7.0;
               credit[6]=2.0;
               credit[7]=3.5;
               credit[8]=4.5;
               credit[9]=6.0;
                credit[10]=2.5;
               credit[11]=3.0;
                credit[12]=1.5;
                credit[13]=2.0;
    for(i=0;i<31;i++)
    {int cnt=0;
    double sum=0;
    double lowsum=0;
        score[0]=student[i].english;
               score[1]=student[i].marks;
               score[2]=student[i].laywer;
               score[3]=student[i].geob;
                score[4]=student[i].celiangb;
               score[5]=student[i].math;
                score[6]=student[i].phyb;
               score[7]=student[i].phyc;
                score[8]=student[i].algebra;
               score[9]=student[i].math2;
                score[10]=student[i].matlab;
               score[11]=student[i].logic;
                score[12]=student[i].celiang2;
                score[13]=student[i].clanguage2;

                for(j=0;j<14;j++)
                {
                    if(score[j]!=0)
                    {


                        sum=sum+credit[j];
                    }

                }

                student[i].creditcnt=sum;//������ѧ����
                   for(j=0;j<14;j++)
                {
                    if(score[j]<60&&score[j]!=0)
                    {


                        cnt++;
                        lowsum=lowsum+credit[j];
                    }

                }
                 student[i].lownum=cnt; //�󲻼�������
                  student[i].lowcredit=lowsum; //�󲻼�������
    }

}

void count()//�༶ͳ�ƺ���
{
    coursecnt();//���ÿγ�������
    creditcnt();//������ѧ�ֺ���
    int i;
    printf("ѧ��           ����   ���޿�Ŀ��    �ܷ�    ��ѧ��   �������Ŀ��    ������ѧ��\n");
    for(i=0;i<31;i++)
    {
    printf("%d    %s          %d         %d        %.1f        %d         %.1f\n",student[i].id,student[i].name,student[i].coursecnt,
       student[i].scorecnt,student[i].creditcnt,student[i].lownum,student[i].lowcredit);
    }
}

void queryCountFirst()//�ڲ�ѯǰ��ִ�д˺������м���
{
     coursecnt();//���ÿγ�������
    creditcnt();//������ѧ�ֺ���
    GPA();
}
void GPA()//����GPA
{

     int i=0,j=0;
   int score[14];
double credit[14];
double Gpa[14];
 credit[0]=4.0;
               credit[1]=3.0;
               credit[2]=1.5;
               credit[3]=3.0;
                credit[4]=2.5;
               credit[5]=7.0;
               credit[6]=2.0;
               credit[7]=3.5;
               credit[8]=4.5;
               credit[9]=6.0;
                credit[10]=2.5;
               credit[11]=3.0;
                credit[12]=1.5;
                credit[13]=2.0;
    for(i=0;i<31;i++)
    {double gpacnt=0;
  double allcredit=0;
  int m;
        score[0]=student[i].english;
               score[1]=student[i].marks;
               score[2]=student[i].laywer;
               score[3]=student[i].geob;
                score[4]=student[i].celiangb;
               score[5]=student[i].math;
                score[6]=student[i].phyb;
               score[7]=student[i].phyc;
                score[8]=student[i].algebra;
               score[9]=student[i].math2;
                score[10]=student[i].matlab;
               score[11]=student[i].logic;
                score[12]=student[i].celiang2;
                score[13]=student[i].clanguage2;
  for(m=0;m<14;m++)
  {
if(score[m]>=60)
{

      allcredit=allcredit+credit[m];
  }
  }

                for(j=0;j<14;j++)
                {
                    if(score[j]>=60)
                    {


                       Gpa[j]=score[j]/10-5;
                       gpacnt=gpacnt+credit[j]*Gpa[j];
                    }


                }
                student[i].gpa=gpacnt/allcredit;


    }
}
void sortgpa()//��GPA��������
{


GPA();
    double creditsort[31];
    int i,j;
    double temp;
    for(i=0;i<31;i++)
    {
        creditsort[i]=student[i].gpa;


    }
        for(i=0;i<31;i++)
        {
    for(j=30;j>i;j--)
        {
            if(creditsort[j]<creditsort[j-1])
            {
             temp=creditsort[j-1];
                creditsort[j-1]=creditsort[j];
                creditsort[j]=temp;
            }

        }
    }
      for(i=0;i<31;i++)
    {
        for(j=0;j<31;j++)
        {

            if(student[j].gpa==creditsort[i])
            {

                printf("%d %s %.2f\n",student[j].id,student[j].name,student[j].gpa);
            }

        }
    }
}

void queryInformation()
{   queryCountFirst();
    int n,targetid;
    char targetname[20];
    printf("��ѡ���ѯ��ʽ��\n");
    printf("1:ѧ�Ų�ѯ\n");
    printf("2:������ѯ\n");
    scanf("%d",&n);

    if(n==1)//ѧ�Ų�ѯ
    {printf("������ѧ��ѧ��\n");
    scanf("%d",&targetid);
        int i;
        for(i=0;i<31;i++)
        {

            if(student[i].id==targetid)
            {

                printf("��ѧ��������Ϣ����\n");
                printf("ѧ��           ����     ���޿�Ŀ��     �ܷ�     ��ѧ��           ����\n");
                printf("%d  %s    %d           %d            %.1f             %.2f\n",student[i].id,student[i].name,student[i].coursecnt,student[i].scorecnt,student[i].creditcnt,student[i].gpa);
             printf("��ѧӢ��      ���˼�������ԭ��      ˼��      ����ѧ       ����     �ߴ�....\n");
             printf("%d                       %d            %d         %d         %d        %d",student[i].english,student[i].marks,student[i].laywer,student[i].geob,student[i].math,student[i].algebra);

            break;
            }
        }
        if(i==31)
        {

            printf("�����ڴ�ѧ���������Ƿ���������\n");
            queryInformation();
        }

    }
       else if(n==2)//������ѯ
    {
        printf("������ѧ������\n");
    scanf("%s",targetname);
        int i;
        for(i=0;i<31;i++)
        {

            if(strcmp(student[i].name,targetname)==0)
            {

                printf("��ѧ��������Ϣ����\n");
                printf("ѧ��           ����     ���޿�Ŀ��     �ܷ�     ��ѧ��           ����\n");
                printf("%d  %s    %d           %d            %.1f             %.2f\n",student[i].id,student[i].name,student[i].coursecnt,student[i].scorecnt,student[i].creditcnt,student[i].gpa);
             printf("��ѧӢ��      ���˼�������ԭ��      ˼��      ����ѧ       ����     �ߴ�....\n");
             printf("%d                       %d            %d         %d         %d        %d\n",student[i].english,student[i].marks,student[i].laywer,student[i].geob,student[i].math,student[i].algebra);

            break;
            }
        }
        if(i==31)
        {

            printf("�����ڴ�ѧ���������Ƿ���������\n");
            queryInformation();
        }

    }
   else
    {

        printf("������������������\n");
        queryInformation();
    }
}
void queryLow()//��ѯ�ҿ�����
{
    coursecnt();//���ÿγ�������
    creditcnt();//������ѧ�ֺ���
    int i;
    for(i=0;i<31;i++)
    {

        if(student[i].lownum>0)
        {
            printf("�ҿ�ѧ��������Ϣ��\n");
            printf("%d    %s    �ҿ�%d��\n",student[i].id,student[i].name,student[i].lownum);
            if(student[i].english<60&&student[i].english!=0)
            {//Ӣ��ɼ�
             printf("��ѧӢ�%d\n",student[i].english);
            }
             if(student[i].marks<60&&student[i].marks!=0)
            {//Ӣ��ɼ�
             printf("���˼�������ԭ��%d\n",student[i].marks);
            }
             if(student[i].laywer<60&&student[i].laywer!=0)
            {//Ӣ��ɼ�
             printf("˼�ޣ�%d\n",student[i].laywer);
            }
             if(student[i].geob<60&&student[i].geob!=0)
            {//Ӣ��ɼ�
             printf("����ѧ��%d\n",student[i].geob);
            }
             if(student[i].celiangb<60&&student[i].celiangb!=0)
            {//Ӣ��ɼ�
             printf("����ѧB��%d\n",student[i].celiangb);
            }
             if(student[i].math<60&&student[i].math!=0)
            {//Ӣ��ɼ�
             printf("�ߵ���ѧ��%d\n",student[i].math);
            }
             if(student[i].phyb<60&&student[i].phyb!=0)
            {//Ӣ��ɼ�
             printf("����ʵ�飺%d\n",student[i].phyb);
            }
             if(student[i].phyc<60&&student[i].phyc!=0)
            {//Ӣ��ɼ�
             printf("��ѧ����%d\n",student[i].phyc);
            }
             if(student[i].algebra<60&&student[i].algebra!=0)
            {//Ӣ��ɼ�
             printf("�ߵȴ�����%d\n",student[i].algebra);
            }
             if(student[i].math2<60&&student[i].math2!=0)
            {//Ӣ��ɼ�
             printf("������ѧ������%d\n",student[i].math2);
            }
	if(student[i].matlab<60&&student[i].matlab!=0)
            {//Ӣ��ɼ�
             printf("matlab��%d\n",student[i].matlab);
            }
            if(student[i].logic<60&&student[i].logic!=0)
            {//Ӣ��ɼ�
             printf("�����߼���%d\n",student[i].logic);
            }
            if(student[i].celiang2<60&&student[i].celiang2!=0)
            {//Ӣ��ɼ�
             printf("����ѧʵ�飺%d\n",student[i].celiang2);
            }
	if(student[i].clanguage2<60&&student[i].clanguage2!=0)
            {//Ӣ��ɼ�
             printf("C���Կ��裺%d\n",student[i].clanguage2);
            }









        }
    }

}
void write()//д���������ļ�
{
    FILE *fp1;
	int i=0,j;
	fp1=fopen("sort.txt","w+");
	if(fp1==NULL)
    {
        printf("file open error\n");

    }
    GPA();
    double creditsort[31];

    double temp;
    for(i=0;i<31;i++)
    {
        creditsort[i]=student[i].gpa;


    }
        for(i=0;i<31;i++)
        {
    for(j=30;j>i;j--)
        {
            if(creditsort[j]<creditsort[j-1])
            {
             temp=creditsort[j-1];
                creditsort[j-1]=creditsort[j];
                creditsort[j]=temp;
            }

        }
    }
      for(i=0;i<31;i++)
    {
        for(j=0;j<31;j++)
        {

            if(student[j].gpa==creditsort[i])
            {

                fprintf(fp1,"%d %s %.2f\n",student[j].id,student[j].name,student[j].gpa);
            }

        }
    }
    printf("�ļ��洢��ɣ�����sort.txt�в鿴\n");
fclose(fp1);
}
void menu()
{
int v,w1;
	 do
	 {
		 printf("\n\n\n\n");
		 printf("\t\t<_______________________THE MENU_________________________>\n");
		 printf("\n");
		 printf("\t\t||                    (1) �� �� ͳ ��                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
         printf("\t\t||                    (2) �� �� ͳ ��                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (3) ��ѯ������Ϣ                  ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (4) ��ѯ�ҿ���Ϣ                  ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (5) �洢������Ϣ                  ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (6)    �� ��                      ||\n");
		 printf("\t\t||______________________________________________________||\n");
		 printf("\n\n\t\t ��ѡ�����(1--6):< >\b\b");
		 scanf("%d",&v);
		 if(v<1||v>6)
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
	 case 1:count();break;
	 case 2:sortgpa();break;
	 case 3:queryInformation();break;
	 case 4:queryLow();break;
	 case 5:write();break;
	 case 6:flag=0;break;
	 }
}


