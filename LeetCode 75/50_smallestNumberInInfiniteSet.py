class SmallestInfiniteSet:

    def __init__(self):
        self.s = set()
        self.curr = 1

    def popSmallest(self) -> int:
        if len(self.s) > 0:
            ele = min(self.s)
            self.s.remove(ele)
        else:
            ele = self.curr
            self.curr += 1
        return ele
            

    def addBack(self, num: int) -> None:
        if num < self.curr:
            self.s.add(num)

if __name__ == "__main__":

    obj = SmallestInfiniteSet()
    
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())

    obj.addBack(2)
    obj.addBack(4)

    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
