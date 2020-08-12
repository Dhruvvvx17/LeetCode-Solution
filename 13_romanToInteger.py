# Leet code problem, given a roman numeral find the equivalent number

class Solution(object):
    def romanToInt(self, s):
        conversion_dict = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000} 
        
        prev = 0
        res = 0
        curr = 0
        for i in range(len(s)):
            curr = conversion_dict[s[i]]
            if(curr>prev):
                res = res + curr - 2*prev
            else:
                res = res + curr
                
            prev = curr

        return(res)

if(__name__ == "__main__"):
    obj = Solution()
    arr = ["IV","X","XV","C","CCXLV","DXII","DCCLXIX","MCCXXXIV","MMCDXCI","MMMCMXCIX"]
    for i in arr:
        print(f"{i}: ",obj.romanToInt(i))