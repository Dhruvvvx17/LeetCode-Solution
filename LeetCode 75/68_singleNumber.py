def singleNumber(nums):
    res = 0

    for num in nums:
        res = res ^ num

    return res

if __name__ == "__main__":
    
    nums = [4,1,2,1,2]

    print(f"The single number in {nums} is {singleNumber(nums)}")