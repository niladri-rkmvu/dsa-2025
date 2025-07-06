/****************************
  1. Recusrsion
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

void fun2(int n)
{
    cout << "called fun2 (n) => " << n << endl;
    if (n > 0)
    {
        fun2(n-1);
        cout << n << endl;
    }
}

int main()
{
    int x = 3;
    fun2(3);
    return 0;
}

called fun2 (n) => 3
called fun2 (n) => 2
called fun2 (n) => 1
called fun2 (n) => 0
1
2
3

/****************************
  2. recursion
*****************************/

#include <stdio.h>
#include <iostream>
using namespace std;

void fun(int n);  // Function prototype

int main(void)
{
    int x=3;
    fun(x);
    return 0;
}

void fun(int n)
{
    if (n>0)
    {
        fun(n-1) + n;
        printf("%d ",n);
    }
}

/****************************
  3. Static-Global
*****************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int x = 0;

int fun(int n){
    //static int x = 0; -- same effect as global
    if (n>0){
        x++;
        return fun(n-1) + x;
    }
    return 0;
}

int main() {
    int a = 5, ret_val;
    ret_val = fun(a);
    printf("%d\n",ret_val);
    
    ret_val = fun(a);
    printf("%d\n",ret_val);
    return 0;
}

25
50

/****************************
  4. Tree recursion
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

void fun(int n)
{
    if (n>0)
    {
        printf("%d ",n);
        fun(n-1);
        fun(n-1);
    }
}

int main()
{
    fun(3);
    return 0;
}

3 2 1 1 2 1 1

/****************************
  5. Indirect recursion
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

void functionA(int n);
void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        printf("A: %d\n", n);
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        printf("B: %d\n", n);
        functionA(n / 2);
    }
}

int main() {
    functionA(10);
    return 0;
}

A: 10
B: 9
A: 4
B: 3
A: 1

/****************************
  6. Nested Recursion
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int fun(int n)
{
    if (n > 100)
    {
        return n - 10;
    }
    else
    {
        return fun(fun(n + 11));
    }
}

int main() {
    int result = fun(95);
    printf("Result: %d\n", result);
    return 0;
}

Result: 91

/****************************
7a. Sum of natural numbers | using recursion
   Time = O(n)
   Space = O(n)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int sum(int n)
{
    if (n==0)
        return 0; 
    return sum(n-1) + n;
}

int main()
{
    int result = sum(7);
    cout << "Result = " << result << endl;
}

Result = 28

/****************************
7.b Sum of natural numbers | direct formula use
    Time = O(1)
    Space = O(1)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int sum(int n)
{
   return (n*(n+1))/2;
}

int main()
{
    int result = sum(7);
    cout << "Result = " << result << endl;
}

/****************************
7.c Sum of natural numbers | using loop
#   Time = O(n)
#   Space = O(1)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int sum_iterative(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

int main() {
    int result = sum_iterative(7);
    printf("Result = %d\n", result);
    return 0;
}

/****************************
8a. Factorial of a number
    Method : Recursion
    Time : O(n)
    Space : O(n)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int fact(int n)
{
    if (n==0)
        return 1;
    return n * fact(n-1);
}

int main()
{
    int x=5, result = fact(5);
    cout << x << "!= " << result << endl;
    return 0;
}

/****************************
8b. Factorial of a number
    Method : iteration (for loop)
    Time : O(n)
    Space : O(1)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int fact(int n)
{
    int result = 1;
    
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int main()
{
    int x = 2;
    int result = fact(x);
    cout << x << "! = " << result << endl;
    return 0;
}

/****************************
8c. Factorial of a number
    Method : iteration (while loop)
    Time : O(n)
    Space : O(1)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int fact(int n)
{
    int result = 1;
    int i = 2;

    while (i <= n)
    {
        result *= i;
        i++;
    }

    return result;
}

int main()
{
    int x = 2;
    int result = fact(x);
    cout << x << "! = " << result << endl;
    return 0;
}

/****************************
9a. Exponent
    Method  : Recursion
    Time    : O(n)
    Space   : O(n)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int power_recursive(int m, int n) {
    if (n == 0)
        return 1;
    return m * power_recursive(m, n - 1);
}

int main() {
    int m = 2, n = 5;
    cout << m << "^" << n << " = " << power_recursive(m, n) << endl;
    return 0;
}

/****************************
9b. Exponent
    Method  : Using loop
    Time    : O(n)
    Space   : O(1)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int power_iterative(int m, int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= m;
    }
    return result;
}

int main() {
    int m = 2, n = 5;
    cout << m << "^" << n << " = " << power_iterative(m, n) << endl;
    return 0;
}

/****************************
9c. Exponent
    Method  : exponent squaring method
    Time    : O(log n)
    Space   : O(log n)
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int power_fast(int m, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power_fast(m * m, n / 2);
    else
        return m * power_fast(m * m, (n - 1) / 2);
}

int main() {
    int m = 2, n = 10;
    cout << m << "^" << n << " = " << power_fast(m, n) << endl;
    return 0;
}

/****************************
10.a. Taylor series = e^x
*****************************/
#include <stdio.h>
#include <iostream>
using namespace std;

// Recursive function for Taylor series
double e(int x, int n) {
    static double p = 1, f = 1;
    double r;

    if (n == 0)
        return 1;

    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + (p / f);
}

int main() {
    int x = 2; // Initialize x here = this is power of e
    int n = 6; // Number of terms = how far we may want to approximate
    double result = e(x, n);
    cout << "Function = e^" << x << " | No. of terms = " << n << " | Result = " << result << endl;
    return 0;
}

Function = e^2 | No. of terms = 6 | Result = 7.35556

/****************************
10.b. Taylor series = e^x
Method : Iterative
*****************************/
#include <iostream>
#include <stdio.h>
using namespace std;

double e(int x, int n)
{
    double s = 1;
    int i;
    double num=1;
    double den=1;

    for(i=1; i<=n; i++){
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main()
{
    printf("%lf \n",e(2,10));
    return 0;
}

/****************************
10.c. Taylor series = e^x | Horner's rule
Method : Recursion
Multiplication time = O(n)
*****************************/
#include <iostream>
#include <stdio.h>
using namespace std;

double e(int x, int n)
{
    static double s;
    if(n==0)
        return s;
    s= 1 + ((x*s)/n);
    return e(x,n-1);
}

int main()
{
    printf("%lf \n",e(2,10));
    return 0;
}

/****************************
11.a. Fibonacci series
Method : Loop (iterative)
*****************************/
#include <iostream>
#include <stdio.h>
using namespace std;

int fibonacci(int n) 
{
    int t0 = 0, t1 = 1, s, i;

    if (n<=1)
        return n;

    for (i=2; i<=n; i++)
    {
        s = t0+t1;
        t0 = t1; 
        t1 = s;
    }

    return s;

}
    
int main() {
    int number = 5;
    int result = fibonacci(number);
    
    cout << "The " << number << "th Fibonacci number is " << result << endl;
    return 0;
}

/****************************
11.b. Fibonacci series
Method : Recursion
*****************************/
#include <iostream>
#include <stdio.h>
using namespace std;

// Recursive Fibonacci function
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int number = 6;
    int result = fibonacci(number);
    
    cout << "The " << number << "th Fibonacci number is " << result << endl;
    return 0;
}

/****************************
11.c. Fibonacci series
Method : Recursion using memoization
*****************************/
#include <iostream>
#include <stdio.h>
using namespace std;

int F[10];

int mfib(int n) {
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(F[n-2] == -1)
            F[n-2] = mfib(n-2);

        if(F[n-1] == -1)
            F[n-1] = mfib(n-1);

        return F[n-2] + F[n-1];
    }
}

int main() {
    int i, result;

    for(i=0; i<10; i++)
        F[i] = -1;

    result = mfib(5);
    cout << "Result of mfib(5) = " << result << endl;

    return 0;
}


/****************************
12.a.    nCr
Method : Formula based approach using factorial
*****************************/
#include <iostream>
#include <stdio.h>
using namespace std;

int fact(int n)
{
    if (n==0)
        return 1;
    return n * fact(n-1);
}

int C(int n, int r)
{
    if (r < 0 || r > n)
        return -1;
    return fact(n)/(fact(r) * fact(n-r));
}

int main()
{
    cout << "C(4,2) = " << C(4,2) << endl;
    return 0;
}

/****************************
12.b.    nCr
Method : Using Pascal triangle
*****************************/
#include <iostream>
#include <stdio.h>
using namespace std;

int C(int n, int r)
{
    if (r < 0 || r > n)
        return -1;
    
    // base case
    if (r==0 || n==r)
        return 1;
    else
        return (C(n-1,r-1) + C(n-1,r));
}

int main()
{
    cout << "C(4,2) = " << C(4,2) << endl;
    return 0;
}

/****************************
13.    Tower of Hanoi
*****************************/

#include <iostream>
using namespace std;

void TOH(char source, char destination, char auxiliary, int n) {
    if (n == 1) {
        cout << "Move only disk from " << source << " to " << destination << endl;
        return;
    } else {
        TOH(source, auxiliary, destination, n - 1);
        cout << "Move top disk " << n << " from " << source << " to " << destination << endl;
        TOH(auxiliary, destination, source, n - 1);
    }
}

int main() {
    int num_disks = 3;
    TOH('A', 'B', 'C', num_disks);
    return 0;
}












