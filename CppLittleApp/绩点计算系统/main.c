#include <stdio.h>
#include <stdlib.h>
struct gpa
{
    char name[20];
    float score;
    float credit;
    struct gpa *next;
};
struct gpa* input()
{system("color 24");
    struct gpa *p1,*p2,*head;

    p1=p2=(struct gpa *)malloc(sizeof(struct gpa));
    scanf("%s%f%f",p1->name,&p1->score,&p1->credit);


    head=p1;
    p2=p1;
    while(p1->score!=0)
    {p2->next=p1;
    p2=p1;

    p1=(struct gpa *)malloc(sizeof(struct gpa));
    scanf("%s%f%f",p1->name,&p1->score,&p1->credit);

    }
 p2->next=NULL;
 return head;
}

void GPa(struct gpa *p)
{struct gpa *pt=p;
    float temp,temp2;
int temp1,temp4;

    double sumscore=0,sumcredit=0;
    double Gpa;
    while(pt!=NULL)
    {
        temp1=(pt->score-60)/10;
        temp=(pt->score-60)/10;
        temp2=temp-temp1;
        temp4=(pt->score-50)/10;
        if(temp2>=0.5)
        {
            pt->score=temp4+0.5;
        }
        if(temp2<0.5)
        {
            pt->score=temp4;
        }

        sumscore=sumscore+pt->score*pt->credit;
        sumcredit=sumcredit+pt->credit;
        pt=pt->next;
    }
    Gpa=(double)sumscore/sumcredit;
    printf("ͬѧ���ƽ������Ϊ%.2f\n",Gpa);
    if(Gpa>=3.0&&Gpa<4.0)
    {
        printf("ͬѧ��ĳɼ������㰡���ٽ�����\n");
    }
    if(Gpa>=4.0)
    {
        printf("ͬѧ����Ҫ�ù��ҽ�ѧ����ѧ��\n");
    }
    if(Gpa>=1.8&&Gpa<3.0)
    {
        printf("�ɼ�һ�㣬��ҪŬ����\n");
    }
    if(Gpa<1.8)
    {
        printf("��ҵ��������������Ͱ�\n");
    }
}

void display(struct gpa* p)
    {
        struct gpa *p1=p;
        while(p1!=NULL)
        {
             printf("%10s%6.2f%6.2f\n",p1->name,p1->score,p1->credit);
             p1=p1->next;
        }
    }

int main()
{int b;
    struct gpa * pp;
    int i;
    for(i=0;i<100;i++)
    {
    pp=input();
system("color 24");
    printf("����������Ҫ�Ĳ���\n");
    printf("*****************************\n");
    printf("        1:�������ɼ�       \n");
    printf("        2:�������           \n");
    printf("*****************************\n");
     printf("����������Ҫ�Ĳ���\n");
     scanf("%d",&b);
     switch(b)
     {
         case 1:display(pp);break;
         case 2:GPa(pp);break;
     }
    }
}
