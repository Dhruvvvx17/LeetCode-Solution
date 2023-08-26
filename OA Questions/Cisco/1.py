# Given an array of numbers, find the maximum different between two numbers such that 
# the smaller number appears before the larger number.

# eg: 
# array = [2, 3, 10, 6, 4, 8]
# result = 8

# Logic: iterate from left to right, keep track of the global max difference and the smallest number observed

def findMaxDiff(arr):

    curr_max_diff = 0
    curr_min = arr[0]

    for num in arr[1:]:
        curr_max_diff = max(curr_max_diff, num - curr_min)
        curr_min = min(curr_min, num)

    return curr_max_diff

if __name__ == "__main__":
    arr = [2, 3, 10, 6, 4, 8]
    print(f"The max difference observed (smaller number before larger number) is: {findMaxDiff(arr)}")