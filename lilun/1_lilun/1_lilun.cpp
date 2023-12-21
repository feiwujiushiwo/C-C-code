#include <stdio.h>

#define MAX_DEGREE 100
typedef struct Poly
{
    int data[MAX_DEGREE];
    int degree; // 多项式最大项次数
} Poly;
int AddPolyn(Poly *p1, Poly *p2, Poly *p3)
{
    if (p1->degree > p2->degree)
    {
        p3->degree = p1->degree;
        for (int i = 0; i <= p2->degree; i++)
            p3->data[i] = p1->data[i] + p2->data[i];
        for (int i = p2->degree + 1; i <= p3->degree; i++)
            p3->data[i] = p1->data[i];
    }
    else if (p1->degree <= p2->degree)
    {
        p3->degree = p2->degree;
        for (int i = 0; i <= p1->degree; i++)
            p3->data[i] = p1->data[i] + p2->data[i];
        for (int i = p1->degree + 1; i <= p3->degree; i++)
            p3->data[i] = p2->data[i];
    }
    return 0;
}
int PrintPolyn(Poly *p)
{
    for (int i = 0; i <= p->degree; i++)
    {
        if (p->data[i] == 0)
            continue;
        if (i==0){
            printf("%d+",p->data[i]);
            continue;
        }
        if (i < p->degree)
        {
            printf("%dX^%d+", p->data[i], i);
        }else
            printf("%dX^%d",p->data[i],i);
    }
    return 0;
}
int main()
{
    Poly poly1;
    Poly poly2;
    Poly poly3;
    printf("多项式1最大项次数");
    scanf("%d", &poly1.degree);
    printf("多项式1的系数\n");
    for (int i = 0; i <= poly1.degree; i++)
    {
        scanf("%d", &poly1.data[i]); 
    }
    printf("多项式2最大项次数");
    scanf("%d", &poly2.degree);
    printf("多项式2的系数\n");
    for (int i = 0; i <= poly2.degree; i++)
    {
        scanf("%d", &poly2.data[i]);
    }
    AddPolyn(&poly1, &poly2, &poly3);
    PrintPolyn(&poly3);
    return 0;
}
