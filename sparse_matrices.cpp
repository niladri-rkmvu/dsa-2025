/*---------------------------------------------------------------
 Sparse Matrices
----------------------------------------------------------------*/
/* -------------------------------
1.a Create a sparse matrix | C
----------------------------------*/
#include <stdio.h>
#include <stdlib.h>

struct Element
{
	int i; // represents row
	int j; // represents col
	int x; // represents val
};

struct Sparse
{
	int m; // dimension of matrix = row
	int n; // dimension of matrix = col
	int num; // no. of non zero elements
	struct Element *ele; // pointer for creating the array
};

void create(struct Sparse *s)
{
	printf("Enter Dimensions of the matrix (mxn) : ");
	scanf("%d %d",&s->m, &s->n);
	printf("\n");

	printf("number of non-zero elements : ");
	scanf("%d",&s->num);
	printf("\n");

	s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

	printf("Enter non-zero elements (row, col, val) : \n");

	for(int i=0; i<s->num; i++)
	{
		scanf("%d %d %d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
	}
}

void display(struct Sparse s)
{
	int i, j, k = 0;
	printf("\n");
	printf("displaying matrix \n");

	for(i=0; i<s.m; i++)
	{
		for(j=0; j<s.n; j++)
		{
			if (i == s.ele[k].i && j == s.ele[k].j)
			{
				printf("%d ",s.ele[k++].x);
			}
			else
			{
				printf("0 ");
			}

		}
		printf("\n");
	}
}

int main()
{
	struct Sparse s;
	create(&s);
	display(s);
	return 0;
}


/* -------------------------------
2. Create a sparse matrix | C++
Include add function
Ensure you enter the input from 0 index - for both row and col
----------------------------------*/

#include <iostream>
using namespace std;

struct Element
{
	int i; // represents row
	int j; // represents col
	int x; // represents val
};

struct Sparse
{
	int m; // dimension of matrix = row
	int n; // dimension of matrix = col
	int num; // no. of non zero elements
	struct Element *ele; // pointer for creating the array
};

void create(Sparse *s)
{	
	cout << "Enter Dimensions of matrix : ";
	cin >> s->m >> s->n;
	cout << endl;

	cout << "Enter the number of non-zero elements (should be less than 50% of m×n) : ";
	cin >> s->num;
	cout << endl;

	s->ele = new Element[s->num];

	cout << "Enter non-zero elements (row, col, val) : " << endl;

	for (int i=0; i<s->num; i++)
	{
		cout << "Element[" << i << "].[row][col][val] = ";
		cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
	}
}

Sparse* add(const Sparse* s1, const Sparse* s2)
{
    if(s1->m != s2->m || s1->n != s2->n)
        return nullptr;

    Sparse* sum = new Sparse;
    sum->m = s1->m;
    sum->n = s1->n;
    sum->ele = new Element[s1->num + s2->num];

    int i = 0, j = 0, k = 0;

    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else if (s1->ele[i].j < s2->ele[j].j)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].j > s2->ele[j].j)
            sum->ele[k++] = s2->ele[j++];
        else {
            sum->ele[k].i = s1->ele[i].i;
            sum->ele[k].j = s1->ele[i].j;
            sum->ele[k].x = s1->ele[i].x + s2->ele[j].x;
            ++i; ++j; ++k;
        }
    }

    // if things are leftovers, we just copy them
    
    while (i < s1->num) 
    	sum->ele[k++] = s1->ele[i++];

    while (j < s2->num) 
    	sum->ele[k++] = s2->ele[j++];

    sum->num = k;
    return sum;
}

void display(const Sparse s) {
    int k = 0;
    cout << "\nDisplaying matrix:\n";

    for (int i = 0; i < s.m; ++i) {
        for (int j = 0; j < s.n; ++j) {
            if (k < s.num && i == s.ele[k].i && j == s.ele[k].j) {
                cout << s.ele[k++].x << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    Sparse s1, s2;
    cout << "Matrix 1:\n";
    create(&s1);
    display(s1);

    cout << "Matrix 2:\n";
    create(&s2);
    display(s2);

    Sparse* result = add(&s1, &s2);

    if (result) {
        cout << "\nResultant Matrix After Addition:\n";
        display(*result);
    } else {
        cout << "Cannot add matrices: dimension mismatch.\n";
    }

    delete[] s1.ele;
    delete[] s2.ele;
    delete[] result->ele;
    delete result;

    return 0;
}