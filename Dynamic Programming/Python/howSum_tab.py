# given a target an an array of non-negative integers, return a combination of values that sum up to the target value.
# the numbers can be used repeatedly. If no combination possible return NULL

# Time: O(m * n * m)    (iterating through table * iterating through nums * copying array elements at a new location)

def howSum_tab(target, arr):

    table = [None for _ in range(target+1)]

    # possible to generate 0 by not using any number from arr
    table[0] = []

    for i in range(target+1):
        if not(table[i] == None):
            for j in range(len(arr)):
                # out of bounds check
                if(i + arr[j] < len(table)):
                    table[i + arr[j]] = table[i][:]     # this step account for the last 'm' in complexity
                    table[i + arr[j]].append(arr[j])
    
    return table[target]


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    i = 0
    arr = []
    while(i<n):
        t = int(input(f"Enter element {i}: "))
        arr.append(t)
        i += 1
    
    target = int(input("Enter target: "))

    res = howSum_tab(target, arr)
    if(res):
        print(f"{target} can be generated from array elements {res}")
    else:
        print(f"{target} cannot be generated from array")