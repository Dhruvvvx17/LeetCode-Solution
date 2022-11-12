from typing import List


def productExceptSelf(nums: List[int]) -> List[int]:
    # an array where value at i is a product of nums[0] to nums[i-1]
    left = [1]

    left_prod = 1
    for i in range(len(nums)-1):
        left_prod *= nums[i]
        left.append(left_prod)

    # another array where value at i is a product of nums[i+1] to nums[n-1]
    right = [1]
    right_prod = 1
    for i in range(len(nums)-1, 0, -1):
        right_prod *= nums[i]
        right.append(right_prod)

    right = right[::-1]

    # print(left)
    # print(right)

    # multiplying the two products from the left of i and right of i
    res = [left[i] * right[i] for i in range(len(left))]

    return res


# more efficient solution over memory using only O(n) extra space
def productExceptSelf2(nums: List[int]) -> List[int]:

    arr = [1]

    # first iteration from left to right storing the product from o to i in index i+1
    left_prod = 1
    for i in range(len(nums)-1):
        left_prod *= nums[i]
        arr.append(left_prod)

    # second iteration from right to left storing the product of arr[i] (left product) and product of i+1 to n-1
    right_prod = 1
    for i in range(len(nums)-1, -1, -1):
        arr[i] = arr[i] * right_prod
        right_prod *= nums[i]

    return(arr)


if __name__ == "__main__":

    nums = [1, 2, 3, 4, 5]

    print("Product of array except self method1: ", productExceptSelf(nums))

    print("Product of array except self method2: ", productExceptSelf2(nums))
