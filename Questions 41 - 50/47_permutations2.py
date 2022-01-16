# Generating all permutations of a given list of numbers (Repetition allowed)

def permute(nums):    
    # Using DFS
    
    res = []
    # Sorting the numbers to later make it easier to check for a repeting permutation at an early step in dfs
    nums.sort()
    dfs(nums,[],res)
    return res


def dfs(nums,path,res):
    
    if(len(nums)==0):
        res.append(path)
    
    for i in range(len(nums)):
        # If condition satisfied then it would end up in a repeated permutation.
        if i>0 and nums[i] == nums[i-1]:
            continue
        else:
            dfs(nums[:i]+nums[i+1:],path+[nums[i]],res)

if __name__ == "__main__":
    print("Enter array elements [UNIQUE ONLY]: ",end="")
    arr = []
    arr = list(map(int,input().split()))

    print(f"Permutations of the given list of numbers = {permute(arr)}")