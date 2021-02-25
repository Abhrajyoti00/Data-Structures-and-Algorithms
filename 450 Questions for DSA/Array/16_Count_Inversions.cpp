#include <bits/stdc++.h>
using namespace std;
// #define long long int long long
#define pi (3.141592653589)
#define mod 1000000007
// #define long long int long long
#define float long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(arr, b, c) min(c, min(arr, b))
#define min4(arr, b, c, d) min(d, min(c, min(arr, b)))
#define rrep(i, n) for(long long int i=n-1;i>=0;i--)
#define rep(i,n) for(long long int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


bool isPrime(long long int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (long long int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

long long int _mergeSort( long long int arr[], long long int temp[], long long int left, long long int right);
long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid,
          long long int right);
 
/* This function sorts the
   input array and returns the
number of inversions in the array */
long long int mergeSort(long long int arr[], long long int array_size)
{
    long long int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
long long int _mergeSort(long long int arr[], long long int temp[], long long int left, long long int right)
{
    long long int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array long long into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;
 
        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
 
/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid,
          long long int right)
{
    long long int i, j, k;
    long long int inv_count = 0;
 
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
 
            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
 
    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
 
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}
long long int inversionCount(long long arr[], long long N)
{
    return mergeSort(arr,N);
}

 int32_t main(){
fast


// ||| Author: Abhrajyoti Kundu |||
// ||| DS-ALGO Lover |||


long long int t=1;
// cin>>t;
while(t--){
    long long int n;
    cin>>n;
    // long long int arr[] = {1,4,2,1,4,2,4,2,1,2};
    long long int arr[n];
    // long long int n = sizeof(arr)/sizeof(arr[0]);
    long long int ans = 0;
    for (long long int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    ans = inversionCount(arr, n);
    cout<<"Sorted Array :- \n";
    for (long long int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
   
    cout<<"\n Count of Inversions = "<<ans;



    
    
}
return 0;
}
