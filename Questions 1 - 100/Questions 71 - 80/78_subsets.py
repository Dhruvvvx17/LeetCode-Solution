from itertools import combinations
from typing import List


def subsets(nums: List[int]) -> List[List[int]]:
    res = []
    for i in range(len(nums)+1):
        res += list(map(list,combinations(nums,i)))
    
    return(res)

if __name__ == "__main__":
    print(subsets([1,2,3]))