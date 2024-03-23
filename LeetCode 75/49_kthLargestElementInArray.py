import heapq

def findKthLargest(nums, k):
    
    h = heapq.heapify(nums)
    res = -1

    # as python heap is a min heap, instead of finding kth largest, we can find n-kth smallest
    l = len(nums) - k

    while(l >= 0):
        res = heapq.heappop(nums)
        l -= 1

    return res

if __name__ == "__main__":
    nums = [3,2,1,5,6,4]
    k = 2

    print(f"Kth largest element is: {findKthLargest(nums, k)}")