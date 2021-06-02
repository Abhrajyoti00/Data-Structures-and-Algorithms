#include<bits/stdc++.h>
using namespace std;

// O(n) Solution 
// vector<int> find(int arr[], int n , int x )
// {
//     vector<int> ans;
//     int first = 0, last = n-1, mid = 0;
//     int flag = 0;
//     while(first<=last){
//         mid = (first+last)/2;
//         if(x<arr[mid]){
//             last = mid-1;
//         }
//         else if(x>arr[mid]){
//             first = mid+1;
//         }
//         else if(x == arr[mid]){
//             flag = 1;
//             break;
//         }
//     }

//     if(flag!=1){
//         ans.push_back(-1);
//         ans.push_back(-1);
//         return ans;
//     }
//     // Now the mid has the ans

//     int first_occurence = mid, last_occurence = mid;
//     int mid1 = 0, mid2 = 0;
//     // cout<<"Mid = "<<mid<<endl;
//     while(first_occurence>=0){
//         if(arr[first_occurence-1] == x){
//             first_occurence--;
//         }
//         else{
//             ans.push_back(first_occurence);
//             break;
//         }

//     }

//     while(last_occurence<n){
//         if(arr[last_occurence+1] == x){
//             last_occurence++;
//         }        
//         else{
//             ans.push_back(last_occurence);
//             break;
//         }
//     }


//     return ans;
// }

 
// O(log N) solution :-


vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    int low = 0, high = n-1, mid = 0, res = -1;
    int flag = 0;

    // For finding the first occurence
    while(low<=high){
        mid = (low+high)/2;
        if(x<arr[mid]){
            high = mid-1;
        }
        else if(x>arr[mid]){
            low = mid+1;
        }
        else if(x == arr[mid]){
            res = mid;
            high = mid-1;
        }
    }
    ans.push_back(res);

    low = 0, high = n-1, mid = 0, res = -1;
    // For finding the last occurence
    
    while(low<=high){
        mid = (low+high)/2;
        if(x<arr[mid]){
            high = mid-1;
        }
        else if(x>arr[mid]){
            low = mid+1;
        }
        else if(x == arr[mid]){
            res = mid;
            low = mid+1;
        }
    }
    ans.push_back(res);
    return ans;

}



int main(){
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i = 0 ; i<n; i++)
        cin>>arr[i];
    vector<int> ans = find(arr, n, x);
    cout<<ans[0]<<" "<<ans[ans.size()-1]<<endl;
}

//n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// 1 3 5 5 5 5 67 123 125
