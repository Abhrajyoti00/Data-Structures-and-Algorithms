//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
// 	int print2largest(int arr[], int n) {
//     int max = INT_MIN;
// 	    for(int i = 0; i<n; i++){
// 	            if(arr[i]>max)
// 	                max = arr[i];
// 	    }
// 	    int slar = -1;
// 	    for(int i = 0; i<n; i++){
// 	        if(arr[i]!=max){
// 	            if(arr[i]>slar)
// 	                slar = arr[i];
// 	        }
// 	    }
// 	    return slar;
// 	}


    int print2largest(int arr[], int n) {
    if (n < 2) {
        // Array should have at least two elements
        return -1; // or any appropriate error value
    }

    int max = arr[0];
    int secondLargest = INT_MIN; // Initialize to lowest possible value

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            secondLargest = max;
            max = arr[i];
        } else if (arr[i] < max && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        // No second largest element found
        return -1; // or any appropriate error value
    }

    return secondLargest;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends