# given a target an an array of non-negative integers, find out if the target can be constructed using the number of the array.
# the numbers can be used repeatedly.
# Time Complexity with memoization O(m*n) - m is the target and n is the number of elements.

cache = {}

def canSum(target, arr):
    if(target < 0):
        return False
    if(target == 0):
        return True
    if(target in cache):
        return cache[target]
    
    for num in arr:
        if(canSum(target-num, arr)):
            cache[target] = True
            return cache[target]
    
    cache[target] = False
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

    if(canSum(target, arr)):
        print(f"{target} can be generated from array")
    else:
        print(f"{target} cannot be generated from array")