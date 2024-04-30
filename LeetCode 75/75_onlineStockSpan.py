class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        res = 1
        while len(self.stack) and self.stack[-1][0] <= price:
            res += self.stack[-1][1]
            self.stack.pop(-1)
        
        self.stack.append([price, res])
        return res
            

if __name__ == "__main__":

    spanner = StockSpanner()
    print(spanner.next(100))
    print(spanner.next(80))
    print(spanner.next(60))
    print(spanner.next(70))
    print(spanner.next(60))
    print(spanner.next(75))
    print(spanner.next(85))