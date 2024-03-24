def successfulPairs(spells, potions, success):
    
    potions = sorted(potions)
    res = []

    for spell in spells:
        # mix = [p * spell for p in potions]
        # print(mix)
        left = 0
        right = len(potions)-1
        while (left <= right):
            mid = left + (right - left) // 2
            if potions[mid] * spell >= success:
                right = mid - 1
            else:
                left = mid + 1
        
        res.append(len(potions) - left)
    
    return res

if __name__ == "__main__":
    spells = [5,1,3]
    potions = [1,2,3,4,5]
    success = 7

    print(f"Number of successful pairs: {successfulPairs(spells, potions, success)}")