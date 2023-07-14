From an interview perspective, using deque from the collections module would be a better choice
for implementing stacks and queues in Python. Here's why:

Efficiency: deque is specifically designed to provide efficient operations for adding and removing elements
            at both ends. It offers constant-time complexity (O(1)) for these operations, making it well-suited
            for implementing stacks and queues that require frequent push and pop operations.
            On the other hand, adding or removing elements from the front of a list has a
            time complexity of O(n) since it requires shifting all subsequent elements.

Performance: deque is optimized for high-performance insertion and deletion at both ends.
             It uses a doubly-linked list internally, which allows for efficient memory allocation
             and element management. This makes it a more efficient choice for implementing stacks and queues.

Consistency and Familiarity: Using deque from the collections module is a standardized approach,
                             and interviewers are generally familiar with its usage.
                             It demonstrates your knowledge of Python's standard library and your ability
                             to leverage built-in data structures effectively.

API Compatibility: Both list and deque provide similar APIs, so you can perform common stack and queue
                   operations using either data structure. This means you can easily switch between list and
                   deque based on the requirements of the interview question without significant changes to
                   your code.


Stack:

append(item): Adds an item to the top of the stack (push operation).
pop(): Removes and returns the item from the top of the stack (pop operation).
peek(): Returns the item at the top of the stack without removing it (top operation).
is_empty(): Checks if the stack is empty.
size(): Returns the number of elements in the stack.

Time Complexity: O(1) Space Complexity: O(1)

Queue:

append(item): Adds an item to the rear of the queue (enqueue operation).
popleft(): Removes and returns the item from the front of the queue (dequeue operation).
peek(): Returns the item at the front of the queue without removing it (front operation).
is_empty(): Checks if the queue is empty.
size(): Returns the number of elements in the queue.

Time Complexity: O(1) Space Complexity: O(1)

Stack implementation:

from collections import deque

class Stack:
    def __init__(self):
        self.stack = deque()

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            raise IndexError("Stack is empty")

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else:
            raise IndexError("Stack is empty")

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)

Queue implementation:

from collections import deque

class Queue:
    def __init__(self):
        self.queue = deque()

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.queue.popleft()
        else:
            raise IndexError("Queue is empty")

    def peek(self):
        if not self.is_empty():
            return self.queue[0]
        else:
            raise IndexError("Queue is empty")

    def is_empty(self):
        return len(self.queue) == 0

    def size(self):
        return len(self.queue)
