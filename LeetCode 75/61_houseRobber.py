def rob(nums):
    n = len(nums)

    if n == 1:
        return nums[0]
    if n == 2:
        return max(nums)

    a = nums[0]
    b = max(nums[0], nums[1])

    for i in range(2, n):
        res = max(a + nums[i], b)
        a = b
        b = res
    
    return res

if __name__ == "__main__":
    nums = [2,7,9,3,1]

    print(f"Max that can be robbed: ${rob(nums)}")