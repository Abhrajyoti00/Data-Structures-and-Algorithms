#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int b[n];
        for(int i = 0; i < n; i++)
            cin>>b[i];
        int ns = 2*n;
        int arr[ns];
        for(int i = 0 ; i<ns; i++)
            arr[i] = 0;
        for(int i = 0; i<ns; i+=2){
            arr[i] = b[i/2];
        }
        for(int i = 1; i<ns-1; i+=2){
            if(arr[i-1] == arr[i+1])
                arr[i] = arr[i-1];
            else
         
                arr[i] = min(arr[i-1], arr[i+1])-1;
        }
        vector<int>v;
        for(int i = 0 ; i< ns; i++){
            // if(arr[i]!=0)
                v.push_back(arr[i]);
        }
        cout<<v.size()<<endl;
        for(int i = 0 ;  i<v.size(); i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}
