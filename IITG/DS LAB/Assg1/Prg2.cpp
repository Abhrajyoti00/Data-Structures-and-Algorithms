// Given a sorted array nums of N integers and an integer x, write a program to find the lower
// bound of x. The lower bound of x is the smallest index i such that nums[i] >= x.


#include<bits/stdc++.h>
using namespace std;

int lowerBound(int arr[], int n, int x) {
	// Write your code here
	int low = 0, high = n-1;
	int ans;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>=x){
			high = mid-1;
			ans = low;
		}
		else
			low = mid+1;
	}
    return low;
}


int main(){
    int n;
    cout<<"Enter the number of elements present in the nums :- \n";
    cin>>n;
    int nums[n];
    cout<<"Enter the elements :- \n";   
    for(int i =0; i<n; i++)
        cin>>nums[i];

    cout<<"Enter the value of x \n";
    int x;
    cin>>x;
    cout<<lowerBound(nums, n, x);
}