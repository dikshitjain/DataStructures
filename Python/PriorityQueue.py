The following functions are provided:

heapq.heappush(heap, item)
Push the value item onto the heap, maintaining the heap invariant.

heapq.heappop(heap)
Pop and return the smallest item from the heap, maintaining the heap invariant.
If the heap is empty, IndexError is raised. To access the smallest item without popping it, use heap[0].

heapq.heappushpop(heap, item)
Push item on the heap, then pop and return the smallest item from the heap.
The combined action runs more efficiently than heappush() followed by a separate call to heappop().

heapq.heapify(x)
Transform list x into a heap, in-place, in linear time.

heapq.heapreplace(heap, item)
Pop and return the smallest item from the heap, and also push the new item.
The heap size doesn’t change. If the heap is empty, IndexError is raised.

This one step operation is more efficient than a heappop() followed by heappush() and can be more
appropriate when using a fixed-size heap. The pop/push combination always returns an element from
the heap and replaces it with item.

The value returned may be larger than the item added. If that isn’t desired, consider using
heappushpop() instead. Its push/pop combination returns the smaller of the two values, leaving the
larger value on the heap.

The module also offers three general purpose functions based on heaps.

heapq.merge(*iterables, key=None, reverse=False)
Merge multiple sorted inputs into a single sorted output (for example, merge timestamped entries
from multiple log files). Returns an iterator over the sorted values.

Similar to sorted(itertools.chain(*iterables)) but returns an iterable, does not pull the data into
memory all at once, and assumes that each of the input streams is already sorted (smallest to largest).

Has two optional arguments which must be specified as keyword arguments.

key specifies a key function of one argument that is used to extract a comparison key from each
input element. The default value is None (compare the elements directly).

reverse is a boolean value. If set to True, then the input elements are merged as if each
comparison were reversed. To achieve behavior similar to
sorted(itertools.chain(*iterables), reverse=True), all iterables must be sorted from largest to smallest.

Changed in version 3.5: Added the optional key and reverse parameters.

heapq.nlargest(n, iterable, key=None)
Return a list with the n largest elements from the dataset defined by iterable. key, if provided,
specifies a function of one argument that is used to extract a comparison key from each element in
iterable (for example, key=str.lower). Equivalent to: sorted(iterable, key=key, reverse=True)[:n].

heapq.nsmallest(n, iterable, key=None)
Return a list with the n smallest elements from the dataset defined by iterable. key, if provided,
specifies a function of one argument that is used to extract a comparison key from each element in
iterable (for example, key=str.lower). Equivalent to: sorted(iterable, key=key)[:n].

Implementation of Heap:

class Heap:
    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i - 1) // 2

    def left_child(self, i):
        return 2 * i + 1

    def right_child(self, i):
        return 2 * i + 2

    def insert(self, item):
        self.heap.append(item)
        self.heapify_up(len(self.heap) - 1)

    def extract_min(self):
        if self.is_empty():
            return None
        min_item = self.heap[0]
        last_item = self.heap.pop()
        if not self.is_empty():
            self.heap[0] = last_item
            self.heapify_down(0)
        return min_item

    def is_empty(self):
        return len(self.heap) == 0

    def heapify_up(self, i):
        while i > 0 and self.heap[i] < self.heap[self.parent(i)]:
            self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]
            i = self.parent(i)

    def heapify_down(self, i):
        smallest = i
        left = self.left_child(i)
        right = self.right_child(i)
        if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
            smallest = left
        if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
            smallest = right
        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self.heapify_down(smallest)

MinHeap:

    import heapq

    # Create an empty list to serve as the min heap
    min_heap = []

    # Insert elements into the min heap
    heapq.heappush(min_heap, 5)
    heapq.heappush(min_heap, 2)
    heapq.heappush(min_heap, 10)
    heapq.heappush(min_heap, 1)

    # Print and remove elements from the min heap
    while min_heap:
        print(heapq.heappop(min_heap), end=" ")

MaxHeap:

Approach 1:

    import heapq

    # Create an empty list to serve as the max heap
    max_heap = []

    # Insert elements into the max heap
    heapq.heappush(max_heap, -5)
    heapq.heappush(max_heap, -2)
    heapq.heappush(max_heap, -10)
    heapq.heappush(max_heap, -1)

    # Print and remove elements from the max heap
    while max_heap:
        print(-heapq.heappop(max_heap), end=" ")

Approach 2:

    import heapq

    class MaxHeapWrapper:
        def __init__(self, value):
            self.value = value

        def __lt__(self, other):
            return other.value < self.value

    # Example list of integers
    numbers = [5, 2, 10, 1]

    # Create an empty list to serve as the max heap
    max_heap = []

    # Wrap the numbers using the MaxHeapWrapper class and insert them into the max heap
    for number in numbers:
        heapq.heappush(max_heap, MaxHeapWrapper(number))

    # Print and remove elements from the max heap
    while max_heap:
        number = heapq.heappop(max_heap).value
        print(number, end=" ")



Lexicographically increasing string:

    import heapq

    # Example list of strings
    strings = ["apple", "banana", "orange", "grape"]

    # Create a min heap
    min_heap = []
    for string in strings:
        heapq.heappush(min_heap, string)

    # Pop elements from the min heap
    while min_heap:
        string = heapq.heappop(min_heap)
        print(string)


Lexicographically decreasing string:

    import heapq

    # Example list of strings
    strings = ["apple", "banana", "orange", "grape"]

    # Custom key function for max heap
    def max_heap_key(string):
        return tuple(-ord(char) for char in string)

    # Create a max heap using the custom key function
    max_heap = []
    for string in strings:
        heapq.heappush(max_heap, (max_heap_key(string), string))

    # Pop elements from the max heap
    while max_heap:
        string = heapq.heappop(max_heap)[1]
        print(string, end=" ")

Custom class comparator:

    import heapq

    class CustomObject:
        def __init__(self, value):
            self.value = value

    # Custom wrapper class for max heap behavior
    class MaxHeapWrapper:
        def __init__(self, custom_obj):
            self.custom_obj = custom_obj

        def __lt__(self, other):
            return other.custom_obj.value < self.custom_obj.value

    # Example list of custom class objects
    custom_objects = [CustomObject(5), CustomObject(2), CustomObject(10), CustomObject(1)]

    # Create an empty list to serve as the max heap
    max_heap = []

    # Wrap the custom objects using the MaxHeapWrapper class and insert them into the max heap
    for obj in custom_objects:
        heapq.heappush(max_heap, MaxHeapWrapper(obj))

    # Print and remove elements from the max heap
    while max_heap:
        obj = heapq.heappop(max_heap).custom_obj
        print(obj.value, end=" ")

Priority based on second element of list:

    import heapq

    # Example list of lists
    elements = [[3, 'apple'], [1, 'banana'], [2, 'orange'], [4, 'grape']]

    # Custom comparison function for priority queue
    def priority_compare(element):
        return element[1]

    # Create an empty list to serve as the priority queue
    priority_queue = []

    # Insert elements into the priority queue using the custom comparison function
    for element in elements:
        heapq.heappush(priority_queue, (priority_compare(element), element))

    # Pop elements from the priority queue based on the priority
    while priority_queue:
        _, element = heapq.heappop(priority_queue)
        print(element, end=" ")
