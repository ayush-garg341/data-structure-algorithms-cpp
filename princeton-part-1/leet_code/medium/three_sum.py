class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = {}
        n = len(nums)
        nums.sort()
        
        for k in range(n):
            i = k+1
            j = n-1
            
            while(i<j):
                if nums[i] + nums[j] == -nums[k] and (nums[k],nums[i],nums[j]) not in ans: 
                    ans[(nums[k],nums[i],nums[j])] = 1
                    i+=1
                elif nums[i] + nums[j] < -nums[k] : 
                    i+=1
                else:
                    j-=1
        return [list(k) for k in ans]

