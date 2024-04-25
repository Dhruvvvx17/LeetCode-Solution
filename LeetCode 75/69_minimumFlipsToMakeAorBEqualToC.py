def minFlips(a: int, b: int, c: int) -> int:
    
    count = 0

    while(a>0 or b>0 or c>0):
        bit_a = a & 1
        bit_b = b & 1
        bit_c = c & 1

        if bit_c:
            if not (bit_a or bit_b):
                count += 1

        else:
            if bit_a and bit_b:
                count += 2
            elif bit_a or bit_b:
                count += 1

        a >>= 1
        b >>= 1
        c >>= 1

    return count

if __name__ == "__main__":

    a = 2
    b = 6
    c = 5

    print(f"Minimum flips to make a OR b = c is {minFlips(a, b, c)}")