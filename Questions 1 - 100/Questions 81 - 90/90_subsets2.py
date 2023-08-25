from itertools import combinations
from typing import List

def subsetsWithDup(nums: List[int]) -> List[List[int]]:
    
    # sort the array 
    nums.sort()
    
    # final result list
    res = list()

    # use combinations to generate all combinations
    for i in range(0,len(nums)+1):
        temp = list(map(list,combinations(nums,i)))
        res+=temp

    # extract only unique combinations
    res = [list(x) for x in set(tuple(x) for x in res)]
    return res

if __name__ == "__main__":
    n = int(input("Enter no. of list elements: "))
    arr = list()
    for i in range(n):
        arr.append(int(input(f"Enter element {i}: ")))

    print(f"All possible subsets: {subsetsWithDup(arr)}")