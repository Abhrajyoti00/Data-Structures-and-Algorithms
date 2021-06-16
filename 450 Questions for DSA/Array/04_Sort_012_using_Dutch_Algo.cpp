#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:

        // O(2n) using Dutch Algo 

    // void sort012(int a[], int n)
    // {
    //     // To fix the position of 2
    //     int i = 0, j = n-1;
    //     while(i<=j){
    //         if(a[j] == 2)
    //             j--;
    //         else if(a[i] != 2)
    //             i++;
    //         else if(a[i] == 2 && a[j]!=2){
    //             swap(a[i], a[j]);
    //             i++;
    //             j--;
    //         }
    //     }
    //     // cout<<j<<endl;
    //     // To fix the pos of 0 and 1
    //     // j contains the pos after which 2 starts
    //     i = 0;
    //     while(i<=j){
    //         if(a[i] == 0)
    //             i++;
    //         else if(a[j] == 1)
    //             j--;
    //         else if(a[i] == 1 && a[j] == 0){
    //             swap(a[i], a[j]);
    //             i++;
    //             j--;
    //         }
    //     }
    // }

    // O(n) using Dutch Algo , Best Method :- 
    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {   
            if(a[mid] == 0)
                swap(a[mid++], a[low++]);
            else if(a[mid] == 1)
                mid++;
            else if(a[mid] == 2)
                swap(a[mid], a[high--]);
        }
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
    sol.sort012(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}