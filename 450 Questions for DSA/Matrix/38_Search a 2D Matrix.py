class Solution:

    def binarySearch(self, array, target):
        first = 0
        last = len(array)-1
        while(first<=last):
            mid = first+(last-first)//2
            if array[mid] == target:
                return True
            elif (array[mid]<target):
                first = mid+1
            elif (array[mid]>target):
                last = mid-1
        return False


    def searchMatrix(self, matrix,target):
        start_list = []
        reqd_index = len(start_list)-1
        for lists in matrix:
            start_list.append(lists[0]) #Stored the first element of all lists
        for i in range(len(start_list)):
            if start_list[i]==target:
                reqd_index = i
                break
            elif start_list[i]>target:
                reqd_index = i-1
                break
        # print(matrix[reqd_index], target)
        return self.binarySearch(matrix[reqd_index], target)
    
sol = Solution()
# matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
# matrix = [[1],[3]]
matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
target = 30
print(sol.searchMatrix(matrix, target))
