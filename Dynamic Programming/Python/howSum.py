#  given a target an an array of non-negative integers, return a combination of values that sum up to the target value.
#  the numbers can be used repeatedly. If no combination possible return NULL

#  Time Complexity brute force is O(n^m * m) - (branching factor ^ tree height * copying array elements)
#  Time Complexity with memoization O(m*n * m) - m is the target and n is the number of elements. (Second m is copying array elements)

cache = {}
def howSum(target, arr, res):

    # edge cases
    if(target == 0):
        return True
    if(target < 0):
        return False

    # cache check
    if(target in cache):
        savedSolution = cache[target]
        if(len(savedSolution) == 0):
            return False
        return True

    # if not found in cache
    for num in arr:
        if(howSum(target-num, arr, res)):
            res.append(num)
            cache[target] = res[:]
            return True

    # this branch did not lead to a solution
    cache[target] = []
    return False


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    i = 0
    arr = []
    while(i<n):
        t = int(input(f"Enter element {i}: "))
        arr.append(t)
        i += 1
    
    target = int(input("Enter target: "))
    res = []

    if(howSum(target, arr, res)):
        print(f"{target} can be generated from array elements {res}")
    else:
        print(f"{target} cannot be generated from array")