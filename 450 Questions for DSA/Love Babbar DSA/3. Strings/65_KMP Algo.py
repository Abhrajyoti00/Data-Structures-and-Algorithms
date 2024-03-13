class Solution:
    def lps(self, s):
        j = 0
        lps = [0 for i in range(len(s))]
        i = 1
        n = len(s)
        while(i<n):
            #AABAACAABAA

            if s[i] == s[j]:
                j+=1
                lps[i] = j
                i+=1
            else:
                if j!=0:
                    j = lps[j-1]
                
                else:
                    lps[i] = 0
                    i+=1
        # print("lps = ", lps)
        res = lps[len(s)-1]
        return res, lps
    
    def KMPSearch(self, pat, txt):
        m = len(pat)
        n = len(txt)
        lps = [0]*n
        res, lps = self.lps(pat)
        j = 0
        i = 1
        while(i<n):
            if pat[j] == txt[i]:
                i+=1
                j+=1
            if j == m:
                print("Found pattern at index " + str(i-j))
                j = lps[j-1]
            elif i<n and pat[j] != txt[i]:
                if j!=0:
                    j = lps[j-1]
                else:
                    i+=1





sol = Solution()
txt = "ABABDABACDABABCABAB"
# pat = "ABABCABAB"
pat = "ABAB"
sol.KMPSearch(pat, txt)
print("The length of the longest prefix which is also the suffix of the pattern is = " , sol.lps("AABAACAABAA"))
# print(sol.lps("AABAACAABAA"))

