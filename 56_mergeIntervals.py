def merge(intervals):
    
    if(len(intervals)==0):
        return []
    
    intervals.sort(key = lambda x: x[0])
    
    res = [intervals[0]]
    
    for interval in intervals[1:]:
        
        #If starting index of the new interval is greater than the ending of existing interval then append
        if(interval[0]>res[-1][1]):
            res.append(interval)

        else:
            res[-1][1] = max(res[-1][1],interval[1])

    return res

if __name__ == "__main__":
    print("Enter number of intervals: ",end="")
    n = int(input())

    arr = []
    for i in range(n):
        print(f"Enter starting index for interval {i}: ",end="")
        s = int(input())
        print(f"Enter ending index for interval {i}: ",end="")
        e = int(input())
        arr.append([s,e])

    print("Result after merging intervals: ",end="")
    res = merge(arr)
    print(res)