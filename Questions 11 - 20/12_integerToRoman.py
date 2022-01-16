# Leet code problem, given a number find the equivalent roman numeral

class Solution(object):
    def intToRoman(self, num):
        conversion_dict = {1:'I', 5:'V', 10:'X', 50:'L', 100:'C', 500:'D', 1000:'M'}

        res = []
        n,r,base = num,0,1

        while(n>0):
            n,r = divmod(n,10)
            if(r<=3):
                res.append(conversion_dict[base]*r)
            elif(r==4):
                res.append(conversion_dict[base] + conversion_dict[base*5])
            elif(r==5):
                res.append(conversion_dict[base*5])
            elif(r>=6 and r<=8):
                res.append(conversion_dict[base*5] + conversion_dict[base]*(r%5))
            elif(r==9):
                res.append(conversion_dict[base] + conversion_dict[base*10])

            base = base*10

        return(''.join(res[::-1]))
        
if(__name__ == "__main__"):
    obj = Solution()
    arr = [4,10,15,100,245,512,769,1234,2491,3999]
    for i in arr:
        print(f"{i}: ",obj.intToRoman(i))