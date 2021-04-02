#include<bits/stdc++.h>
using namespace std;

void increment1(int **p2){
    p2 = p2+1; //Nothing will happen
}
void increment2(int **p2){
    *p2 = *p2+1; //*p pointer will change
}
void increment3(int **p2){
    **p2 = **p2+1; //Change will happen at the original place
}

int main(){
    int i =10;
    int *p = &i;
    int **p2 = &p;
    cout<<p2<<endl;
    cout<<&p<<endl;
    cout<<**p2<<endl;

    cout<<i<<endl;

    increment1(p2);
    cout<<"After increment1"<<endl;
    cout<<i<<endl;

    // increment2(p2);
    // cout<<"After increment2"<<endl;
    // cout<<**p2<<endl;
    
    increment3(p2);
    cout<<"After increment3"<<endl;

    cout<<**p2<<endl;
    cout<<i<<endl;


}