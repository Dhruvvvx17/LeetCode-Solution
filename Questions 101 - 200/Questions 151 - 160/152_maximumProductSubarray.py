import math


def maxProduct(nums):

    res = float(-math.inf)
    curr_max = 1
    curr_min = 1

    for num in nums:
        # update the products
        temp_max = curr_max * num
        temp_min = curr_min * num

        curr_max = max(temp_max, temp_min, num)
        curr_min = min(temp_max, temp_min, num)

        res = max(curr_max, curr_min, res)

        # reset if 0 encountered
        if(curr_max == 0):
            curr_max = 1
        if(curr_min == 0):
            curr_min = 1

    return res


if __name__ == "__main__":
    nums = [2, 3, -2, 4]

    print(f"Maximum product subarray is: {maxProduct(nums)}")
