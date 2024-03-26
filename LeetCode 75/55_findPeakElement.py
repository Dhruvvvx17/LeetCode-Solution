def findPeakElement(nums):
    
    n = len(nums) - 1

    if not n:
        return 0

    left, right = 0, n

    while left <= right:
        pos = left + (right - left)//2

        if pos == 0 and nums[pos] > nums[pos+1]:
            return pos
        
        if pos == n and nums[pos] > nums[pos-1]:
            return pos
        
        if nums[pos] > nums[pos+1] and nums[pos] > nums[pos-1]:
            return pos
        
        else:
            if nums[pos+1] > nums[pos]:
                left = pos + 1
            else:
                right = pos -1 
    
    return -1

if __name__ == "__main__":

    nums = [1,2,1,3,5,6,4]

    print(f"Peak element found at index = {findPeakElement(nums)}")