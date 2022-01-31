from typing import List

def generate(numRows: int) -> List[List[int]]:
    
    # first row
    if(numRows==1):
        return [[1]]
    
    # second row
    if(numRows==2):
        return [[1],[1,1]]

    # row 3 and greater
    res = [[1],[1,1]]
    
    for i in range (2,numRows):
        prev = res[i-1]
        new = [1]       # start with 1       

        # add consecutive numbers and append to new list
        for index in range(len(prev)-1):
            new.append(prev[index]+prev[index+1])
        
        new.append(1)   # end with 1
        
        res.append(new) # append new list to overall result
        
    return res

if __name__ == "__main__":
    n = int(input("Enter number of rows: "))
    res = generate(n)

    for row in res:
        print(row)
