class Solution:
    def threeWayPartition1(self, array, a, b):
        array.sort()
        return array
    def threeWayPartition2(self, array, a, b):
        low = 0
        mid = 0
        high = len(array)-1
        while(mid<=high):
            print('array = ', array)
            if array[mid]<a:
                array[low], array[mid] = array[mid], array[low]
                low+=1
                mid+=1
            elif array[mid]>b:
                array[high], array[mid] = array[mid], array[high]
                high-=1
            else:
                mid+=1

    def threeWayPartition3(self, arr, n, lowVal, highVal): 
  
        # Initialize ext available positions for 
        # smaller (than range) and greater lements 
        start = 0
        end = n - 1
        i = 0
    
        # Traverse elements from left 
        while i <= end: 
    
            # If current element is smaller than 
            # range, put it on next available smaller 
            # position. 
            if arr[i] < lowVal: 
                temp = arr[i] 
                arr[i] = arr[start] 
                arr[start] = temp 
                i += 1
                start += 1
    
            # If current element is greater than 
            # range, put it on next available greater 
            # position. 
            elif arr[i] > highVal: 
                temp = arr[i] 
                arr[i] = arr[end] 
                arr[end] = temp 
                end -= 1
    
            else: 
                i += 1
sol = Solution()

array = [4,5,2,4,7,8,6,1,5,2]
a = 3
b = 6
sol.threeWayPartition1(array,a,b)
print(array)                
