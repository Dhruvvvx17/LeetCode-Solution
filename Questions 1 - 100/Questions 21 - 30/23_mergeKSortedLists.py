'''
Complexity:
    Time: O(NlogN) -> O(N) to get all value + O(NlogN) to sort + O(N) to create new LinkedList
    Space: O(N) to store all values in a list before sorting.
'''


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeKLists(lists) -> ListNode:
    
    # Solution to get all node values and store in a list
    values = []
    for li in lists:
        p = li
        while(p):
            values.append(p.val)
            p = p.next
            
    print(values)
    newList = ListNode(0)
    p = newList
    
    # Sort the values and insert in new list
    for val in sorted(values):
        p.next = ListNode(val)
        p = p.next
        
    return(newList.next)

if __name__ == "__main__":
    # create k lists 
    # send the list of lists to the function
    l1 = ListNode(0)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(1)
    l2.next.next = ListNode(2)

    l3 = ListNode(8)
    l3.next = ListNode(7)
    l3.next.next = ListNode(6)

    lists = [l1,l2,l3]

    print(f"Original k lists = {lists}")
    print(f"Sorted list = {mergeKLists([l1,l2,l3])}")

