from typing import List


def minCostClimbingStairs(cost: List[int]) -> int:

    # add a 0 to cost list - because last step is out of bounds
    cost.append(0)

    # go from right to left and calculate mincost at every step for 1-jump and 2-jump

    # total steps
    n = len(cost)

    # last step -> 0
    # second last step -> no change
    # third last step -> choice of 1 or 2 jump (start from here)

    for step in range(n-3, -1, -1):

        cost[step] += min(cost[step+1], cost[step+2])

    return min(cost[0], cost[1])


if __name__ == "__main__":

    cost = [10, 15, 1, 5, 20, 5, 4, 3, 8]
    print(
        f"Min cost to reach the end of the staircase is: {minCostClimbingStairs(cost)}")
