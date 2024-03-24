import heapq

def maxScore(nums1, nums2, k):
    
    n = len(nums1)
    pairs = []

    for i in range(n):
        pairs.append([nums2[i], nums1[i]])
    
    # nums1 = [1, 3, 3, 2]
    # nums2 = [2, 1, 3, 4]

    pairs = sorted(pairs, key = lambda x: x[0], reverse = True)

    # pairs = [[4, 2], [3, 3], [2, 1], [1, 3]]
    # reverse sorting ensures the maximum sum at all times
    # heap ensures only the smallest number of the subsequence is removed at every step

    sum_n1 = 0
    res = 0
    min_n2 = 10**10
    pq = []

    for i in range(n):
        n2 = pairs[i][0]    
        n1 = pairs[i][1]    

        sum_n1 += n1        
        heapq.heappush(pq, n1)

        if (len(pq) > k):
            sum_n1 -= heapq.heappop(pq)
        
        if len(pq) == k:
            res = max(res, n2 * sum_n1)

    return res

if __name__ == "__main__":

    nums1 = [1,3,3,2]
    nums2 = [2,1,3,4]
    k = 3

    print(f"result: {maxScore(nums1, nums2, k)}")