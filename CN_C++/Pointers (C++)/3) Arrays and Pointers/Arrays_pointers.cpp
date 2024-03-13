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

    /*
        *(a+1) -> a[1]
        *(a+i) -> a[i]   
        a[i] -> *(a+i)
        i[a]  -> *(i+a)
         All are same
         Therefore, a[i] is same as i[a]
    */
    cout<<a[1]<<" "<<1[a]<<endl;
    cout<<"Size of A "<<sizeof(a)<<endl;
    int *p = a;
    cout<<"Size of *p "<<sizeof(*p)<<endl;
    cout<<"Size of p "<<sizeof(p)<<endl; //Size of a pointer is fixed for all datatypes and it depends on the machine architecture


}