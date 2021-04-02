// A Symbol table stores the addresses of the variables.
// & (Address of Operator)
// To compile the program... type g++ File_name.cpp
// After compiling To run the program... type .\a.exe
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i;
    cout<<&i<<endl; // Prints address of variable

    int *p = &i;  //P is a pointer to an integer
    cout<<p<<endl;  // Prints the address of i

    float f = 10.2;
    float *pf = &f;

    double d = 122.32;
    double *pd = &d;

    cout<<pf<<endl;
    cout<<pd<<endl;
}