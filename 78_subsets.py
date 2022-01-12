from itertools import combinations


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        for i in range(len(nums)+1):
            res += list(map(list,combinations(nums,i)))
        
        return(res)