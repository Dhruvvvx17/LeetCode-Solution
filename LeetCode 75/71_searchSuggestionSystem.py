from typing import List

def suggestedProducts(products: List[str], searchWord: str) -> List[List[str]]:
    
    products.sort()

    res = []

    l, r  = 0, len(products)-1

    for i in range(len(searchWord)):
        ch = searchWord[i]
        temp = []

        while l <= r and (len(products[l]) <= i or products[l][i] != ch):
            l += 1
        
        while l <= r and (len(products[r]) <= i or products[r][i] != ch):
            r -= 1
        
        for x in range(l, l + min(3, r-l+1)):
            temp.append(products[x])
        
        res.append(temp)
    
    return res

if __name__ == "__main__":
    products = ["mobile","mouse","moneypot","monitor","mousepad"]
    searchWord = "mouse"

    print(f"The possible autocompletes are: {suggestedProducts(products, searchWord)}")