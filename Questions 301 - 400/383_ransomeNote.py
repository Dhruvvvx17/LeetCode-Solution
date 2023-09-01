def canConstruct(ransomNote: str, magazine: str) -> bool:

    d = {}

    for ch in magazine:
        if ch not in d:
            d[ch] = 1
        else:
            d[ch] += 1

    for ch in ransomNote:
        if ch not in d or d[ch] <= 0:
            return False
        else:
            d[ch] -= 1
                
    return True

if __name__ == "__main__":
    ransomNote = input("Enter ransome note: ")
    magazine = input("Enter Magazine: ")

    if(canConstruct(ransomNote, magazine)):
        print(f"Can construct {ransomNote} from {magazine}")
    else:
        print(f"Cannot construct {ransomNote} from {magazine}")