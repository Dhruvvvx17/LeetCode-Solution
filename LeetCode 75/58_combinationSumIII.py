def combinationSum3(k: int, n: int):

    res = []
    dfs(0, k, n, [], res)
    return res

def dfs( num, k, target, path, res):
    
    if len(path) == k:
        if target == 0:
            res.append(path)
        return
    
    for i in range(num+1,10):
        if i not in path:
            dfs(i, k, target - i, path + [i], res)
    
    return

if __name__ == "__main__":
    k = 3
    n = 9
    print(f"combination of {k} that sum up to {n}: {combinationSum3(k, n)}")