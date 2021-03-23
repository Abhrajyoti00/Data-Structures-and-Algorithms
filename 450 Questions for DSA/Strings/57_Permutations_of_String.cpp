#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:

        string reverse(string S, int start, int end){
            while(start<end){
                swap(&S[start], &S[end]);
                start++;
                end--;
            }
            return S;
        }
        void swap (char* a, char* b)  
        {  
            char t = *a;  
            *a = *b;  
            *b = t;  
        }  

        int findCeil(string S, char first_character, int start, int end){
            // cout<<"String inside findceil = "<<S<<endl;
            int ceil_index = start;
            for(int i = start+1; i<=end; i++){
                if(S[i]>first_character && S[i] < S[ceil_index]){
                    ceil_index = i;
                }
            }
            return ceil_index;
        }

		vector<string>find_permutation(string S)
		{
            vector<string>ans_string;
            int size = S.length();
            sort(S.begin(), S.end());
		    bool isCompleted = false;
            while(!isCompleted){
                ans_string.push_back(S);
        
                int i;
                char first_character;
                for(i = size-2; i>=0; --i){
                    if(S[i]<S[i+1])
                        break;
                }
                if(i == -1)
                    isCompleted = true;
                
                else{
                    
                    first_character = S[i];
                    int ceil_index = findCeil(S, first_character, i+1, size-1);
                    swap(&S[i], &S[ceil_index]);

                    S = reverse(S, i+1, size-1);
                }
            }
            return ans_string;
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for(auto i: ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}



