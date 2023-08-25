# Time complexity O(n)
# Space complexity O(n) -> n indices * 2 decisions for each

def maxProfit(prices):

    dp = {}
    res = DFS(prices, 0, True, dp)
    # print(dp)
    return res

# recursively find the best solution for each index


def DFS(prices, index, buying, dp):

    # no profit
    if (index >= len(prices)):
        return 0

    # check if result was computed
    if((index, buying) in dp):
        return dp[(index, buying)]

    # if buying is set to true
    if buying:

        # what could be the profit if I buy my stock
        buy_profit = DFS(prices, index+1, not buying, dp) - prices[index]

        # what could be the profit if I wait and cooldown - no state change
        cooldown_profit = DFS(prices, index+1, buying, dp)

        res = max(buy_profit, cooldown_profit)

        # store result in dp
        dp[(index, buying)] = res

    # If selling is set to true
    else:

        # what could be the profit if I sell my stock (forces cooldown)
        sell_profit = DFS(prices, index+2, not buying, dp) + prices[index]

        # what could be the profit if I wait and cooldown - no state change
        cooldown_profit = DFS(prices, index+1, buying, dp)

        res = max(sell_profit, cooldown_profit)

        # store result in dp
        dp[(index, buying)] = res

    return dp[(index, buying)]


if __name__ == "__main__":
    stock_prices = [5, 1, 2, 3, 0, 2]
    print(f"Max profit possible: {maxProfit(stock_prices)}")
