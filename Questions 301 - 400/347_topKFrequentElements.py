from typing import List


def topKFrequent(nums: List[int], k: int) -> List[int]:

    # creating buckets of frequency
    # so whatever occurs once will be appended to the sublist at array position 1
    # whatever occurs 5 times will be appended to the sublist at array position 5
    buckets = [[] for i in range(len(nums)+1)]

    # keeping track on visited numbers
    visited = set()

    # for every non visited element, count its occurance and append it to buckets list
    for n in nums:
        if n not in visited:
            c = nums.count(n)
            buckets[c].append(n)
            visited.add(n)

    # result - k most frequent
    res = []

    # going from most to least frequence, adding sublists to the result until the result size is k
    for i in range(len(buckets)-1, 0, -1):
        for val in buckets[i]:
            res.append(val)

            if(len(res) == k):
                return res


if __name__ == "__main__":
    nums = [1, 1, 1, 1, 2, 2, 3, 1, 2, 3, 4, 5, 4, 4, 4]
    k = 3

    res = topKFrequent(nums, k)

    print(f"{k} most frequent elements are: {res}")
