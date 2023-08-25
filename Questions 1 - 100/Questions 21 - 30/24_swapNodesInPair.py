# Using 3 pointer approach, switching the adjacent pointer in every iteration

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swapPairs(head: ListNode) -> ListNode:        
    temp = prev = ListNode(0)
    temp.next = head
    
    while(prev.next and prev.next.next):
        a = prev.next
        b = prev.next.next
        c = prev.next.next.next
        
        prev.next = b
        prev.next.next = a
        prev.next.next.next = c
        
        prev = prev.next.next
        
    return temp.next

if __name__ == "__main__":

    myList = ListNode(1)
    myList.next = ListNode(2)
    myList.next.next = ListNode(3)
    myList.next.next.next = ListNode(4)

    print("Original list: ",end="")
    p = myList
    while(p):
        print(p.val,end=" ")
        p = p.next
    print("\n")

    print("After swapping adjacent nodes: ",end="")
    p = swapPairs(myList)
    while(p):
        print(p.val,end=" ")
        p = p.next
    print("\n")
    