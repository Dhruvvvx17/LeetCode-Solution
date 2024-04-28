class Node:
    def __init__(self, value = None, next = None, prev = None):
        self.value = value
        self.next = next
        self.prev = prev


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def prepend(self, value):
        
        node = Node(value)
        self.length += 1

        if not self.head:
            self.head = node
            self.tail = node
            return
        
        node.next = self.head
        self.head.prev = node
        self.head = node
        return

    def append(self, value):

        node = Node(value)
        self.length += 1

        if not self.tail:
            self.tail = node
            self.head = node
            return
        
        node.prev = self.tail
        self.tail.next = node
        self.tail = node
        return
    
    def insertAt(self, value, index):

        if(index >= self.length):
            print("Error! Cannot insert as position is greater than current length")
            return
        
        if(index == 0):
            self.prepend(value)
            return

        if(index == self.length):
            self.append(value)
            return
        
        self.length += 1
        node = Node(value)

        curr = self.head
        for _ in range(0, index):
            curr = curr.next
        
        node.prev = curr.prev
        curr.prev.next = node

        node.next = curr        
        curr.prev = node
        return
    
    def printList(self):
        node = self.head
        print(f"List length = {self.length}\nList: ",end=" ")
        for _ in range(self.length):
            print(node.value, end=" ")
            node = node.next
        print("\n")
        return
    
    def removeAt(self, index):
        if(index >= self.length):
            print(f"Error! Cannot remove as position ({index}) is greater than current length {self.length}")
            return
        

        # single element
        if(self.length == 0):
            out = self.head.value
            self.head = None
            self.tail = None
            return out
        
        node = self.getNode(index)

        self.length -= 1
        if(node.prev):
            node.prev.next = node.next
        
        if(node.next):
            node.next.prev = node.prev
        
        if(node == self.head):
            self.head = node.next
        
        if(node == self.tail):
            self.tail = node.prev

        node.next = None
        node.prev = None
        return node.value
    

    def getNode(self, index):
        if(index >= self.length):
            print("Error! Cannot get as position is greater than current length")
            return None

        curr = self.head
        for _ in range(0, index):
            curr = curr.next
        return curr
    
    def getVal(self, index):
        resp = self.getNode(index)
        if(resp):
            return resp.value
        return "Invalid get"

    
if __name__ == "__main__":

    d = DoublyLinkedList()

    d.append(5)
    d.append(6)
    d.append(7)
    d.append(8)
    d.append(9)
    d.append(10)

    d.printList()

    d.prepend(4)
    d.prepend(3)
    d.prepend(2)
    d.prepend(1)
    d.printList()

    d.insertAt(100, 5)
    d.printList()


    print(f"Node removed: {d.removeAt(3)}")
    d.printList()

    print(f"Node removed: {d.removeAt(5)}")
    d.printList()

    print(f"Node removed: {d.removeAt(7)}")
    d.printList()

    print(f"Node removed: {d.removeAt(0)}")
    d.printList()


    print(d.head.value)
    print(d.tail.value)

    print(f"Node removed: {d.removeAt(6)}")
    d.printList()

    print(d.head.value)
    print(d.tail.value)

    print(f"Node removed: {d.removeAt(0)}")
    print(f"Node removed: {d.removeAt(0)}")
    print(f"Node removed: {d.removeAt(0)}")
    print(f"Node removed: {d.removeAt(0)}")
    print(f"Node removed: {d.removeAt(0)}")
    print(f"Node removed: {d.removeAt(0)}")
    print(f"Node removed: {d.removeAt(0)}")

