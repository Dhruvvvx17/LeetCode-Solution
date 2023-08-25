# Approach works only if the strings can be arranged lexographically

def longestCommonPrefix(strs):
    
    if(len(strs)==0):
        return ""

    if(len(strs)==1):
        return strs[0]
    
    # Sort lexographically
    strs.sort()
    
    # Compare between first and last strings
    first = strs[0]
    last = strs[-1]
    
    i = 0
    while(i<len(first) and i<len(last) and first[i]==last[i]):
        i += 1
    
    return first[:i]

if __name__ == "__main__":

    strs = ["flower","flow","flight"]
    print("Given list of sequences",strs)
    print(f"longest common subsequence = {longestCommonPrefix(strs)}")