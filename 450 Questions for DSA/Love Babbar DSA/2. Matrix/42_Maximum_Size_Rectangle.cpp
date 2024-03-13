// // C++ code for Maximum size square  
// // sub-matrix with all 1s  
// #include <bits/stdc++.h> 
// #define bool int  
// #define R 6  
// #define C 5  
// using namespace std; 
  
  
// void printMaxSubSquare(bool M[R][C])  
// {  
//     int i,j;  
//     int S[R][C];  
//     int max_of_s, max_i, max_j;  
      
//     /* Set first column of S[][]*/
//     for(i = 0; i < R; i++)  
//         S[i][0] = M[i][0];  
      
//     /* Set first row of S[][]*/
//     for(j = 0; j < C; j++)  
//         S[0][j] = M[0][j];  
          
//     /* Construct other entries of S[][]*/
//     for(i = 1; i < R; i++)  
//     {  
//         for(j = 1; j < C; j++)  
//         {  
//             if(M[i][j] == 1)  
//                 S[i][j] = min(S[i][j-1],min( S[i-1][j],  
//                                 S[i-1][j-1])) + 1;  
//             else
//                 S[i][j] = 0;  
//         }  
//     }  
      
//     /* Find the maximum entry, and indexes of maximum entry  
//         in S[][] */
//     max_of_s = S[0][0]; max_i = 0; max_j = 0;  
//     for(i = 0; i < R; i++)  
//     {  
//         for(j = 0; j < C; j++)  
//         {  
//             if(max_of_s < S[i][j])  
//             {  
//                 max_of_s = S[i][j];  
//                 max_i = i;  
//                 max_j = j;  
//             }  
//         }              
//     }  
//     cout<<"Max of s = "<<max_of_s<<endl;
//     cout<<"Max of i = "<<max_i<<endl;
//     cout<<"Max of j = "<<max_j<<endl;
  
//     cout<<"Maximum size sub-matrix is: \n";  
//     for(i = max_i; i > max_i - max_of_s; i--)  
//     {  
//         for(j = max_j; j > max_j - max_of_s; j--)  
//         {  
//             cout << M[i][j] << " ";  
//         }  
//         cout << "\n";  
//     }  
// }  
  
  
// /* Driver code */
// int main()  
// {  
//     bool M[R][C] = {{0, 1, 1, 0, 1},  
//                     {1, 1, 0, 1, 0},  
//                     {0, 1, 1, 1, 0},  
//                     {1, 1, 1, 1, 0},  
//                     {1, 1, 1, 1, 1},  
//                     {0, 0, 0, 0, 0}};  
//     // bool M[R][C] = {{0, 1 ,1 ,0},
//     //      {1, 1 ,1 ,1},
//     //      {1 ,1 ,1 ,1},
//     //      {1 ,1 ,0 ,0}};
                      
//     printMaxSubSquare(M);  
// }  


// #include <bits/stdc++.h>
// using namespace std;

// int largestHistogramArea(int arr[], int n){
//     int rb[n]; // right boundary... keep index of next smaller element on the right
//     stack<int>s;

    
    
//     int lb[n]; // left boundary... keep index of next smaller element on the left
//     int maxArea = 0; 
//     for (int i = 0; i < n; i++){
//         int width = rb[i]-lb[i]-1;
//         int area = arr[i]*width;
//         maxArea = max(maxArea, area);
//     }
// return maxArea;

// }

// int main(){

// }
#include<bits/stdc++.h> 
using namespace std; 
  
// The main function to find the maximum rectangular  
// area under given histogram with n bars 
int getMaxArea(int hist[], int n) 
{ 
    // Create an empty stack. The stack holds indexes  
    // of hist[] array. The bars stored in stack are  
    // always in increasing order of their heights. 
    stack<int> s; 
  
    int max_area = 0; // Initialize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar 
                       // as the smallest bar 
  
    // Run through all bars of given histogram 
    int i = 0; 
    while (i < n) 
    { 
        // If this bar is higher than the bar on top  
        // stack, push it to stack 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
    int n = sizeof(hist)/sizeof(hist[0]); 
    cout << "Maximum area is " << getMaxArea(hist, n); 
    return 0; 
} 
