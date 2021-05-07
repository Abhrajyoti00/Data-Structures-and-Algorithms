#include<bits/stdc++.h>
using namespace std;


vector<vector<string> > Anagrams(vector<string>& string_list) 
// void Anagrams(vector<string>& string_list) 
{
    vector<vector<string>> result;
    
    map<map<char,int>, vector<string>>big_mp;
    
    for(string str: string_list){
        vector<string>temp_list;
        map<char, int> temp_map;
        for(int i=0; i<str.length(); i++){
            temp_map[str[i]]++;
        }
        auto it = big_mp.find(temp_map);
        if(it != big_mp.end()){
            it->second.push_back(str);
        }
        else{
            temp_list.push_back(str);
            big_mp.insert({temp_map, temp_list}); 
        }
    }
    for(auto it = big_mp.begin(); it != big_mp.end(); it++){
        result.push_back(it->second);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<string> string_list(n);
    // words[] = {act,god,cat,dog,tac};
    // act god cat dog tac
    // 6
    // eat tea tan ate nat bat
//     bat
// eat tea ate
// tan nat

// Input:
// 14
// k e q e d p e s x k d k g d

// Its Correct output is:
// d d d
// e e e
// g
// k k k
// p
// q
// s
// x


    for(int i=0; i<n; i++){
        cin>>string_list[i];
    }
    vector<vector<string>> result = Anagrams(string_list);
    sort(result.begin(), result.end());
    // Anagrams(string_list);
    cout<<"ANSWER TIME \n\n";
    for(int i=0; i<result.size(); i++){
        // cout<<" Result "<<i<<" "<<endl;
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}
