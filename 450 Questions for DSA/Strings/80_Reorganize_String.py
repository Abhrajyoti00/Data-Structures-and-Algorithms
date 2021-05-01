import heapq
class Solution:
    def reorganizeString(self, S):
        pq = [(-S.count(x), x) for x in set(S)]
        heapq.heapify(pq)
        result = []
        while(len(pq)>1):
            # print('pq = ', pq)
            current_count, current_ele = heapq.heappop(pq)
            next_count, next_ele = heapq.heappop(pq)
            result.extend([current_ele, next_ele])
            if current_count+1<0:
                heapq.heappush(pq, (current_count+1, current_ele))
            if next_count+1<0:
                heapq.heappush(pq, (next_count+1, next_ele))
        # print(result)
        if(len(pq)>0):
            # print(pq)
            last_count, last_ele = heapq.heappop(pq)
            
            if last_count < -1:
                return ""
            result.extend(last_ele)
        return "".join(result)

sol = Solution()
S = "aaabb"
S = "aaabbbcc"
# S = "aaab"
print(sol.reorganizeString(S))