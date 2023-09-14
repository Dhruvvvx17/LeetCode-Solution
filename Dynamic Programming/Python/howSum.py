# given a target an an array of non-negative integers, return a combination of values that sum up to the target value.
# the numbers can be used repeatedly. If no combination possible return NULL

# Time Complexity brute force is O(n^m * m) - (branching factor ^ tree height * copying array elements)
# Time Complexity with memoization O(m*n * m) - m is the target and n is the number of elements. (Second m is copying array elements)

# as python allowes different return type for the same function (None or a list) as opposed to C++, it can be used to 
# simply return None or best list until now rather that true/false and a list in method params that's modified.

cache = {}
def howSum(target, arr):

    # edge cases
    if(target == 0):
        return []
    if(target < 0):
        return None

    # cache check
    if(target in cache):
        return cache[target]

    # if not found in cache
    for num in arr:
        res = howSum(target-num, arr)
        if not(res == None):
            res.append(num)
            cache[target] = res[:]
            return cache[target]

    # this branch did not lead to a solution
    cache[target] = None
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

    res = howSum(target, arr)
    if(res):
        print(f"{target} can be generated from array elements {res}")
    else:
        print(f"{target} cannot be generated from array")