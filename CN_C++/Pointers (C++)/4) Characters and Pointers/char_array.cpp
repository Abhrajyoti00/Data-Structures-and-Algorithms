#include<bits/stdc++.h>
using namespace std;
int main(){

    char str[] = "abcde";
    char *pstr = "abcde"; // This is not correct as it is pointing to an address that might not work sometimes.

    cout<<str<<endl;
    cout<<pstr<<endl;



    int a[] = {1,2,3};
    char b[] = "abc";

    cout<<a<<endl;
    cout<<b<<endl; //char array is different

    char *c = &b[0];
    cout<<"Line 20 "<<c<<endl; //Prints everything

    char c1= 'a';
    char *pc = &c1;

    cout<<c1<<endl;
    cout<<pc<<endl; // It continues to print until it finds a null character

}
