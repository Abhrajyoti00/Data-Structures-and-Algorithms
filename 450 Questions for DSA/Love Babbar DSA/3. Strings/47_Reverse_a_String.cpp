#include <bits/stdc++.h>
using namespace std;

    void reverseString(vector<char>& s) {
        int l = s.size();
        char temp;
        for(int i = 0; i < l/2; i++){
            temp = s[i];
            s[i] = s[l-i-1];
            s[l-i-1] = temp;
        }

    }

    int main(){
        
        string str;
        cin>>str;
        vector<char>s(str.begin(), str.end());
        reverseString(s);
        for (const char &c: s)
            std::cout << c;
        return 0;
    }

