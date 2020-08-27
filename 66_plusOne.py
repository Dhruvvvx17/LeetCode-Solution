def plusOne(digits):
        
        carry = 0
        last_num = digits[-1]
        last_num += 1
        if last_num > 9:
            digits[-1] = last_num %10
            carry = last_num//10
        else:
            digits[-1] = last_num
            return digits

        
        for i in range(len(digits)-2,-1,-1):
            if carry==0:
                break
            num = digits[i] + carry
            digits[i] = num%10
            carry = num//10
        
        if(carry>0):
            digits.insert(0,carry)
        
        return digits

if __name__ == "__main__":
    print("Enter array numbers: ",end="")
    arr = list(map(int,input().split()))

    print(f"New list after adding 1 to the input list = {plusOne(arr)}")