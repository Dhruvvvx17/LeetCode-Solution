# given a target an an array of non-negative integers, return the smallest combination of values that sum up to the target value.
# the numbers can be used repeatedly. If no combination possible return NULL

def bestSum_tab(target, arr):

    table = [None for _ in range(target+1)]

    # possible to generate 0 by not using any number from arr
    table[0] = []

    for i in range(len(table)):
        # check for valid positions
        if not(table[i] == None):
            for j in range(len(arr)):
                # check for out of bounds
                if(i + arr[j] < len(table)):
                    # if new position is None or if new position has a longer result - copy the original (table[i])
                    if(table[i + arr[j]] == None or len(table[i + arr[j]]) > len(table[i])):
                        table[i + arr[j]] = table[i][:]
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

    res = bestSum_tab(target, arr)
    if(res):
        print(f"{target} can be generated from array elements {res}")
    else:
        print(f"{target} cannot be generated from array")