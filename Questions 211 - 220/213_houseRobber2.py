def rob(nums):

    if(len(nums) == 1):
        return nums[0]

    if(len(nums) == 2):
        return max(nums[0], nums[1])

    return max(helper(nums[1:]), helper(nums[:len(nums)-1]))


def helper(nums):

    # 0th index remains same
    # nums[0] = nums[0]

    # 1st index -> choice between max of nums[0] and nums[1]
    nums[1] = max(nums[0], nums[1])

    # greedy approach to find max until ith index
    for i in range(2, len(nums)):
        nums[i] = max(nums[i] + nums[i-2], nums[i-1])

    return nums[-1]


if __name__ == "__main__":

    nums = [1, 2, 3, 1, 4, 2, 3, 8, 1]
    print(f"Max that the robber can rob is: {rob(nums)}")

    nums = [1, 3, 2, 5, 1, 2, 3]
    print(f"Max that the robber can rob is: {rob(nums)}")
