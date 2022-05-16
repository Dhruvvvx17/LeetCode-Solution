# check out Boyer-Moore Voting Algorithm
from typing import List

def majorityElement(nums: List[int]) -> int:
    
    if(len(nums)==1):
        return nums[0]
    
    count = dict()
    max_num = -1
    max_num_count = -1
    
    for num in nums:
        if num not in count:
            count[num] = 1
        else:
            count[num] += 1
            if(count[num]>max_num_count):        
                max_num_count = count[num]
                max_num = num
    
    return max_num

if __name__ == "__main__":
    n = list(input("Enter list of elements: ").split())
    nums = list(map(int, n))

    res = majorityElement(nums)

    print(f"Majority element is: {res}")


    
