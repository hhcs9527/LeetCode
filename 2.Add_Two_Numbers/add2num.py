# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode, c = 0) -> ListNode:
        if l1 is not None and l2 is not None:
            if (l1.val + l2.val + c) >= 10:
                ans = ListNode(l1.val + l2.val + c - 10)
                c = 1
                ans.next = self.addTwoNumbers(l1.next, l2.next, c)
            else:
                ans = ListNode(l1.val + l2.val + c)
                c = 0
                ans.next = self.addTwoNumbers(l1.next, l2.next, c)
        elif l1 is None and l2 is not None:
            if c != 0:
                if (l2.val + c >= 10):
                    ans = ListNode(l2.val + 1 - 10)
                    ans.next = self.addTwoNumbers(l1, l2.next, c)
                else:
                    ans = ListNode(l2.val + 1)
                    c = 0
                    ans.next = self.addTwoNumbers(l1, l2.next, c)
            else:
                ans = l2
                return ans
        elif l1 is not None and l2 is None:
            if c != 0:
                if (l1.val + c >= 10):
                    ans = ListNode(l1.val + 1 -10)
                    ans.next = self.addTwoNumbers(l1.next, l2, c)
                else:
                    ans = ListNode(l1.val + 1)
                    c = 0
                    ans.next = self.addTwoNumbers(l1.next, l2, c)
            else:
                ans = l1
                return ans
        elif l1 is None and l2 is None and c != 0:
            ans = ListNode(c)
            c = 0
            return ans
        else:
            return
        return ans











a = [3,7]
l1 = ListNode(a[0])
tmp = l1
for i in range(1,len(a)):
    l1.next = ListNode(a[i]) 
    l1 = l1.next
l1 = tmp


b = [9,2]
l2 = ListNode(b[0])
tmp = l2
for i in range(1,len(b)):
    l2.next = ListNode(b[i]) 
    l2 = l2.next
l2 = tmp

#while(tmp is not None):
#    print(tmp.val)
#    tmp = tmp.next
#print (tmp.val)
ans = Solution()
QQ = ans.addTwoNumbers(l1,l2, 0)
tmp = QQ
while(tmp is not None):
    print(tmp.val)
    tmp = tmp.next
#print (tmp.val)

