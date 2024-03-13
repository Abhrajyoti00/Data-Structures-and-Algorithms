class Solution:
    def getPairsCount(self, arr, n, k):
        d = dict()
        count_of_pairs = 0
# First of all, I make a dictionary (Hash Table) of frequency.

        for ele in arr:
            d[ele] = d.get(ele,0)+1


        for ele in arr:
# Then I iterate through the array, as soon as I get an element, I decrease its count.
# Then I look for the presence of d[k-ele]. If the count is more than 0, then 
# we add its count. 


            '''
            Eg. arr = [1,1,1,1], k -2 
            d = {1:4}, count = 0
            1st time, ele = 1
            d[1] = 4-1 = 3 //d = {1:3}
            Is d[k-ele] > 0, d[2-1] > 0, yes 
            count = 0 + d[k-ele] = 0+3
            
            2nd iteration, ele = 1
            d[1] = 3-1 = 2 //d = {1:2}
            ..... Similarly, So count becomes, count = 0 + 3 + 2 + 1 = 6 Ans.
            '''

            d[ele]-=1
            if ele < k:
                if d.get(k-ele) is not None:
                    count_of_pairs+= d[k-ele]
        return count_of_pairs
        

soln = Solution()
# arr = [1,1,1,1]
# arr = [1,5,7,1]
arr = [1,1,2]
print(soln.getPairsCount(arr,3,2))