def sortColors(nums):
    """
    red - 0
    white - 1
    blue - 2
    """
    red,white,blue = 0,0,len(nums)-1
    
    while(white<=blue):
        
        if nums[white] == 0:
            nums[white],nums[red] = nums[red],nums[white]
            white += 1
            red += 1
            
        elif nums[white] == 1:
            white += 1
            
        else:
            nums[white],nums[blue] = nums[blue],nums[white]
            blue -= 1

    return nums
                

if __name__ == "__main__":
    nums = [2,2,1,1,0,1,2,0,2,1,0,0,0,2]
    print("Original list: ",nums)
    print("New list: ",sortColors(nums))
                    