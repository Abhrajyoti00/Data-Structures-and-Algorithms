class Solution:
    # Your task is to complete this function
    # Function should return an integer

    #Recursive Soln:-
    # def countPsHelper(self, string, i, j):
    #     if i == j:
    #         return 1
    #     if i>j:
    #         return 0
    #     print("The string is = ", string[i:j+1])

    #     if string[i] == string[j]:
    #         return 1+self.countPsHelper(string,i,j-1)+self.countPsHelper(string,i+1,j)
    #     else:
    #         return self.countPsHelper(string,i+1,j)+self.countPsHelper(string,i,j-1)-self.countPsHelper(string,i+1,j-1)
    # def countPs(self,string):
    #     return self.countPsHelper(string,0,len(string)-1)

    #Memoized Soln:-
    # # def countPsHelper(self, string, i, j,dp):
    # #     if(i > j):
    # #         return 0
     
    # #     if(dp[i][j] != -1):
    # #         return dp[i][j]%(10**9+7)
     
    # #     if(i == j):
    # #         dp[i][j] = 1
    # #         return dp[i][j]%(10**9+7)
            
    # #     elif string[i] == string[j]:
    # #         dp[i][j] = (1+self.countPsHelper(string,i,j-1,dp)%(10**9+7)+self.countPsHelper(string,i+1,j,dp)%(10**9+7))%(10**9+7)
    # #         return dp[i][j]%(10**9+7)
    # #     else:
    # #         dp[i][j] = (self.countPsHelper(string,i+1,j,dp)%(10**9+7)+self.countPsHelper(string,i,j-1,dp)%(10**9+7)-self.countPsHelper(string,i+1,j-1,dp)%(10**9+7))%(10**9+7)
    # #         return dp[i][j]%(10**9+7)
            
    # def countPs(self,string):
    #     dp = [[-1 for i in range(len(string)+1)] for j in range(len(string)+1)]
    #     return self.countPsHelper(string,0,len(string)-1,dp)%(10**9+7)
    
    #DP SOl
    
    def countPs(self,str):
        N = len(str)
     
        # Create a 2D array to store the count
        # of palindromic subsequence
        cps = [[0 for i in range(N + 2)]for j in range(N + 2)]
     
        # palindromic subsequence of length 1
        for i in range(N):
            cps[i][i] = 1%(10**9+7)
     
        # check subsequence of length L
        # is palindrome or not
        for L in range(2, N + 1):
     
            for i in range(N):
                k = L + i - 1
                if (k < N):
                    if (str[i] == str[k]):
                        cps[i][k] = (cps[i][k - 1]%(10**9+7) +
                                     cps[i + 1][k]%(10**9+7) + 1)%(10**9+7)
                    else:
                        cps[i][k] = (cps[i][k - 1]%(10**9+7) +
                                     cps[i + 1][k]%(10**9+7) -
                                     cps[i + 1][k - 1]%(10**9+7))%(10**9+7)
     
        # return total palindromic subsequence
        return cps[0][N - 1]%(10**9+7)

sol = Solution()
# string = 'aab'  #4 ans
# string = 'abcd'  #4 ans
# string = 'aaaa'   #15 ans
string = 'bccb'   #9 ans
print(sol.countPs(string))