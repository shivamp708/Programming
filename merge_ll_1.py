#merge procedure for linked list
class Node:
    def __init__(self,d):
        self.data = d
        self.next = None
def merge(head1,head2):
    i = head1
    j = head2
    iprev = None
    jprev = None
    while i!=None and j!=None:
        if i.data<j.data:
            while(i!=None and i.data<j.data):
                iprev = i
                i = i.next
            iprev.next = j
        else:
            while(j!=None and i.data>=j.data):
                jprev = j
                j = j.next
            jprev.next = i
    head3 = None
    if head1.data<head2.data:
        head3 = head1
    else:
        head3 = head2
    return head3
def print_1(head3):
    i = head3
    while i!= None:
        print(i.data,end = " ")
        i = i.next 
head1 = Node(2)
head1.next = Node(3)
head1.next.next = Node(5)
head1.next.next.next = Node(6)
head2 = Node(1)
head2.next = Node(4)
head2.next.next = Node(7)
head3 = merge(head1,head2)
print_1(head3)
