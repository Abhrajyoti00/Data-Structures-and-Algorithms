#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[10];
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<&a[0]<<endl;
    // All of the above ones represent the same thing, i.e., the address of a[0]

    a[0] = 5;
    cout<<*a<<endl;
    a[1] = 10;
    cout<<a+1<<endl;// address of 2nd element, which is 4 byts to 1st address
    cout<<*(a+1)<<endl;// address of 2nd element

    int *p = &a[0];
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<&a<<endl;

    p = p+1; //Fine
    // a = a+1; //Not Fine
}