from typing import List

# array of size 34 because acc to constraints max rowIndex=33
# so 0-33 => 34 possible factorial values
factArray = [None]*34

# return factorial if precomputed else calculate, store and return
def fact(n):
    
    # return if available
    if(factArray[n]):
        return factArray[n]

    # compute if not available
    factorial = 1
    for i in range(2,n+1):
        factorial = factorial*i

    # store and return
    factArray[n] = factorial
    return factArray[n]

def getRow(rowIndex: int) -> List[int]:
    
    # 0th Row
    if(rowIndex==0):
        return [1]
    
    # 1st Row
    if(rowIndex==1):
        return [1,1]
    
    # 2nd Row or above
    n = rowIndex
    res = [0]*(n+1)
    mid = (rowIndex//2)
                        

    # Calculate only for one half, as the other half is a mirror image
    for index in range(mid+1):
        # Calculate binomial coefficient for every index
        res[index] = fact(n)//(fact(index)*fact(n-index))
    
    if(rowIndex%2==0):
        temp = res[:mid]
    else:
        temp = res[:mid+1]
        
    res[mid+1:] = temp[::-1]
        
    return res


if __name__ == "__main__":
    row = int(input("Enter row value: "))
    print(f"Pascal's triangle values for row {row}: {getRow(row)}")