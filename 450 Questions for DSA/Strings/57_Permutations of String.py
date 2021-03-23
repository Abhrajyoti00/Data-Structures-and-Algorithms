# class Solution:

#     def toString(self, List):
#         return ''.join(List)

#     def swap(self, S,pos1,pos2):
#         t = S[pos1]
#         S[pos1] = S[pos2]
#         S[pos2] = t

#     def find_permutation_helper(self,S,l,r):
#         # print(S)
#         if l == r:
#             print(self.toString(S))
#         for i in range(l,r+1):
#             self.swap(S, l, i)
#             self.find_permutation_helper(S,l+1,r)
#             self.swap(S, l, i)
        

#     def find_permutation(self, S):
#         self.find_permutation_helper(S,0,len(S)-1)


class Solution:

    ans = []
    def toString(self, List):
        return ''.join(List)

    def swap(self, S,pos1,pos2):
        t = S[pos1]
        S[pos1] = S[pos2]
        S[pos2] = t

    def find_permutation_helper(self,S,l,r):
        # print(S)
        if l == r:
            self.ans.append((self.toString(S)))
        for i in range(l,r+1):
            self.swap(S, l, i)
            self.find_permutation_helper(S,l+1,r)
            self.swap(S, l, i)
        

    def find_permutation(self, S):
        # S.sort()
        self.ans = []
        self.find_permutation_helper(list(S),0,len(S)-1)
        self.ans.sort()
        return self.ans

sol = Solution()
print(sol.find_permutation(list('ABC')))