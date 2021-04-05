#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        map<string,int>mp;
        int flag = 0;
        string mostRepeated = arr[0], second_most_repeated = arr[0];
        int lar = 0, slar = 0;
        for (int i=0; i<n; i++)
                mp[arr[i]]+=1;

        for (auto itr:mp){
            if(itr.second > lar){
                slar = lar;
                second_most_repeated = mostRepeated;
                lar = itr.second;
                mostRepeated = itr.first;
            }
            if(itr.second > slar and itr.first!=mostRepeated){
                slar = itr.second;
                second_most_repeated = itr.first;
            }
        }

        return second_most_repeated;
    }
};


int main(){
    Solution sol;
    int n = 0;
    cin>>n;
    string arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<sol.secFrequent(arr,n)<<endl;
}