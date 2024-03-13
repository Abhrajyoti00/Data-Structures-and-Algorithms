#include <bits/stdc++.h>
using namespace std;

/*

6 78
5 20 3 2 5 80
1

5 45
90 70 20 80 50      
-1

6 
16
3 2 4 80 81 20
1

5 1
2 23 213 231 232
1
*/

// T.C = O(n), Sc = O(n)
// bool findPair(int arr[], int size, int n)
// {
//     unordered_map <int, int> my_map;
//     for(int i = 0 ; i<size; i++)
//         my_map[arr[i]]++;
//     for(int i = 0 ; i < size; i++){
//         if(my_map[(abs(arr[i] - n))] > 0)
//             return true;
//     }
//     return false;
// }

// More Optimised Solution  

// T.C = O(nlog n), Sc = O(1)

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int a = size-2, b = size - 1;
    while (a >= 0)
    {
        if ((arr[b] - arr[a]) < n)
            a -= 1;
        else if ((arr[b] - arr[a]) > n)
            b -= 1;
        else if ((arr[b] - arr[a]) == n)
            return true;
    }
    return false;
}

int main()
{
    int l, n;
    cin >> l >> n;
    int arr[l];
    for (int i = 0; i < l; i++)
        cin >> arr[i];
    if (findPair(arr, l, n))
        cout << 1 << endl;
    else
        cout << -1 << endl;
}