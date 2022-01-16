# Generating all permutations of a given list of UNIQUE numbers

import itertools

# Alternate method
def permuteAlternate(nums):
    return list(map(list,itertools.permutations(nums)))


def permute(nums):    
    # Using DFS
    res = []
    dfs(nums,[],res)
    return res


def dfs(nums,path,res):
    
    if(len(nums)==0):
        res.append(path)
    
    for i in range(len(nums)):
        dfs(nums[:i]+nums[i+1:],path+[nums[i]],res)

if __name__ == "__main__":
    print("Enter array elements [UNIQUE ONLY]: ",end="")
    arr = []
    arr = list(map(int,input().split()))

    print(f"Permutations of the given list of numbers = {permute(arr)}")
    print(f"Permutations of the given list of numbers = {permuteAlternate(arr)}")


