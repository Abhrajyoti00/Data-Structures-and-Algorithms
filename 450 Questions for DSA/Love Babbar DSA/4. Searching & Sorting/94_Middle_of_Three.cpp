#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:

    // 5 comparisons

    // int middle(int A, int B, int C){
    //     //code here//Position this line where user code will be pasted.
    //     if(A>=C){
    //         if(B>=A)
    //             return A;
    //         else{
    //             if(B>=C)
    //                 return B;
    //             else
    //                 return C;
    //         }
    //     }
    //     else{
    //         if(C<=B)
    //             return C;
    //         else{
    //             if(B>=A)
    //                 return B;
    //             else
    //                 return A;
    //         }
    //     }
    // }

    // 2 comparisons
    // int middle(int A, int B, int C){
    //     int x,y,z;
    //     x = A-B;   // X>0 means A>B
    //     y = B-C;   // y>0 means B>C
    //     z = A-C;   // z>0 means A>C
    //     if(x*y > 0)
    //         return B;
    //     if(z*y > 0)
    //         return A;
    //     return C;
    // }

    int middle(int A, int B, int C){
        int avg = (A+B+C)/3;
        int min = abs(avg-A);
        int temp = A;
        if(min>abs(avg-B)){
            temp = B;
            min = abs(avg-B);
        }
        if(min>abs(avg-C)){
            temp = C;
            min = abs(avg-C);
        }
        return temp;
    }

};

int main(){
    int A, B, C;
    cin>>A>>B>>C;
    Solution sol;
    cout<<"The Middle is = "<<(sol.middle(A,B,C));
}
