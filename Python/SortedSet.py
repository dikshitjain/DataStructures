https://grantjenks.com/docs/sortedcontainers/sortedset.html

Sorted set is a sorted mutable set.

Sorted set values are maintained in sorted order.
The design of sorted set is simple: sorted set uses a set for set-operations
and maintains a sorted list of values.

Sorted set values must be hashable and comparable.
The hash and total ordering of values must not change while they are stored in the sorted set.

sortedcontainers is a popular third-party library that provides SortedDict and SortedSet classes,
which are implementations of ordered map and ordered set, respectively.
These classes internally use a combination of a binary search tree (AVL tree)
and an underlying list to maintain the ordered elements.

add(value): Inserts a value into the sorted set.

Time complexity: O(log n)
Space complexity: O(n)
remove(value): Removes a value from the sorted set.

Time complexity: O(log n)
Space complexity: O(n)
discard(value): Removes a value from the sorted set if it exists.

Time complexity: O(log n)
Space complexity: O(n)
clear(): Removes all elements from the sorted set.

Time complexity: O(1)
Space complexity: O(n)
__contains__(value): Checks if a value is present in the sorted set.

Time complexity: O(log n)
Space complexity: O(n)
__iter__(): Returns an iterator over the elements in ascending order.

Time complexity: O(n)
Space complexity: O(n)
__reversed__(): Returns an iterator over the elements in descending order.

Time complexity: O(n)
Space complexity: O(n)
__getitem__(index): Accesses the element at the specified index.

Time complexity: O(1)
Space complexity: O(1)
__len__(): Returns the number of elements in the sorted set.

Time complexity: O(1)
Space complexity: O(1)
__repr__(): Returns a string representation of the sorted set.

Time complexity: O(n)
Space complexity: O(n)
copy(): Creates a shallow copy of the sorted set.
Time complexity: O(n)
Space complexity: O(n)

Example:

    from sortedcontainers import SortedSet

    # Create an ordered set
    ordered_set = SortedSet([3, 1, 4, 1, 5, 9, 2, 6, 5])

    # Perform operations on the ordered set
    print(ordered_set)  # Output: SortedSet([1, 2, 3, 4, 5, 6, 9])

    ordered_set.add(7)
    print(ordered_set)  # Output: SortedSet([1, 2, 3, 4, 5, 6, 7, 9])

    ordered_set.remove(4)
    print(ordered_set)  # Output: SortedSet([1, 2, 3, 5, 6, 7, 9])

    print(ordered_set[2])  # Output: 3

    print(len(ordered_set))  # Output: 7

    print(2 in ordered_set)  # Output: True

Custom Class:

The SortedSet class from the sortedcontainers library in Python does not have built-in methods for
finding the upper bound and lower bound values directly.
However, you can use the bisect_left and bisect_right functions from the bisect module to achieve
similar functionality.

from sortedcontainers import SortedSet

    class Person:
        def __init__(self, name, age):
            self.name = name
            self.age = age

        def __repr__(self):
            return f"Person(name='{self.name}', age={self.age})"

        def __lt__(self, other):
            return self.age < other.age

    # Create a SortedSet of Person objects
    people = SortedSet()

    # Add Person objects to the SortedSet
    people.add(Person("Alice", 25))
    people.add(Person("Bob", 30))
    people.add(Person("Charlie", 20))
    people.add(Person("David", 35))

    # Print the SortedSet
    print(people)
    # Output: SortedSet([Person(name='Charlie', age=20), Person(name='Alice', age=25),
    #                   Person(name='Bob', age=30), Person(name='David', age=35)])

Lower Bound and Upper Bound:

The SortedSet class from the sortedcontainers library in Python does not have built-in methods
for finding the upper bound and lower bound values directly. However, you can use the
bisect_left and bisect_right functions from the bisect module to achieve similar functionality.

from sortedcontainers import SortedSet
import bisect

# Create a SortedSet
sorted_set = SortedSet([1, 3, 5, 7, 9])

# Find the lower bound value
lower_bound_index = bisect.bisect_left(sorted_set, 4)
lower_bound_value = sorted_set[lower_bound_index] if lower_bound_index < len(sorted_set) else None
print("Lower Bound:", lower_bound_value)
# Output: Lower Bound: 5

# Find the upper bound value
upper_bound_index = bisect.bisect_right(sorted_set, 4)
upper_bound_value = sorted_set[upper_bound_index] if upper_bound_index < len(sorted_set) else None
print("Upper Bound:", upper_bound_value)
# Output: Upper Bound: 5
