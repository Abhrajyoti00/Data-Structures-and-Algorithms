#include <bits/stdc++.h>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}

void incrementPointer(int *p){
    p = p+1;
}

void increment(int *p){
    (*p)++;  //Changes at the original place
}

int main(){
    int i = 10;
    int *p = &i;

    print(p);
    cout<<p<<endl;
    incrementPointer(p); //Nothing changes
    cout<<p<<endl;
    cout<<i<<endl;
    cout<<*p<<endl;
    increment(p);
    cout<<*p<<endl;

}