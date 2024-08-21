import heapq

def findKthLargest(nums, k) -> int:
    
    h = nums[:]

    h = list(map(lambda x: x*(-1), h))
    heapq.heapify(h)

    while k > 1:
        heapq.heappop(h)
        k -= 1
    
    res = 0 - heapq.heappop(h)
    return  res

if __name__ == "__main__":
    nums = [3,2,3,1,2,4,5,5,6]
    k = 4

    print(f"{k}-th largest number in the array is: {findKthLargest(nums, k)}")