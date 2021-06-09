#Answer is N-1


# class Solution:
# def countSquares(self, N):
#     square_root = 1
#     count = 0
#     while(square_root*square_root < N):
#         square_root+=1
#         count+=1
#     return count

# OR

# import math
# class Solution:
#     def countSquares(self, N):
#         return int(math.sqrt(N-1))

class Solution:
    def countSquares(self, N):
        
        N = N-1
        # Base cases
        if (N== 0 or N== 1) :
            return N
    
        # Do Binary Search for floor(sqrt(N))
        start = 1
        end = N 
        while (start <= end) :
            mid = (start + end) // 2
            
            # If Nis a perfect square
            if (mid*mid == N) :
                return mid 
                
            # Since we need floor, we update
            # answer when mid*mid is smaller
            # than N, and move closer to sqrt(N)
            if (mid * mid < N) :
                start = mid + 1
                ans = mid
                
            else :
                
                # If mid*mid is greater than N
                end = mid-1
                
        return ans

sol = Solution()
N = int(input())
print(sol.countSquares(N))

'''
Stress Test : - 

30895603985623059863498689630498623509283650239858326503958632405983650923856023985623945862059865206502389560239463250985034986523098562039846305986235098650349888888888888888888888888
'''