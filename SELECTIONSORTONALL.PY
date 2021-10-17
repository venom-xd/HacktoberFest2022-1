class Node:
    
    def __init__(self, data):
        self.data = data
        self.next = None

def selectionSort(head):
    temp = head
    while (temp is not None):
        minn = temp
        r = temp.next
        while (r is not None):
            if (minn.data > r.data):
                minn = r
            r = r.next
        x = temp.data
        temp.data = minn.data
        minn.data = x
        temp = temp.next
    return head

def printLL(head):
    while head is not None:
        print(head.data,end="-->")
        head = head.next
    print('None')
    return

def takeInput():
    arr = list(int(ele) for ele in input().split())
    head = None
    tail = None
    for currData in arr:
        if currData == -1:
            break
        newNode = Node(currData)        
        if head is None:
            head = newNode
            tail = newNode
        else: 
            tail.next = newNode
            tail = newNode                
    return head

head = takeInput() 
head = selectionSort(head)
printLL(head)