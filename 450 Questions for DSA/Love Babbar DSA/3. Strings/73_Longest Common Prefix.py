class Solution:
    def longestCommonPrefix(self, strs):
        strs.sort()
        if len(strs) == 0:
            return ""
        commonPrefix = strs[0]
        for i in range(1, len(strs)):
            for j in range(len(strs[i])):
                # print(strs[i][j])
                if j<len(commonPrefix) and strs[i][j]!=commonPrefix[j]:
                    commonPrefix = strs[i][:j]
        return commonPrefix


sol = Solution()
# strs = ["flower","flow","flight"]
# strs = ["dog","racecar","car"]
strs = ["ab", "a"]
print(sol.longestCommonPrefix(strs))

