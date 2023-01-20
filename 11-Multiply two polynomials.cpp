
#include <iostream>
#include <cstring>
using namespace std;
 

int *multiply(int A[], int B[], int m, int n)
{
   int *prod = new int[m+n-1];

   for (int i = 0; i<m+n-1; i++)
    prod[i] = 0;
 
   for (int i=0; i<m; i++)
   {
    for (int j=0; j<n; j++)
        prod[i+j] += A[i]*B[j];
   }
 
   return prod;
}
 

void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
       cout << poly[i];
       if (i != 0)
        cout << "x^" << i ;
       if (i != n-1)
       cout << " + ";
    }
}
 
 
int *multiplyy(int A[], int B[], int m, int n)
{
    int nA0=int(m/2);
    int nA1=m-nA0;
    int *A0 = new int[nA0];
    int *A1 = new int[nA1];
    for (int i=0;i<nA0;i++)
    {
        A0[i]=A[i];
    }
    for (int i=nA0;i<m;i++)
    {
        A1[i-nA0]=A[i];
    }
    
    
    
    
    int nB0=int(n/2);
    int nB1=m-nA0;
    int *B0 = new int[nB0];
    int *B1 = new int[nB1];
    
    for (int i=0;i<nB0;i++)
    {
        B0[i]=B[i];
    }
    for (int i=nB0;i<n;i++)
    {
        B1[i-nB0]=B[i];
    }
    
    
    int *C10 = multiply(A0, B0, nA0, nB0);
    int *C2nb0 = multiply(A0, B1, nA0, nB1);
    int *C3na0 = multiply(A1, B0, nA1, nB0);
    int *C4nab0 = multiply(A1, B1, nA1, nB1);
    
    
    
    int *C1 = new int[m+n-1];
    memset(C1,0,sizeof C1);
    for (int i=0;i<(nA0+nB0-1);i++)
    {
        C1[i]=C10[i];
    }
    
    
    int *C2 = new int[m+n-1];
    memset(C2,0,sizeof C2);
    for (int i=0;i<(nA0+nB1-1);i++)
    {
        C2[i+nB0]=C2nb0[i];
    }
    
    int *C3 = new int[m+n-1];
    memset(C3,0,sizeof C3);
    for (int i=0;i<(nA1+nB0-1);i++)
    {
        C3[i+nA0]=C3na0[i];
    }    
    
    int *C4 = new int[m+n-1];
    memset(C4,0,sizeof C4);
    for (int i=0;i<(nA1+nB1-1);i++)
    {
        C4[i+nA0+nB0]=C4nab0[i];
    }  
    
    for (int i=0;i<(n+m-1);i++)
    {
        C4[i]=C4[i]+C3[i]+C2[i]+C1[i];
    }
    
    return C4;
    
}
 
 
 
 
 
 
 
 

int main()
{

    int A[] = {5, 0, 10, 6};
    int B[] = {1, 2, 4};

    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
 
    cout << "First polynomial is ";
    printPoly(A, m);
    cout <<endl<< "Second polynomial is ";
    printPoly(B, n);
 
    // int *prod = multiply(A, B, m, n);
 
    // cout <<endl<< "Product polynomial is ";
    // printPoly(prod, m+n-1);
    
    
    
    
    int *p = multiplyy(A, B, m, n);
 
    cout <<endl<< "Product polynomial is ";
    printPoly(p, m+n-1);
 
    return 0;
}