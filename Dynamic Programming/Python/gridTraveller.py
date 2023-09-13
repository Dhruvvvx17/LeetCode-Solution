# Given a mxn grid, how many ways can I go from the start (0,0) to the end (m,n) by just moving RIGHT or DOWN

cache = {}

def gridTraveller(m,n):
    key = str(m) + "_" + str(n)
    if key in cache:
        return cache[key]
    
    if(m==1 and n==1):
        return 1
    if(m==0 or n==0):
        return 0
    
    cache[key] = gridTraveller(m-1,n) + gridTraveller(m,n-1)
    return cache[key]

if __name__ == "__main__":
    m = int(input("Enter number of rows: "))
    n = int(input("Enter number of cols: "))

    print(f"Number of ways to travel from (1,1) to ({m},{n}): {gridTraveller(m,n)}")