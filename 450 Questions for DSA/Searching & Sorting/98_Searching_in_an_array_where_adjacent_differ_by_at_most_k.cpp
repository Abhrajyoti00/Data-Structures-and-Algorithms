#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, x;
    // cin >> n>>k>>x;

    int arr[n] = {4, 5, 6, 7, 6};
    k = 1;
    x = 6;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 0, high = n - 1, mid = 0, index = -1;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        int range = mid - low;
        if ((range * k + arr[low]) < x)
        {
            low = mid + 1;
        }
        else if ((range * k + arr[low]) > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] == x)
        {
            if (index >= mid)
                index = mid;
        }
    }
    cout << "The first index of " << x << " is " << index << "." << endl;
    return 0;
}