'''Find the next permutation of the given list of numbers, WITHOUT USING EXTRA SPACE'''


def nextPermutation(nums):
    # If single element list, next permutation is the same unmodified list
    if(len(nums)==1):
        pass

    else:        
        # Starting from the right side, find the first decreasing element
        # eg: [3,7,5,8,6,4,2] => Here, the first decreasing element is 5 at position 2 (zero-indexed)
        i = len(nums)-1
        position = -1
        while(i>0):
            if(nums[i]>nums[i-1]):
                position = i-1
                break
            i -= 1

        # If no such position exists...        
        # It is the last lexographic permutation, so arrange in place in ascending order
        if(position==-1):
            nums.sort()

        # Find an element at a position greater than i-1 that is just greater than nums[i-1]
        # eg: [3,7,5,8,6,4,2] => Here, the first decreasing element is 5 at position 2 (zero-indexed)
        # eg: [3,7,5,8,6,4,2] => Here, the element just greater than 5 is 6 at postion 4 (zero-indexed)
        # Now switch the two numbers - New list : [3,7,6,8,5,4,2]
        # Now, reverse the list from i till the end. Final res: [3,7,6,2,4,5,8]
        else:
            ele = nums[position]
            min_value = 100000000   # Some large number
            min_index = -1

            for j in range(i,len(nums)):
                if nums[j] > ele and nums[j] <= min_value:
                    min_value = nums[j]
                    min_index = j

            # Swap the numbers at the two postions
            temp = nums[i-1] + nums[min_index]
            nums[i-1] = temp - nums[i-1]
            nums[min_index] = temp - nums[min_index]

            # Reverse the list from i till the end
            l = i
            r = len(nums)-1
            while(l<r):
                nums[l],nums[r] = nums[r],nums[l]
                l += 1
                r -= 1
            
            
if __name__ == "__main__":
    print("Enter a number: ",end="")
    n = input()
    nums = list(map(int,list(n)))

    nextPermutation(nums)
    print(f"Next permutation of {n} is {''.join(map(str, nums))}")