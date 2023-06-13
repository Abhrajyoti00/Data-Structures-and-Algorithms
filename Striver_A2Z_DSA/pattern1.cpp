#include <bits/stdc++.h>
using namespace std;

void printSquare(int n) {
        for(int i=1;i<=n;i++){
            for(int j =1; j<=n; j++){
                if(i>=j)
                cout<<"* ";
            }
            cout<<endl;
        }
    }

int main()
{
    int n;
    cin>>n;
    printSquare(n);
    return 0;
}