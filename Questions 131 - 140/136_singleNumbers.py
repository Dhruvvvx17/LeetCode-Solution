from typing import List

def singleNumber(nums: List[int]) -> int:
    
    # XOR Solution
    res = nums[0]
    for num in nums[1:]:
        res = res ^ num
        
    return res

if __name__ == "__main__":

    nums = input("Enter list of numbers: ")
    nums = list(map(int,nums.split()))

    print(f"Single number is: {singleNumber(nums)}")