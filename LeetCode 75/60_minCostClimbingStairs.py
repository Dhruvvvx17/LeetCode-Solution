def minCostClimbingStairs(cost):
    res = [cost[0], cost[1]]
    n = len(cost)
    if n == 2:
        return min(res)

    for i in range(2, n):
        temp = min(cost[i] + res[i-1], cost[i] + res[i-2])
        res.append(temp)
    
    return min(res[-1], res[-2])

if __name__ == "__main__":
    cost = [1,100,1,1,1,100,1,1,100,1]
    print(f"Min cost: {minCostClimbingStairs(cost)}")