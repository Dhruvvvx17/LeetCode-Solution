import math

def getPermutation(n: int, k: int) -> str:
    
    numbers = [x for x in range(1,n+1)]
    res = ""
    k -= 1
    
    while(n>0):
        
        # Decrement n because the ith digit of a number has (n-i) possibilities
        # Going sequentially, need to reduce by 1 each time.
        n-=1 

        index, k = divmod(k,math.factorial(n))
        
        res += str(numbers.pop(index))
        
    return res


if __name__ == "__main__":
    # Given n and k generate the kth permutation using the first n natural number
    print("Enter n: ",end="")
    n = int(input())
    print("Enter k: ",end="")
    k = int(input())

    print(f"The {k}th permutation of numbers 1 to {n} is {getPermutation(n,k)}")
    