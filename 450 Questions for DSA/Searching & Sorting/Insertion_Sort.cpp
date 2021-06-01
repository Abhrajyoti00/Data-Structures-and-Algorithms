#include<bits/stdc++.h>
using namespace std;

/* A General Note in C++
The function declaration:

void funcA(int[]);
is silently translated into the following:

void funcA(int*);
and when you write this:

funcA(myArray);
it is silently translated into the following:

funcA(&myArray[0]);

*/


// 7 2 5 2 8 6 10 2
// j i 
// 7 7 5 2 8 6 10 2
// j i

void insertionSort(int arr[], int n){
    // We can even use:  int n = sizeof(arr)/sizeof(arr[0]);   --> to find the size of array.
    // Remember here size() function doesn't work. 
    
    for(int i = 1; i < n; i++){
        int current_element = arr[i];
        int j = i-1;
        while(current_element<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current_element;
    }
}
int main(){
    cout<<"Enter the number of elements \n";
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    insertionSort(arr, n);
    cout<<"Sorted Array : - \n";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}