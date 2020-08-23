def firstMissingPositive(nums):
    nums.append(0)
    n = len(nums)
    
    # Remove all useless numbers 
    for i in range(n):
        if(nums[i]<0 or nums[i]>=n):
            nums[i] = 0
    
    # To capture the frequency of every element from 0 to n, in the index 0 to n respectively
    for i in range(n):
        nums[nums[i]%n] += n
    
    # Find the number with frequency 0
    for i in range(1,n):
        if nums[i]//n == 0:
            return i
    
    return n      

if __name__ == "__main__":
    print("Enter array elements: ",end="")
    arr = list(map(int,input().split()))

    print(f"First missing positive in {arr} is {firstMissingPositive(arr)}")