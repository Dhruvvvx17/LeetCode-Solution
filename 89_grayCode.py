from typing import List

# graycode trick:
# n=1: [0,1]
# n=2: [0,1] + add 2^(n-1) to every element of the previous list in reverse order
# ie;  [0,1] + (2^1+1) + (2^1+0)
# n=2: [0,1] + 3 + 2 = [0,1,3,2]

def grayCode(n: int) -> List[int]:
    
    if n == 1:
        return [0,1]

    res = [0,1]
    for i in range(1,n):
        res += map(lambda x: x+(2**i),res[::-1])
                
    return res

if __name__ == "__main__":
    for i in range(1,5):
        print(f"grayCode-{i}:",grayCode(i))