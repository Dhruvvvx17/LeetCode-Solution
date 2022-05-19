def hammingWeight(n: int) -> int:
    res = 0
    while(n):
        n = n & (n-1)
        res += 1
        
    return res

if __name__ == "__main__":
    n = int(input("Enter the number n: "))
    print(f"Number of 1s in binary representation of n = {hammingWeight(n)}")