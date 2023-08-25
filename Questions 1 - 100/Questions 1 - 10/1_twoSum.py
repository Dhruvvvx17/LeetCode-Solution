# Given a list of numbers, find the number or pairs that add up to the given sum k.
# A number cannot be used more than once.
# O(n) 1 pass solution
print("Enter array size: ",end="")
n = int(input())

print("Enter array elements space separated: ",end="")
arr = list(map(int, input().split()))

print("Enter K value: ",end="")
K = int(input())

d = {}
pair_count = 0
pairs = []

for i in range(len(arr)):
    if(K-arr[i] in d):
        pair_count += 1
        pairs.append([d[K-arr[i]],i])
    else:
        d[arr[i]] = i

print(f"Number of pairs that add up to {K} = {pair_count}")
print("List of pairs (values represent indices in original array) = ", pairs)