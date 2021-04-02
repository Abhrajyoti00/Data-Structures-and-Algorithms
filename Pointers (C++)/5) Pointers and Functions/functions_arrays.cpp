#include <bits/stdc++.h>
using namespace std;

// int sum(int a[], int size){
int sum(int *a, int size){

    cout<<"Inside Sum : "<<sizeof(a)<<endl; //Here a is the pointer, not the array
    int s = 0;
    for(int i = 0 ; i < size ; i++){
        s+=a[i];
    }
    return s;
}
int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"Inside Main : "<<sizeof(a)<<endl;
    cout<<sum(a,10)<<endl;
    cout<<sum(a+3, 7)<<endl; //Passing part of an array
}