# given a target an an array of non-negative integers, find out if the target can be constructed using the number of the array.
# the numbers can be used repeatedly.

def canSum_tab(target, arr):
    table = [False for _ in range(target+1)]
    table[0] = True

    for i in range(0, target+1):
        if table[i]:
            for shift in arr:
                if i + shift < len(table):
                    table[i+shift] = True

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

    if(canSum_tab(target, arr)):
        print(f"{target} can be generated from array")
    else:
        print(f"{target} cannot be generated from array")