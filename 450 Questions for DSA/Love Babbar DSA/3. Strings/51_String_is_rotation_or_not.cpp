# include <bits/stdc++.h> 
using namespace std;
bool areRotations(string str1, string str2){
    if (str1.length()!=str2.length()){
        return false;
    }
    str2 = str2+str2;
    // cout<<str2<<endl;
    int p1 = 0;
    // for(int i=0; i<str2.length(); i++){
    //     if (p1==str1.length()){
    //         return true;
    //     }
    //     if (str2[i]==str1[p1]){
    //         p1+=1;
    //     }
    //     else{
    //         p1=0;
    //     }
    // }

    //Another better stl

    return (str2.find(str1) != string::npos);


    // return false;
}

int main() 
{ 
   string str1 = "AACD", str2 = "ACDA"; 
//    string str1 = "AACD", str2 = "ABAD"; 
   if (areRotations(str1, str2)) 
     printf("Strings are rotations of each other"); 
   else
      printf("Strings are not rotations of each other"); 
   return 0; 
} 