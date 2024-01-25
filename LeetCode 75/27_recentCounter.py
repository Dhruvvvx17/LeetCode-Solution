from collections import deque

class RecentCounter:

    def __init__(self):
        self.queue = deque([])

    def ping(self, t: int) -> int:
        self.queue.append(t)

        while(self.queue[0] < t - 3000):
            self.queue.popleft()

        return len(self.queue)

if __name__ == "__main__":

    obj1 = RecentCounter()
    print(obj1.ping(1))
    print(obj1.ping(100))
    print(obj1.ping(3001))
    print(obj1.ping(3002))
    print(obj1.ping(3003))
    print(obj1.ping(3100))
    print(obj1.ping(3110))
    print(obj1.ping(8000))