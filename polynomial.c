/*---------------------------------------------------------------
 Polynomial - create, evaluation, addition
----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    printf("Enter the number of non-zero terms : ");
    scanf("%d",&p->n);

    p->terms = (struct Term*)malloc(p->n * sizeof(struct Term));

    printf("Enter the terms : \n");

    for(int i=0; i<p->n; i++)
    {
        printf("Term : %d\n",i+1);
        printf("Coeff : ");
        scanf("%d",&p->terms[i].coeff);
        printf("Exp : ");
        scanf("%d",&p->terms[i].exp);
        printf("----------\n");
    }
}

void display(struct Poly p)
{
    for(int i=0; i<p.n; i++)
    {
        if(p.terms[i].exp==0)
        {
            printf("%d",p.terms[i].coeff);
        }
        else
        {
            printf("%dx^%d",p.terms[i].coeff,p.terms[i].exp);
        }
        if (i != p.n-1)
        {
            printf("+");
        }
        
    } 
    printf("\n");
}

int evaluatePolynomial(struct Poly p,int x) 
{
    int sum = 0;
    for(int i=0; i<p.n; i++)
    {
        sum += p.terms[i].coeff*pow(x,p.terms[i].exp);
    }
    return sum;
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i = 0, j = 0, k = 0;
    struct Poly *sum;

    sum = (struct Poly*)malloc(sizeof(struct Poly));
    sum->terms=(struct Term *)malloc((p1->n+p2->n)*sizeof(struct Term));

    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++];
        else if(p2->terms[j].exp > p1->terms[i].exp)
            sum->terms[k++] = p2->terms[j++];
        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    for(;i<p1->n;i++)
        sum->terms[k++] = p1->terms[i];

    for(;j<p2->n;j++)
        sum->terms[k++] = p2->terms[j];

    sum->n = k;
    return sum;
}

int main()
{
    struct Poly p1, p2;
    struct Poly *p3;

    int eval_result=0;
    int eval_value = 4;

    create(&p1);
    display(p1);

    create(&p2);
    display(p2);
    // eval_result = evaluatePolynomial(p1,eval_value);
    // printf("Polynomial value for :%d is : %d",eval_value,eval_result);

    p3 = add(&p1,&p2);
    display(*p3);
    return 0;
}
