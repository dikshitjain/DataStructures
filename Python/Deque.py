append(item): Adds an item to the right end of the deque.
Time complexity: Amortized O(1) (constant time on average). Space complexity: O(1).

appendleft(item): Adds an item to the left end of the deque.
Time complexity: Amortized O(1) (constant time on average). Space complexity: O(1).

pop(): Removes and returns the rightmost item from the deque.
Time complexity: O(1). Space complexity: O(1).

popleft(): Removes and returns the leftmost item from the deque.
Time complexity: O(1). Space complexity: O(1).

extend(iterable): Extends the deque by appending elements from the iterable to the right end.
Time complexity: O(k), where k is the length of the iterable. Space complexity: O(k).

extendleft(iterable): Extends the deque by appending elements from the iterable to the left end.
Time complexity: O(k), where k is the length of the iterable. Space complexity: O(k).

rotate(k): Rotates the deque k steps to the right if k is positive, or to the left if k is negative.
Time complexity: O(k), where k is the number of steps to rotate. Space complexity: O(1).

clear(): Removes all elements from the deque, leaving it empty.
Time complexity: O(1). Space complexity: O(1).

count(item): Returns the number of occurrences of the item in the deque.
Time complexity: O(n), where n is the number of elements in the deque. Space complexity: O(1).

index(item, start, end): Returns the index of the first occurrence of the item in the deque between the start and end indices.
Time complexity: O(n), where n is the number of elements in the deque. Space complexity: O(1).

remove(item): Removes the first occurrence of the item from the deque.
Time complexity: O(n), where n is the number of elements in the deque. Space complexity: O(1).

Deque implementation using list:

class Deque:
    def __init__(self):
        self.data = []

    def append(self, item):
        self.data.append(item)

    def appendleft(self, item):
        self.data.insert(0, item)

    def pop(self):
        if not self.is_empty():
            return self.data.pop()
        else:
            raise IndexError("Deque is empty")

    def popleft(self):
        if not self.is_empty():
            return self.data.pop(0)
        else:
            raise IndexError("Deque is empty")

    def extend(self, iterable):
        self.data.extend(iterable)

    def extendleft(self, iterable):
        for item in iterable:
            self.appendleft(item)

    def rotate(self, k):
        self.data = self.data[-k:] + self.data[:-k]

    def clear(self):
        self.data.clear()

    def count(self, item):
        return self.data.count(item)

    def index(self, item, start=None, end=None):
        return self.data.index(item, start, end)

    def remove(self, item):
        self.data.remove(item)

    def is_empty(self):
        return len(self.data) == 0

    def size(self):
        return len(self.data)

Dynamic size: Doubly linked lists allow for efficient resizing and dynamic memory allocation as
elements are added or removed from the deque.

Constant-time insertion and removal: Insertion and removal operations at both ends of a
doubly linked list can be performed in constant time, while arrays/vectors require shifting/moving
elements.

Efficient element removal: Removing elements from a doubly linked list requires updating neighboring
pointers, resulting in more efficient removal compared to arrays/vectors.

Easy reordering of elements: Doubly linked lists allow for easy reordering of elements by changing
pointers, making them useful in scenarios requiring frequent element rearrangement.

Reduced memory overhead: Doubly linked lists offer more efficient memory utilization as they don't
require upfront allocation of a fixed-size buffer like arrays/vectors.

Implementation using Doubly Linked List:

class Node:
    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None

class Deque:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def append(self, item):
        new_node = Node(item)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def appendleft(self, item):
        new_node = Node(item)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise IndexError("Deque is empty")
        item = self.tail.value
        if self.size == 1:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1
        return item

    def popleft(self):
        if self.is_empty():
            raise IndexError("Deque is empty")
        item = self.head.value
        if self.size == 1:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
        return item

    def is_empty(self):
        return self.size == 0

    def get_size(self):
        return self.size
