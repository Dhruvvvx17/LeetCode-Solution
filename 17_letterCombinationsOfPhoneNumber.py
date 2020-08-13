def letterCombinations(digits):
    mapping = { '1': [], '2':['a','b','c'], '3':['d','e','f'], '4':['g','h','i'], '5':['j','k','l'], '6':['m','n','o'], '7': ['p','q','r','s'], '8':['t','u','v'], '9':['w','x','y','z'] }
    
    if(len(digits) == 0):
        return([])
    
    res = mapping[digits[0]]
    
    for digit in digits[1:]:
        values = mapping[digit]
        temp = []
        l = len(res)
        for val in values:
            for i in range(l):
                ele = res[i]
                ele += val
                temp.append(ele)
        
        res = temp
        
    return(res)

if __name__ == "__main__":
    print("Enter input number: ",end="")
    number = input()
    print(f"Letter combinations of {number} = {letterCombinations(number)}")
