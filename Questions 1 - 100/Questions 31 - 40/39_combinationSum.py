
def combinationSum(candidates, target):
    res = []
    candidates.sort()
    dfs(candidates,target,0,[],res)
    return res

def dfs(candidates, target, index, curr_path, res):
    
    # Backtracking
    if target<0:
        return
    
    # Got the original sum with the numbers in curr_path
    elif target==0:
        res.append(curr_path)
        
    else:
        for i in range(index,len(candidates)):
            dfs(candidates, target-candidates[i], i, curr_path+[candidates[i]], res)
                
if __name__ == "__main__":
    print("Enter array elements: ",end="")
    arr = list(map(int,input().split()))

    print("Enter target: ",end="")
    target = int(input())

    print(f"Array elements that can be added to {target} (repetion allowed) are: {combinationSum(arr,target)}")