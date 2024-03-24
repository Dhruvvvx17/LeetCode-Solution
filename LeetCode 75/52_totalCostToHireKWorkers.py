import heapq

def totalCost(costs, k, candidates):
    
    start_heap = []
    end_heap = []
    res_cost = 0
    hired = 0
    left = 0
    right = len(costs) - 1

    while hired < k:

        while len(start_heap) < candidates and left <= right:
            heapq.heappush(start_heap, costs[left])
            left += 1

        while len(end_heap) < candidates and right >= left:
            heapq.heappush(end_heap, costs[right])
            right -= 1
        
        potential_left = start_heap[0] if len(start_heap) else 10 ** 10
        potential_right = end_heap[0] if len(end_heap) else 10 ** 10

        # print(start_heap, end_heap)

        if(potential_left <= potential_right):
            res_cost += potential_left
            heapq.heappop(start_heap)
        else:
            res_cost += potential_right
            heapq.heappop(end_heap)

        hired += 1
    
    return res_cost

if __name__ == "__main__":

    costs = [17,12,10,2,7,2,11,20,8]
    k = 3
    candidates = 4

    print(f"Total cost to hire {k} workers = {totalCost(costs, k, candidates)}")