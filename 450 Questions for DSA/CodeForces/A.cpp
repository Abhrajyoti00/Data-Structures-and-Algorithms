#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int>v;
        int n, m;
        cin >> n;
        cin >> m;
        char arr[n][m];
        for (int i = 0; i < n; i++) {
            for(int j =0; j<m; j++)
                cin >> arr[i][j];
        }
        int c = 0;
        for(int j = 0 ; j < m; j++){
            if(c == 4)
                break;
            for(int i = 0; i<n; i++){
                if(c == 4)
                    break;
                if(tolower(arr[i][j]) == 'v' && c == 0)
                    { c++; break;}
                else if(tolower(arr[i][j]) == 'i' && c == 1)
                    { c++; break;}
                else if(tolower(arr[i][j]) == 'k' && c == 2)
                    { c++; break;}
                else if(tolower(arr[i][j]) == 'a' && c == 3)
                    { c++; break;}
            }
        }

        if(c == 4)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}