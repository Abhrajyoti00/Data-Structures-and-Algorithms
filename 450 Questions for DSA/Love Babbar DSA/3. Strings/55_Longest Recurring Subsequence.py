class Solution:
    def LongestRepeatingSubsequence(self, X):

        m = len(str)
        n = m
        Y = X
        '''
        :param m: length of string X 
        :param n: length of string Y
        :param X: string X
        :param Y: string Y
        :return: Integer
        '''

        dp = [[0 for j in range(n+1)] for i in range(m+1)]
        for i in range(m+1):
            for j in range(n+1):
                if (i==0 or j==0):
                    dp[i][j] = 0
                elif ((X[i-1] == Y[j-1]) and (i!=j)):
                    dp[i][j] = 1+dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
        # print(dp)

        ans = dp[m][n]
        
        return ans
sol = Solution()

# str = "axxxy"
str = "aab"
# A = 3
# B = 2
# str1 = 'ABC'
# str2 = 'AC'
# A = 23
# B = 6
# str1 = 'AAPAHJWTESPLWEQFMNMYMTQ'
# str2 = 'RELEIN'
print(sol.LongestRepeatingSubsequence(str))
