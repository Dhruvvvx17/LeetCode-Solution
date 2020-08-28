'''NEWTONS FORMULA TO CALCULATE SQRT'''

def mySqrt(x: int) -> int:
    r = x
    while r*r > x:
        r = (r + x//r) // 2
    return r

if __name__ == "__main__":
    print("Enter a number: ",end="")
    n = int(input())

    res = mySqrt(n)
    print(f"The number just lesser than Square root of {n} = {res} with value {res**2}")