//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	// void leftRotate(int arr[], int k, int n) 
	// { 
	//    int b[n];
    //    for(int i =0; i < n ; i++){
    //     b[i] = arr[(i+k)%n];
    //    }
    //    for(int i =0; i < n ; i++){
    //     arr[i] = b[i];
    //    }
	// } 
	void leftRotate(int arr[], int k, int n) 
	{
       int j,t;
       k = k%n;
       int x = __gcd(k,n);
       for(int i = 0 ; i<x; i++){
            t = arr[i];
            j = i;
            while(1){
                int r = (j+k)%n;
                if(r == i)
                    break;
                arr[j] = arr[r];
                j = r;
            }
            arr[j] = t;
       }
	} 	 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends