#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, x;
    cin >> n>>k;
    int arr[n];
    // n = 3;
    // int arr[5] = {4, 5, 6, 7, 6};
    // k = 1;
    // x = 6;
    // n = 5;
    // int arr[n] = {20, 40, 50, 60, 70, 60};
    // k = 20;
    // x = 60;
    // int arr[n] = {20, 40, 50};
    // k = 20;
    // x = 70;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin>>x;
    int low = 0, high = n - 1, mid = 0, index = INT_MAX;
    while (low <= high)
    {
        // cout<<"hi"<<endl;
        mid = low + (high - low) / 2;
        int range = mid - low;
        int value = range * k + arr[low];
        if (arr[mid] == x)
        {   
            if (index >= mid)
                index = mid;
        }
        
        if ((value) <= x)
        {
            if(arr[low] == x && low<=index)
                index = low;
            low = mid + 1;
        }
        else if ((value) > x)
        {
            if(arr[high] == x && high<=index)
                index = high;
            high = mid - 1;
        }
        
    }
    if(index == INT_MAX)
        cout<<-1;
    cout << "The first index of " << x << " is " << index << "." << endl;
    return 0;
}