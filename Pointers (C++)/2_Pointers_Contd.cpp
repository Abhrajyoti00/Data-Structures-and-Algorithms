#include <bits/stdc++.h>
using namespace std;
int main(){
    int i = 10;
    int *p = &i;

    cout<<sizeof(p)<<endl; // Prints the size of int i
    cout<<i<<endl; 
    cout<<*p<<endl;

    i++;

    cout<<i<<endl; 
    cout<<*p<<endl; // Since same location, so prints sae thing

    int a = *p;  //*p is same as i
    a++;
    cout<<a<<endl;
    cout<<*p<<endl;
    i = 12;
    *p = 23;
    cout<<*p<<endl;

    (*p)++;

    cout<<i<<endl;
    cout<<*p<<endl;

}