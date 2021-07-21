#include <bits/stdc++.h>
using namespace std;

/*

6 78
5 20 3 2 5 80
1

5 45
90 70 20 80 50      
-1
*/

bool findPair(int arr[], int size, int n)
{
    unordered_map <int, int> my_map;
    for(int i = 0 ; i<size; i++)
        my_map[arr[i]]++;
    for(int i = 0 ; i < size; i++){
        if(my_map[(abs(arr[i] - n))] > 0) 
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