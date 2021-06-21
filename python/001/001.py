class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0; j = 0; k = len(nums)
        for i in range(0, k):
            for j in range(i+1, k):
                if nums[i] == target - nums[j]:
                    return [i,j]
        return [-1,-1]