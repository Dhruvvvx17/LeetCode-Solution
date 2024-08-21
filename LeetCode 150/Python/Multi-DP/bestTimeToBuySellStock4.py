def maxProfit(prices, k) -> int:
    n = len(prices)
    dp = {}
    # key -> txnRemaining_action_index
    # txnRemaining = k
    # action = buy/sell/skip
    # index = 0 to n

    def helper(profit, index, can_buy, k) -> int:
        # base case
        if index >= n or k <= 0:
            return 0

        key = f"{k}_{can_buy}_{index}"
        if key in dp:
            return dp[key]
        
        if can_buy:
            dp[key] = max(helper(profit, index+1, not can_buy, k) - prices[index], helper(profit, index+1, can_buy, k))
        else:
            dp[key] = max(helper(profit, index+1, not can_buy, k-1) + prices[index], helper(profit, index+1, can_buy,k))
        
        return dp[key]

    return helper(0, 0, True, k)

if __name__ == "__main__":
    prices = [3,3,5,0,0,3,1,4,5,2,8,3]
    k = 3

    print(f"Max profit gained from prices after {k} transactions = {maxProfit(prices, k)}")