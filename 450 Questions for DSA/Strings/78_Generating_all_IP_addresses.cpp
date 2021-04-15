#include <bits/stdc++.h>
using namespace std;

vector<string> tokenizedString(string snew){
    vector<string> string_separated_snew;
    string limiter = "";
    for(int i = 0; i < snew.length(); i++){
        if(snew[i] == '.'){
            string_separated_snew.push_back(limiter);
            limiter = "";

        }
        else{
            limiter += snew[i];
        }
    }
    string_separated_snew.push_back(limiter);
    return string_separated_snew;
}

bool isValid(string snew){
    // snew = 255.255.111.35
    vector<string> string_separated_snew;
    string_separated_snew = tokenizedString(snew);
    // cout<<"Tokenized  = "<<endl;
    int i;
    // for( i = 0; i < string_separated_snew.size(); i++)
    //     cout<<string_separated_snew[i]<<endl;
    
    for( i = 0; i < string_separated_snew.size(); i++){
        
        if(string_separated_snew[i].size()>3 || (stoi(string_separated_snew[i])<0) || (stoi(string_separated_snew[i])>255))
            return false;
        if(string_separated_snew[i].size()>1 && stoi(string_separated_snew[i]) == 0)
            return false;
        if(string_separated_snew[i].size()>1 && stoi(string_separated_snew[i]) != 0 && (string_separated_snew[i][0]) == '0')
            return false;
        // cout<<"The number is "<<string_separated_snew[i]<<" ";

    }

    cout<<"the string is" <<endl;
     for( i = 0; i < string_separated_snew.size(); i++)
        // cout<<string_separated_snew[i]<<" ";
    return true;
}


vector<string> genIps(string S){
    if(S.length()>12 || S.length()<4)
        return {};
    string snew = S;
    vector<string> ips;
    int l = S.length();
    for(int i = 1; i<S.length()-2; i++){
        for(int j = i+1; j<S.length()-1; j++){
            for(int k = j+1; k<S.length(); k++){
                // cout<<"k "<<snew.substr(0,k)<<" "<<snew.substr(k, l-k+2)<<endl;
                snew = snew.substr(0,k) + "." + snew.substr(k, l-k+2); // k = 9 
                // cout<<"j "<<snew.substr(0,j)<<" "<<snew.substr(j, l-j+3)<<endl;
                snew = snew.substr(0,j) + "." + snew.substr(j, l-j+3); // j = 6
                // cout<<"i "<<snew.substr(0,i)<<" "<<snew.substr(i, l-i+4)<<endl; 
                snew = snew.substr(0,i) + "." + snew.substr(i, l-i+4); // i = 3
                // cout<<"Reached Here: snew  = "<<snew<<" "<<endl;
                if(isValid(snew))
                // cout<<"YEAH "<<snew<<endl;
                    ips.push_back(snew);
                snew = S;
            }
        }
    }
    return ips;
}
int main(){
    // string S;
    // cin>>S; //"25525511135"
    vector<string>ips;
    // ips = genIps(S);
    string A = "25525511135";
    string B = "25505011535";
    ips = genIps(A);


    cout<<"First Method of printing \n";
    for(auto &it: ips){
        cout<<it<<" ";
    }
    // cout<<"Second Method of printing \n";
    
    // for(int i = 0; i< ips.size(); i++){
    //     cout<<ips[i]<<" ";
    // }
    cout<<endl;
    // cout<<genIps(S)<<endl;
    return 0;
}