def findTargetSumWays(nums, target):
    # maintain a cache
    # cache will store (index, total so far) -> number of ways
    dp = {}

    index = 0
    total = 0
    res = DFS(nums, index, total, dp, target)
    return res


def DFS(nums, index, total, dp, target):

    # 1 way if I have reached the last index and achieved target
    if(index == len(nums)):
        return 1 if total == target else 0

    if (index, total) in dp:
        return dp[(index, total)]

    # update cache with number of ways with addition and with subtraction
    dp[(index, total)] = DFS(nums, index + 1, total + nums[index], dp,
                             target) + DFS(nums, index + 1, total - nums[index], dp, target)

    return dp[(index, total)]


if __name__ == "__main__":

    nums = [1, 2, 3, 0, 4, -4]
    target = 0

    print(
        f"Number of ways to obtain target from nums is: {findTargetSumWays(nums, target)}")
