class Solution:


    # def editDistanceHelper(self,s,t,m,n):
    #     if m == 0:
    #         return n
    #     if n == 0:
    #         return m
        
    #     if s[m-1] == t[n-1]:
    #         return self.editDistanceHelper(s,t,m-1,n-1)

    #     return 1+min(self.editDistanceHelper(s,t,m,n-1), self.editDistanceHelper(s,t,m-1,n), self.editDistanceHelper(s,t,m-1,n-1))
        
    def editDistance(self, s, t):
        m = len(s)
        n = len(t)
        dp = [[0 for i in range(n + 1)] for j in range(m+1)]

        for i in range(m+1):
            for j in range(n+1):
                if i == 0:
                    dp[i][j] = j
                
                elif j == 0:
                    dp[i][j] = i

                elif s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                
                else:
                    dp[i][j] = 1+ min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])

        return dp[m][n]
        
sol = Solution()
str1 = "sunday"
str2 = "saturday"

# str1 = "geek"
# str2 = "gesek"
print(sol.editDistance(str1,str2))
