class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverseList(head):

    # zero of one nodes
    if(head == None or head.next == None):
        return head

    # two nodes
    if(head.next.next == None):
        head.next.next = head
        head = head.next
        head.next.next = None
        return head

    # three nodes
    p = head
    q = head.next
    r = head.next.next

    # update the first node (which will now point to last)
    p.next = None

    while(r != None):
        q.next = p
        p = q
        q = r
        r = r.next

    # update last node
    q.next = p

    # update head
    head = q

    # return result
    return head


if __name__ == "__main__":

    head = ListNode(5)
    head.next = ListNode(10)
    head.next.next = ListNode(15)
    head.next.next.next = ListNode(20)
    head.next.next.next.next = ListNode(25)

    p = head
    print("Original list: ", end=" ")
    while(p != None):
        print(p.val, end=" ")
        p = p.next

    q = reverseList(head)

    print("\nReversed list: ", end=" ")
    while(q != None):
        print(q.val, end=" ")
        q = q.next
