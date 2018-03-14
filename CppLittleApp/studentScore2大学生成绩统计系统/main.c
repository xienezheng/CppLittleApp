#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student
{
    int id;//学号
    char name[20];//姓名
	int english;//英语成绩
	int marks;//马克思主义成绩
	int laywer;//思修成绩
	int geob;//地质学成绩
	int celiangb;//测量学成绩
	int math;//高数成绩
	int phyb;//物理实验成绩
	int phyc;//大物c1
	int algebra;//线性代数成绩
	int math2;//数学分析成绩
	int matlab;//matlab成绩
	int logic;//数字逻辑成绩
	int celiang2;//测量学实习成绩
	int clanguage2;//c语言实践

	int coursecnt;//总共所修课程数
	int scorecnt;//总分
	double creditcnt;//总学分
	int lownum;//不及格科目数
	double lowcredit;//不及格学分


	double gpa;//绩点
}student[100];
void GPA();
void menu();
void coursecnt();
void creditcnt();
void count();
void queryCountFirst();
void sortgpa();
void queryInformation();
void queryLow();//查询挂科现象
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
	printf("\t*********************学生成绩管理系统************************\n");
	printf("\n\n\n\t\t 文件读取中，按任意键进入............");
	getchar();
	system("cls");
	printf("文件读取完成,请选择需要的操作\n");

	 while(flag)
     {

	menu();

     }
     return 0;
}
void coursecnt()//统计每个学生所修课程数及总分
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
void creditcnt()//统计每个学生所修学分数及不及格学分数
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

                student[i].creditcnt=sum;//求所修学分数
                   for(j=0;j<14;j++)
                {
                    if(score[j]<60&&score[j]!=0)
                    {


                        cnt++;
                        lowsum=lowsum+credit[j];
                    }

                }
                 student[i].lownum=cnt; //求不及格门数
                  student[i].lowcredit=lowsum; //求不及格门数
    }

}

void count()//班级统计函数
{
    coursecnt();//引用课程数函数
    creditcnt();//引用求学分函数
    int i;
    printf("学号           姓名   所修科目数    总分    总学分   不及格科目数    不及格学分\n");
    for(i=0;i<31;i++)
    {
    printf("%d    %s          %d         %d        %.1f        %d         %.1f\n",student[i].id,student[i].name,student[i].coursecnt,
       student[i].scorecnt,student[i].creditcnt,student[i].lownum,student[i].lowcredit);
    }
}

void queryCountFirst()//在查询前先执行此函数进行计算
{
     coursecnt();//引用课程数函数
    creditcnt();//引用求学分函数
    GPA();
}
void GPA()//计算GPA
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
void sortgpa()//对GPA进行排序
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
    printf("请选择查询方式：\n");
    printf("1:学号查询\n");
    printf("2:姓名查询\n");
    scanf("%d",&n);

    if(n==1)//学号查询
    {printf("请输入学生学号\n");
    scanf("%d",&targetid);
        int i;
        for(i=0;i<31;i++)
        {

            if(student[i].id==targetid)
            {

                printf("该学生基本信息如下\n");
                printf("学号           姓名     所修科目数     总分     总学分           绩点\n");
                printf("%d  %s    %d           %d            %.1f             %.2f\n",student[i].id,student[i].name,student[i].coursecnt,student[i].scorecnt,student[i].creditcnt,student[i].gpa);
             printf("大学英语      马克思主义基本原理      思修      地质学       高数     线代....\n");
             printf("%d                       %d            %d         %d         %d        %d",student[i].english,student[i].marks,student[i].laywer,student[i].geob,student[i].math,student[i].algebra);

            break;
            }
        }
        if(i==31)
        {

            printf("不存在此学生，请检查是否输入有误\n");
            queryInformation();
        }

    }
       else if(n==2)//姓名查询
    {
        printf("请输入学生姓名\n");
    scanf("%s",targetname);
        int i;
        for(i=0;i<31;i++)
        {

            if(strcmp(student[i].name,targetname)==0)
            {

                printf("该学生基本信息如下\n");
                printf("学号           姓名     所修科目数     总分     总学分           绩点\n");
                printf("%d  %s    %d           %d            %.1f             %.2f\n",student[i].id,student[i].name,student[i].coursecnt,student[i].scorecnt,student[i].creditcnt,student[i].gpa);
             printf("大学英语      马克思主义基本原理      思修      地质学       高数     线代....\n");
             printf("%d                       %d            %d         %d         %d        %d\n",student[i].english,student[i].marks,student[i].laywer,student[i].geob,student[i].math,student[i].algebra);

            break;
            }
        }
        if(i==31)
        {

            printf("不存在此学生，请检查是否输入有误\n");
            queryInformation();
        }

    }
   else
    {

        printf("输入有误，请重新输入\n");
        queryInformation();
    }
}
void queryLow()//查询挂科现象
{
    coursecnt();//引用课程数函数
    creditcnt();//引用求学分函数
    int i;
    for(i=0;i<31;i++)
    {

        if(student[i].lownum>0)
        {
            printf("挂科学生基本信息：\n");
            printf("%d    %s    挂科%d门\n",student[i].id,student[i].name,student[i].lownum);
            if(student[i].english<60&&student[i].english!=0)
            {//英语成绩
             printf("大学英语：%d\n",student[i].english);
            }
             if(student[i].marks<60&&student[i].marks!=0)
            {//英语成绩
             printf("马克思主义基本原理：%d\n",student[i].marks);
            }
             if(student[i].laywer<60&&student[i].laywer!=0)
            {//英语成绩
             printf("思修：%d\n",student[i].laywer);
            }
             if(student[i].geob<60&&student[i].geob!=0)
            {//英语成绩
             printf("地质学：%d\n",student[i].geob);
            }
             if(student[i].celiangb<60&&student[i].celiangb!=0)
            {//英语成绩
             printf("测量学B：%d\n",student[i].celiangb);
            }
             if(student[i].math<60&&student[i].math!=0)
            {//英语成绩
             printf("高等数学：%d\n",student[i].math);
            }
             if(student[i].phyb<60&&student[i].phyb!=0)
            {//英语成绩
             printf("物理实验：%d\n",student[i].phyb);
            }
             if(student[i].phyc<60&&student[i].phyc!=0)
            {//英语成绩
             printf("大学物理：%d\n",student[i].phyc);
            }
             if(student[i].algebra<60&&student[i].algebra!=0)
            {//英语成绩
             printf("高等代数：%d\n",student[i].algebra);
            }
             if(student[i].math2<60&&student[i].math2!=0)
            {//英语成绩
             printf("工科数学分析：%d\n",student[i].math2);
            }
	if(student[i].matlab<60&&student[i].matlab!=0)
            {//英语成绩
             printf("matlab：%d\n",student[i].matlab);
            }
            if(student[i].logic<60&&student[i].logic!=0)
            {//英语成绩
             printf("数字逻辑：%d\n",student[i].logic);
            }
            if(student[i].celiang2<60&&student[i].celiang2!=0)
            {//英语成绩
             printf("测量学实验：%d\n",student[i].celiang2);
            }
	if(student[i].clanguage2<60&&student[i].clanguage2!=0)
            {//英语成绩
             printf("C语言课设：%d\n",student[i].clanguage2);
            }









        }
    }

}
void write()//写入排序后的文件
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
    printf("文件存储完成，请在sort.txt中查看\n");
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
		 printf("\t\t||                    (1) 班 级 统 计                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
         printf("\t\t||                    (2) 绩 点 统 计                   ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (3) 查询基本信息                  ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (4) 查询挂科信息                  ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (5) 存储排名信息                  ||\n");
		 printf("\t\t||------------------------------------------------------||\n");
		 printf("\t\t||                    (6)    退 出                      ||\n");
		 printf("\t\t||______________________________________________________||\n");
		 printf("\n\n\t\t 请选择操作(1--6):< >\b\b");
		 scanf("%d",&v);
		 if(v<1||v>6)
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
	 case 1:count();break;
	 case 2:sortgpa();break;
	 case 3:queryInformation();break;
	 case 4:queryLow();break;
	 case 5:write();break;
	 case 6:flag=0;break;
	 }
}


