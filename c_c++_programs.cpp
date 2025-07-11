/* ------------ ------------ ------------ ------------ ------------*/
//                      C, C++ Programming
/* ------------ ------------ ------------ ------------ ------------*/

/*------------ ------------ ------------ */
//    1. Simple C++ example of an array
/*------------ ------------ ------------ */

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int A[n];  // Variable-length array (allowed in GCC, not standard in C++)

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];  // Read each element into the array
    }

    cout << "You entered:\n";

    // for each loop
    for (int x : A) {
        cout << x << endl;  // Range-based for loop to print each element
    }

    return 0;
}

/*------------ ------------ ------------ */
//              2. Using Struct
/*------------ ------------ ------------ */

#include <stdio.h>
#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
    char x;
} r1;

// struct Rectangle r1, r2 -- this also works

int main() {
    
    r1.length = 10;
    r1.breadth = 5;
    
    // local declaration - this also works
    // struct Rectangle r1 = {10,5};
    
    std::cout << "Length = " << r1.length << std::endl;
    std::cout << "Breadth = " << r1.breadth << std::endl;
    cout << "Area = " << r1.length * r1.breadth << endl;
    std::cout << "Size of r1 = " << sizeof(r1) << " bytes" << std::endl;

    return 0;
}

Length = 10
Breadth = 5
Area = 50
Size of r1 = 12 bytes 

Note
1. char takes 1 byte, but it reserves max bytes because it is enclosed inside Struct where the max_len(data_type) = 4 bytes

/*------------ ------------ ------------ */
//           3.a. Pointers | C variant
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


Pointer is located at 0x7ffdd6cffafc
a = 10
dereferencing p = 10
This will show where p itself is located = 0x7ffdd6cffb00 (stack)
This will show where a is located = 0x7ffdd6cffafc (stack)

/*------------ ------------ ------------ */
//            3.b. Pointers | C++ variant
/*------------ ------------ ------------ */
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p; // Pointer

    p = &a; // assign address of a

    cout << a << endl;
    cout << "Address of a in stack = " << p << endl;
    cout << "Value of a = " << *p << endl;

    return 0;
}

10
Address of a in stack = 0x7fff597ad41c
Value of a = 10

/*------------ ------------ ------------ */
//         3.c. Pointer to an array
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

Print all elements of an array using A[i]
2
4
6
8
10
-------------
Print all elements of an array using p[i]
2
4
6
8
10

/*------------ ------------ ------------ */
//  3.d. Pointers : create array in heap | C 
/*------------ ------------ ------------ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int val = 10;
    int size = 5;

    // create an array in heap
    p = (int*)malloc(size*sizeof(int));

    // initialize the values in the heap
    for (int i = 0; i < size; i++){
        p[i] = val;
        val = val + 10;
    }

    // display the values using pointer
    for (int i = 0; i < size; i++){
        printf("A[%d] = %d\n",i,p[i]);
    }
    
    // display the address of array
    printf("Address of array in Heap = %p\n",p);

    // free the allocated memory from heap
    free(p);

    return 0;
}

A[0] = 10
A[1] = 20
A[2] = 30
A[3] = 40
A[4] = 50
Address of array in Heap = 0x623f543d62a0

/*------------ ------------ ------------ */
//  3.d. Pointers : create array in heap | C++
/*------------ ------------ ------------ */

#include <iostream>
using namespace std;

int main()
{
    int *p;
    int val = 10;
    int size = 5;

    // create an array in heap
    p = new int[5];

    // initialize the values in the heap
    for (int i = 0; i < size; i++){
        p[i] = val;
        val = val + 10;
    }

    // display the values using pointer
    for (int i = 0; i < size; i++){
        cout << "A[" << i << "] = " << p[i] << endl;
    }
    
    // display the address of array
    cout << "Address of array in heap = " << p << endl;

    // free the allocated memory from heap
    delete[] p;

    return 0;
}

A[0] = 10
A[1] = 20
A[2] = 30
A[3] = 40
A[4] = 50
Address of array in heap = 0x639abf51b2b0


/*------------ ------------ ------------ */
// 3.e. Pointers : size
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

8
8
8
8
8


/*------------ ------------ ------------ */
//  4. Reference - only in C++
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

------ before any update ----- 
a = 10
r = 10
address(a) = 0x7ffdd2775ccc
address(r) = 0x7ffdd2775ccc
------ after r++ ----- 
a = 11
r = 11
address(a) = 0x7ffdd2775ccc
address(r) = 0x7ffdd2775ccc

/*------------ ------------ ------------ */
//  5a. Structure to Pointer | Structure in Stack
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


Length = 10
Breadth = 5
Area = 50


/*------------ ------------ ------------ */
//  5b. Structure to Pointer | Structure in Heap
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


Length = 10
Breadth = 5
Size of Rectangle in Heap = 8
Area = 50


/*------------ ------------ ------------ */
//  5c. Structure to Pointer | Structure in Heap | just the easy way of the above
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
    Rectangle *p;
    
    // create the memory in heap (C++ - the struct keyword can be omitted)
    p = new Rectangle;

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

Length = 10
Breadth = 5
Size of Rectangle in Heap = 8
Area = 50


/*------------ ------------ ------------ */
//  6. Function
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

Sum is 15


/*------------ ------------ ------------ */
//  6.a Function | Call by value
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

Inside main : before swap
a = 10
b = 20


------ before swap -----
temp = 1
x = 10
y = 20
------ after swap -----
temp = 10
x = 20
y = 10


Inside main : after swap
a = 10
b = 20

/*------------ ------------ ------------ */
//  6.b Function | Call by address
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

Inside main : before swap
a = 10
b = 20
address(a) = 0x16b433248
address(b) = 0x16b433244


------ before swap -----
temp = 1
x = it should be address of a = 0x16b433248
y = it should be address of b = 0x16b433244
value (x which means a ) = 10
value (y which means b ) = 20

------ after swap -----
temp = 10
x = it should be address of a = 0x16b433248
y = it should be address of b = 0x16b433244
value (x which means a ) = 20
value (y which means b ) = 10


Inside main : after swap
a = 20
b = 10
address(a) = 0x16b433248
address(b) = 0x16b433244


/*------------ ------------ ------------ */
//  6.c Function | Call by reference | only C++
/*------------ ------------ ------------ */

# include <iostream>
using namespace std;

void swap (int &x, int &y)
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

Inside main : before swap
a = 10
b = 20


------ before swap -----
temp = 1
x = 10
y = 20
------ after swap -----
temp = 10
x = 20
y = 10


Inside main : after swap
a = 20
b = 10

/******************************************************************************
7a. Array as parameter
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
    int A[ ] = {2,4,6,8,10};
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

main : size of Array = 5
main : address of array A using : &A[0] = 0x7ffeb8ada6b0
main : address of array A using : A = 0x7ffeb8ada6b0
main : address of array A using : &A = 0x7ffeb8ada6b0

fun : A is = 0x7ffeb8ada6b0
2
4
6
8
10
array values are after fun call. Expecting A[0] = 15
15
4
6
8
10

/*------------ ------------ ------------ */
//  7b. Function returning array
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

--- main starts ---
--- Fun starts ---
n = 5
p (heap address of the array) = 0x5b4bead846c0
--- Fun ends ---
Address of Array A = 0x5b4bead846c0
Size of Array A = 5
A[0] = 10
A[1] = 20
A[2] = 30
A[3] = 40
A[4] = 50
--- main ends ---
