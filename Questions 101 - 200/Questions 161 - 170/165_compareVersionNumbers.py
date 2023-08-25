# if version lengths are not equal, they are padded with zeros before comparison

def compareVersion(version1: str, version2: str) -> int:
    v1 = list(map(int, version1.split(".")))
    v2 = list(map(int, version2.split(".")))                
    
    # take larger version length for iteration
    index = len(v1) if len(v1) > len(v2) else len(v2)
    
    for i in range(index):
        
        sub_v1 = v1[i] if i < len(v1) else 0
        sub_v2 = v2[i] if i < len(v2) else 0            

        if(sub_v1 > sub_v2):
            return 1

        elif(sub_v1 < sub_v2):
            return -1
        
    return 0

if __name__ == "__main__":
    version1 = input("Enter version 1 (with sub-versions seperated with a '.'): ")
    version2 = input("Enter version 2 (with sub-versions seperated with a '.'): ")

    res = compareVersion(version1, version2)

    if(res == 1):
        print(f"Version {version1} is greater than {version2}")
    elif(res == -1):
        print(f"Version {version2} is greater than {version1}")
    else:
        print(f"Version {version1} and {version2} are the same")