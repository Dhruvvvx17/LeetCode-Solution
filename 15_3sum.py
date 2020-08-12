def threeSum(nums):
    
    nums.sort()
    
    res = []
    for i in range(len(nums)-2):

        # To check if prev curr value is same as the new curr value. In which case the res will get duplicate values.
        # Hence, avoid that!
        if( i>0 and nums[i]==nums[i-1]):
            continue
        
        curr = nums[i]          # curr holds a constant number.
        left_index = i+1        # left index and right index denote the smallest and largest numbers in the array after curr
        right_index = len(nums)-1


        # either reduce the right pointer or incr the left pointer and check if total is 0.
        while(left_index < right_index):
            total = curr + nums[left_index] + nums[right_index]
            if(total==0):
                res.append([curr,nums[left_index],nums[right_index]])
                while(left_index < right_index and nums[left_index] == nums[left_index+1]):
                    left_index += 1
                while(left_index < right_index and nums[right_index] == nums[right_index-1]):
                    right_index -= 1
                
                left_index += 1
                right_index -= 1
        
            elif(total<0):
                # Try to increase the total by going towards a greater number
                left_index += 1
            else:
                # Try to decrease the total by going towards a smaller number
                right_index -= 1

    return res

if(__name__ == "__main__"):
    arr = [-1, 0, 1, 2, -1, -4, 3, 0, 0]
    print(f"Numbers satisfying 3sum condition are: {threeSum(arr)}")