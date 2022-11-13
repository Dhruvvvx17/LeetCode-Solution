
def rob(nums):
    # edge case-1
    if(len(nums) == 1):
        return nums[0]

    # edge case-2
    if(len(nums) == 2):
        return max(nums[0], nums[1])

    # update value at 1st index based on 0th and 1st
    nums[1] = max(nums[0], nums[1])

    # general case - make a greedy decision at every point
    for i in range(2, len(nums)):
        nums[i] = max(nums[i] + nums[i-2], nums[i-1])

    # last element stores the max to gain from entire array
    return nums[-1]


if __name__ == "__main__":

    nums = [1, 2, 3, 1, 4, 2, 3, 8, 1]
    print(f"Max that the robber can rob is: {rob(nums)}")

    nums = [1, 3, 2, 5, 1, 2, 3]
    print(f"Max that the robber can rob is: {rob(nums)}")
