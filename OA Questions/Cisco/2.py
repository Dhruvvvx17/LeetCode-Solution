# Given an array of numbers, find the maximum sum such that two adjacent number cannot be picked for the sum.
# ex:
# arr = [2, 4, 6, 2, 5]
# res = 2 + 6 + 5 = 13

def findMaxSum(arr):

    curr_sum, prev_sum = arr[1],arr[0]

    for num in arr[2:]:
        next_sum = max(curr_sum, prev_sum + num)

        prev_sum = curr_sum
        curr_sum = next_sum

    return curr_sum

if __name__ == "__main__":
    arr = [2, 3, 10, 6, 8, 7, 1, 5]
    print(f"The max difference observed (smaller number before larger number) is: {findMaxSum(arr)}")