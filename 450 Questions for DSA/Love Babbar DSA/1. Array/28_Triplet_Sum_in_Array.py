# O(n^2) Soln, O(n) Space ... Gives TLE due to space

# from collections import Counter
# class Solution:
#     #User function Template for python3
#     # arr[] : The input Array
#     # N : Size of the Array
#     # X : Sum which you need to search for 
#     #Function to find if there exists arr triplet in the 
#     #array arr[] which sums up to X.
#     def find3Numbers(self,arr, N, X):
#         hashTable = Counter(arr)
#         # print('X = ', X)
#         for i in range(N):
#             # print('arr[i] = ', arr[i])
#             # hashTable[arr[i]]-=1
#             sumReqd = X-arr[i]
#             for j in range(i+1, N):
#                 # hashTable[arr[j]]-=1
#                 # print('sumReqd = ', sumReqd)
#                 # print('arr[j] = ', arr[j])
                
#                 diffLeft = (sumReqd - arr[j])
#                 if diffLeft!= arr[j] and diffLeft!= arr[i]:
#                     # print('DiffLeft = ', diffLeft)
#                     # print('HashTable = ', hashTable)
#                     if hashTable[diffLeft]>0:
#                         return True
#         return False

# Another Soln... With Same complexitites
# class Solution:
#     #User function Template for python3
#     # arr[] : The input Array
#     # N : Size of the Array
#     # X : Sum which you need to search for 
#     #Function to find if there exists arr triplet in the 
#     #array arr[] which sums up to X.
#     def find3Numbers(self, A, arr_size, sum):
#         for i in range(0, arr_size-1):
#             # Find pair in subarray A[i + 1..n-1] 
#             # with sum equal to sum - A[i]
#             s = set()
#             curr_sum = sum - A[i]
#             for j in range(i + 1, arr_size):
#                 if (curr_sum - A[j]) in s:

#                     return True
#                 s.add(A[j])
        
#         return False




#O(n^2 Soln), O(1) Space... Should get AC :) But didn't get AC :(

# class Solution:
#     #User function Template for python3
#     # arr[] : The input Array
#     # N : Size of the Array
#     # X : Sum which you need to search for 
#     #Function to find if there exists arr triplet in the 
#     #array arr[] which sums up to X.
#     def find3Numbers(self,arr, N, X):
#         arr.sort()
#         start = 1
#         end = N-1
#         for i in range(N-2):
#             start = i+1
#             end = N-1
#             while(start<end):
#                 if(arr[i]+arr[start]+arr[end] == X):
#                     return True
#                 elif(arr[i]+arr[start]+arr[end] < X):
#                     start+=1
#                 else:
#                     end-=1
            
#         return False
class Solution:
    def find3Numbers(self, A, arr_size, sum):
        for i in range(0, arr_size-1):
            # Find pair in subarray A[i + 1..n-1] 
            # with sum equal to sum - A[i]
            s = set()
            curr_sum = sum - A[i]
            for j in range(i + 1, arr_size):
                if (curr_sum - A[j]) in s:
                    return True
                s.add(A[j])
        
        return False



sol = Solution()

# 50 182
# 589 343 609 61 222 759 955 889 147 691 950 844 431 621 749 68 537 784 36 227 186 39 854 630 225 749 924 360 258 767 945 956 319 727 412 26 356 2 550 497 585 516 965 343 76 914 143 197 949 73

print(sol.find3Numbers(list(map(int, input().split())),50, 182))
