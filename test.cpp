#include<stdio.h>
#include<stdlib.h>
typedef  struct
{
    char  name[10];
    int  score;
} student;

void InsertSort(student a[], int n) 
{
    int i, j, flag;
    student temp;
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (a[j].score < a[j + 1].score) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

//=============================
void SelectionSort(student a[],int n)//简单选择排序
{
    int i,j,k;
    student temp;
    for(i=0; i<n; i++)
    {
        k=i;
        for(j=i; j<n; j++)
        {
            if(a[j].score>a[k].score)  k=j;
        }
        if(k!=i)
        {
            temp=a[i];
            a[i]=a[k];
            a[k]=temp;
        }
    }
}
int main()
{
    int n,i,k,t;
    student *a;
    printf("您要输入多少个学生的信息？\n");
    scanf("%d",&n);
    a=(student *)malloc(n*sizeof(student));
    printf("请输入学生姓名和成绩：\n");
    for(i=0; i<n; i++)
    {
        scanf("%s %d",&a[i].name,&a[i].score);
    }
    printf("您想使用哪种排序算法？(1)使用直接插入排序,(2)使用简单选择排序\n");
    scanf("%d",&k);
    if(k==1)
    {
        InsertSort(a,n);
    }
    else if(k==2)
    {
        SelectionSort(a,n);
    }
    printf("第%d名:   %s   %d\n",1,a[0].name,a[0].score);
    t=1;
    for(i=1; i<n; i++)
    {
        if(a[i].score==a[i-1].score)
        {
            printf("第%d名:   %s   %d\n",t,a[i].name,a[i].score);
        }
        else
        {
            t=i+1;
            printf("第%d名:   %s   %d\n",t,a[i].name,a[i].score);
        }
    }
    free(a);
    return 0;
}

