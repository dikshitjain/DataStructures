Implementation of Deque

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_front(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def insert_back(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node

    def remove_front(self):
        if self.is_empty():
            print("List is empty")
            return
        temp = self.head
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        del temp

    def remove_back(self):
        if self.is_empty():
            print("List is empty")
            return
        temp = self.tail
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        del temp

    def print_list(self):
        current = self.head
        while current is not None:
            print(current.data, end=" ")
            current = current.next
        print()

    def is_empty(self):
        return self.head is None

    def clear(self):
        current = self.head
        while current is not None:
            temp = current
            current = current.next
            del temp
        self.head = None
        self.tail = None


DoublyLinkedList vs Deque

A doubly linked list and a deque (double-ended queue) are two different data structures, but they share some similarities.
Here are the key differences between a doubly linked list and a deque:

Structure and Access:

Doubly Linked List: A doubly linked list is a linear data structure where each node contains a value and two pointers:
one pointing to the previous node and another pointing to the next node. It allows traversal in both directions
(forward and backward) and provides efficient insertion and deletion operations at any position within the list.
Deque: A deque, on the other hand, is a generalized queue that allows insertion and deletion at both ends (front and rear).
It does not support random access or direct traversal to a specific position within the deque like a linked list does.
Operations:

Doubly Linked List: A doubly linked list supports various operations such as insertion and deletion at the front, rear,
or any arbitrary position. It also allows traversal in both directions.
Deque: A deque supports operations like push (insertion) and pop (deletion) at both ends. It offers constant-time
complexity (O(1)) for these operations, making it efficient for scenarios where elements need to be added or removed
from both ends.

Flexibility:

Doubly Linked List: A doubly linked list is more flexible and can handle operations like insertion and deletion at any position
within the list. It is suitable when you need to frequently modify the structure by adding or removing elements from arbitrary
positions.
Deque: A deque is more focused on providing efficient insertion and deletion at both ends. It is particularly useful when you
need to implement data structures like stacks or queues where elements are inserted and removed from the front or rear.

Memory Overhead:

Doubly Linked List: A doubly linked list has a higher memory overhead compared to a deque because each node needs to store
two additional pointers (previous and next).
Deque: A deque has a lower memory overhead compared to a doubly linked list because it does not require storing additional
pointers for traversal.
In summary, a doubly linked list is a linear data structure that allows insertion and deletion at any position with bidirectional
traversal, while a deque is a generalized queue that supports insertion and deletion at both ends with efficient constant-time
operations. The choice between the two depends on the specific requirements of your use case, such as the need for random access,
flexibility in modifying the structure, and the performance characteristics required for specific operations.
