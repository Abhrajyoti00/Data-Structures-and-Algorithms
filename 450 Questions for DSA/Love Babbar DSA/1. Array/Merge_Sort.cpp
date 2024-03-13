#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(arr, b, c) min(c, min(arr, b))
#define min4(arr, b, c, d) min(d, min(c, min(arr, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

void merge(int arr[], int l, int mid, int r){
    // Create 2 temp arrays

    int n1 = mid-l+1;
    int n2 = r-mid;
    
    int a[n1];
    int b[n2]; 

    // We cannot merge into the same array. So we created two temp arrays

    for(int i = 0; i<n1; i++)
        a[i] = arr[l+i];
    for(int i = 0; i<n2; i++)
        b[i] = arr[mid+1+i];

    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j< n2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr, l, mid, r);
    }
    return;
}

int32_t main(){
fast


// ||| Author: Abhrajyoti Kundu |||
// ||| DS-ALGO Lover |||


int t=1;
// cin>>t;
while(t--){
    int n;
    cin>>n;
    // int arr[] = {1,4,2,1,4,2,4,2,1,2};
    int arr[n];
    // int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }



    
    
}
return 0;
}
