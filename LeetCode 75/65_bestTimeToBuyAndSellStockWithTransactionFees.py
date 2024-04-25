def maxProfit(prices, fee):
    n = len(prices)

    # the values represent net profit at index i based on action
    buy = [0]*n
    sell = [0]*n

    # first buy
    buy[0] = -prices[0]
    sell[0] = 0

    # at every step a decision can be made to buy/sell
    # each decision depends on the previous sell/buy transaction
    for i in range(1, n):

        buy[i] = max(buy[i-1], sell[i-1] - prices[i])
        sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee)

    return sell[n-1]

if __name__ == "__main__":

    prices = [1,3,2,8,4,9]
    fee = 2

    print(f"Max profit = {maxProfit(prices, fee)}")