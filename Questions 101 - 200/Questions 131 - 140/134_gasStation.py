from typing import List

def canCompleteCircuit(gas: List[int], cost: List[int]) -> int:

    if sum(gas) < sum(cost):
        return -1

    total = 0
    start = 0

    for i in range(len(gas)):
        total += (gas[i] - cost[i])

        if total < 0:
            total = 0
            start = i + 1

    return start


if __name__ == "__main__":
    gas = [1,2,3,4,5]
    cost = [3,4,5,1,2]

    print(f"Valid starting position without running out of gas: {canCompleteCircuit(gas, cost)}")