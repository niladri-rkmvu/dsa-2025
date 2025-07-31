/*------------ ------------ ------------ */
//         Pointers
/*------------ ------------ ------------ */

#include <stdio.h>

int main() {
    int a = 10; // data
    int *p = &a; // pointer
    
    printf("Pointer is located at %p\n", p); // expecting address of 'a' present in p
    printf("a = %d\n", a); // expecting 10
    printf("dereferencing p = %d\n", *p); // expecting 10

    printf("This will show where p itself is located = %p\n", &p);
    printf("This will show where a is located = %p\n", &a);

    return 0;
}

/*------------ ------------ ------------ */
//         Pointer to an array
/*------------ ------------ ------------ */

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int A[5] = {2,4,6,8,10};
    int *p;

    // Note here we don't have to give & here. 
    // The name is the start address
    // use p = &A[0] or the below; don't write &A
    p = A;

    cout << "Print all elements of an array using A[i]" << endl;

    int n = sizeof(A) / sizeof(A[0]); // size of the array

    for(int i =0; i<n; i++){
        cout << A[i] << endl;
    }

    cout << "-------------" << endl;
    cout << "Print all elements of an array using p[i]" << endl;

    for(int i =0; i<n; i++){
        cout << p[i] << endl;
    }

    return 0;
}

/*------------ ------------ ------------ */
//         Create Array in Heap
/*------------ ------------ ------------ */


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(5*sizeof(int));
    printf("Address is = %p\n",p);

    printf("Enter the values in heap memory \n");

    for(int i=0; i<5; i++)
    {
        scanf("%d",&p[i]);
    }

    printf("Displaying the values : \n");

    for(int i=0; i<5; i++)
    {
        printf("%d\n",p[i]);
    }

    free(p);
    return 0;
}

/*------------ ------------ ------------ */
//  Pointers : size
/*------------ ------------ ------------ */

#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
} r1;

int main()
{
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;


    return 0;
}

/*------------ ------------ ------------ */
//  Reference - only in C++
/*------------ ------------ ------------ */

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a; // creating a reference or alias

    cout << "------ before any update ----- " << endl;
    cout << "a = " << a << endl;
    cout << "r = " << r << endl;
    cout << "address(a) = " << &a << endl;
    cout << "address(r) = " << &r << endl;
    r++;
    cout << "------ after r++ ----- " << endl;
    cout << "a = " << a << endl;
    cout << "r = " << r << endl;
    cout << "address(a) = " << &a << endl;
    cout << "address(r) = " << &r << endl;
    
    return 0;
}


/*------------ ------------ ------------ */
//  Structure to Pointer | Structure in Stack
/*------------ ------------ ------------ */

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main()
{
    struct Rectangle *p; // create the pointer = default size = 8 bytes
    struct Rectangle r; // it will create the struct in stack
    // Rectangle r is also valid in C++

    p = &r;
    
    // now to access length and breadth 
    p->length = 10;
    p->breadth = 5;

    // (*p).length = 10; works. But the above is better
    
    cout << "Length = " << p->length << endl << "Breadth = " << p->breadth << endl;
    cout << "Area = " << p->length * p->breadth  << endl;
    
    return 0;
}

/*------------ ------------ ------------ */
//  Structure to Pointer | Structure in Heap
/*------------ ------------ ------------ */

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main()
{
    struct Rectangle *p;

    // create the memory in heap (C++ - the struct keyword can be omitted)
    p = (struct Rectangle *) malloc (sizeof(struct Rectangle));

    // p = new Rectangle;
    // p = new Rectangle{10, 5};
    
    /* 
        Rectangle* p = new Rectangle[5];  // Creates array of 5 Rectangles on heap
        p[0].length = 10;
        p[0].breadth = 20;
    */

    // now to access length and breadth 
    p->length = 10;
    p->breadth = 5;
    
    cout << "Length = " << p->length << endl << "Breadth = " << p->breadth << endl;
    cout << "Size of Rectangle in Heap = " << sizeof(p) << endl;
    cout << "Area = " << p->length * p->breadth  << endl;
    
    // free heap
    delete[] p;
    
    return 0;
}

/*------------ ------------ ------------ */
//  Function
/*------------ ------------ ------------ */

# include <iostream>
using namespace std;

int add (int a, int b){
    return a + b;
}

int main(){
    int x = 10, y = 5, sum;
    sum = add(x,y);
    cout << "Sum is " << sum << endl;
    return 0;
}

/*------------ ------------ ------------ */
//  Function | Call by value
/*------------ ------------ ------------ */

# include <iostream>
using namespace std;

void swap (int x, int y)
{
    
    int temp;
    cout << "------ before swap -----" << endl;
    cout << "temp = " << temp << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    temp = x;
    x = y;
    y = temp;
    cout << "------ after swap -----" << endl;
    cout << "temp = " << temp << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    cout << "Inside main : before swap" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl << endl << endl;
    swap(a,b);
    cout << endl << endl << "Inside main : after swap" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}


/*------------ ------------ ------------ */
//  Function | Call by address
/*------------ ------------ ------------ */

# include <iostream>
using namespace std;

void swap (int *x, int *y)
{
    
    int temp;
    cout << "------ before swap -----" << endl;
    cout << "temp = " << temp << endl;
    cout << "x = it should be address of a = " << x << endl;
    cout << "y = it should be address of b = " << y << endl;
    cout << "value (x which means a ) = " << *x << endl;
    cout << "value (y which means b ) = " << *y << endl;

    // dereferencing pointer
    temp = *x; 

    // this means I want to change the [value of address showing in *x] with the value that I get in *y
    *x = *y; 
    
    *y = temp;
    cout << "------ after swap -----" << endl;
    cout << "temp = " << temp << endl;
    cout << "x = it should be address of a = " << x << endl;
    cout << "y = it should be address of b = " << y << endl;
    cout << "value (x which means a ) = " << *x << endl;
    cout << "value (y which means b ) = " << *y << endl;
}

int main()
{
    int a = 10;
    int b = 20;

    cout << "Inside main : before swap" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "address(a) = " << &a << endl;
    cout << "address(b) = " << &b << endl << endl << endl;

    swap(&a,&b);

    cout << endl << endl << "Inside main : after swap" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "address(a) = " << &a << endl;
    cout << "address(b) = " << &b << endl << endl << endl;

    return 0;
}

/******************************************************************************
// Array as parameter
*******************************************************************************/
#include <iostream>
using namespace std;

void fun(int A[], int size)
{
    /*
        Here A is a pointer to an Array
        sizeof(A) will not work
        nor for-each loop
    */
   cout << "fun : A is = " << A << endl;
    
   for(int i=0; i < size; i++)
   {
       cout << A[i] << endl;
   }

   // if i change A[0] = 15. it will change the original array
   A[0] = 15;
}

int main()
{
    int A[] = {2,4,6,8,10};
    int size = sizeof(A) / sizeof(A[0]);
    cout << "main : size of Array = " << size << endl;
    cout << "main : address of array A using : &A[0] = " << &A[0] << endl;
    cout << "main : address of array A using : A = " << A << endl;
    cout << "main : address of array A using : &A = " << &A << endl << endl;
    fun(A,size);

    cout << "array values are after fun call. Expecting A[0] = 15" << endl;

    for(int a:A)
        cout << a << endl;
    return 0;
}

/*------------ ------------ ------------ */
//  Function returning array
/*------------ ------------ ------------ */

# include <iostream>
using namespace std;

int * fun (int n)
{
    int *p, val=10, i = 0;
    cout << "--- Fun starts ---" << endl;
    
    cout << "n = " << n << endl;

    // create the array in heap
    // p = (int *)malloc(n*sizeof(int));
    p = new int[n];
    
    cout << "p (heap address of the array) = " << p << endl;

    // assign the values of array
    for (i=0; i<n; i++)
    {
        p[i] = val;
        val += 10;
    }
    
    cout << "--- Fun ends ---" << endl;

    // return array as the parameter
    return p;
}

int main()
{
    cout << "--- main starts ---" << endl;
    int *A, i, size=5;

    A = fun(size);

    // print the address of the array
    cout << "Address of Array A = " << A << endl;
    
    // print the size of the array
    cout << "Size of Array A = " << size << endl;

    // print the array here
    for (i=0; i<size; i++)
    {
        cout << "A[" << i << "] = " << A[i] << endl;
    }

    // free the heap
    delete[] A;

    cout << "--- main ends ---" << endl;

    return 0;
}
