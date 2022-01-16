# O(n^2) time complexity

def threeSumClosest(nums,target):
    
    diff = 10000000
    res = 0
    nums.sort()
    print(nums)
    visited = set()
    
    for i in range(len(nums)-2):
        
        if(nums[i] in visited): continue
        
        visited.add(nums[i])
        curr = nums[i]
        left_index = i+1
        right_index = len(nums)-1
        
        while(left_index<right_index):
            total = curr + nums[left_index] + nums[right_index]
            if(total==target):
                return total
            
            if(abs(total-target)<abs(diff)):
                diff = abs(total-target)
                res = total
                
            # Go closer to the target depending upon current sum
            if(total<target):
                left_index += 1
            else:
                right_index -= 1
                
            # print(target,diff,total)
            
    return(res)

if(__name__ == "__main__"):
    arr = [-1,2,1,-4]
    target = 2
    print(f"The closest 3sum to {target} is: {threeSumClosest(arr,target)}")