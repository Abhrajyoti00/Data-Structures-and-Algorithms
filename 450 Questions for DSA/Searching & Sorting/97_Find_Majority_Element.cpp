#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // Function to find majority element in the array
    // arr: input array
    // size: size of input array

    // O(nlogn)  Solution 

    // int majorityElement(int arr[], int size)
    // {
    //     if(size == 1)
    //         return arr[0];
    //     sort(arr, arr + size);
    //     int count = size / 2 + 1;
    //     int temp_count = count;
    //     for (int i = 0; i < size-1; i++){
    //         // cout<<temp_count<<endl;
    //         if(arr[i] == arr[i+1]){
    //             temp_count--;
    //             if(temp_count == 1)
    //                 return arr[i];
    //         }
    //         else
    //             temp_count = count;
    //     }
    // return -1;

    // }

    // O(n) Solution 

    int majorityElement(int arr[], int size){
        if(size == 0)
            return -1;
        if(size == 1)
            return arr[0];
        int count = 1, maj_ele = arr[0];
        for(int i = 1; i<size; i++){
            if(arr[i]!=arr[i-1]){
                if(arr[i] == maj_ele)
                    count+=1;
                else
                    count-=1;
            }
            else if(arr[i] == arr[i-1]){
                count+=1;
                maj_ele = arr[i];    // Ei line e error ache... Jokhon por por duto not majority but same element ashe tokhon amar majority element change hoye jacche
            }
            if(count == 0){
                maj_ele = arr[i];
                count = 1;
            }
            
        }
        if(count == 0)
            return -1;
        int org_count = 0;
        for(int i = 0; i<size; i++){
            if(arr[i] == maj_ele)
                org_count+=1;
        }
        if(org_count > floor(size/2))
            return maj_ele;
        else
            return -1;
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution sol;
    cout << "The Majority Element is = " << (sol.majorityElement(arr, n));

    // 29   1 1 2 2 2 2 2 2 2 2 2 2 2 1 2 2 1 1 2 1 1 1 1 2 2 1 1 1 1     ans = 2
}
