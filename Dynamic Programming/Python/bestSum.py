cache = {}
def bestSum(target, arr):

    # true edge cases
    if(target == 0):
        return []

    # false edge case
    if(target < 0):
        return None

    # cache check
    if(target in cache):
        return cache[target]

    # variable to keep track of best combination for current target
    shortestCombination = None

    # if not found in cache
    for num in arr:
        temp = bestSum(target-num, arr)
        if not(temp == None):
            currentCombination = temp + [num]
            if(not shortestCombination or len(currentCombination) < len(shortestCombination)):
                shortestCombination = currentCombination

    cache[target] = shortestCombination
    return cache[target]


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    i = 0
    arr = []
    while(i<n):
        t = int(input(f"Enter element {i}: "))
        arr.append(t)
        i += 1
    
    target = int(input("Enter target: "))

    res = bestSum(target, arr)
    if(res):
        print(f"{target} can be generated from array elements {res}")
    else:
        print(f"{target} cannot be generated from array")