class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        arr1 = []
        arr2 = []
        
        while l1:
            arr1.append(l1.val)
            l1 = l1.next

        while l2:
            arr2.append(l2.val)
            l2 = l2.next
                
        len1 = len(arr1)
        len2 = len(arr2)
        i = 0
        j = 0
        carry = 0
        res_list = []
        
        while len1 or len2 or carry:
            val = 0
            if len1:
                val += arr1[i]
                i += 1
                len1 -= 1

            if len2:
                val += arr2[j]
                j += 1
                len2 -= 1

            res_value = (val + carry)%10
            carry = (val+carry)//10
            
            res_list.append(res_value)

        # Create the final answer linked list
        res_final = ListNode(res_list[0])    #Root node value is list[0]
        res_ptr = res_final
                
        for val in res_list[1:]:            #Rest of the list is iterated and added to nodes
            res_ptr.next = ListNode(val)
            res_ptr = res_ptr.next


        return res_final