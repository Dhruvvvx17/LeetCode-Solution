import math

def minEatingSpeed(piles, h):
    
    l = 1
    r = max(piles)

    # max the solution can be
    res = r

    while l <= r:
        k = (l + r)//2
        hours = 0
        for p in piles:
            hours += math.ceil(p/k)
        
        if hours <= h:
            res = min(res, k)
            r = k - 1
        else:
            l = k + 1
    
    return res

if __name__ == "__main__":

    piles = [3,6,7,11]
    h = 8

    print(f"Minimum eating speed to eat all piles: {minEatingSpeed(piles, h)}")