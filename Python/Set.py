Adding an element to a set:

set.add(element) - Adds the specified element to the set.
Time complexity: O(1)
Space complexity: O(1)
Removing an element from a set:

set.remove(element) - Removes the specified element from the set.
                      Raises a KeyError if the element is not found.
set.discard(element) - Removes the specified element from the set if it exists,
                       without raising an exception.
Time complexity: O(1)
Space complexity: O(1)

Checking if an element exists in a set:

element in set - Returns True if the element exists in the set, False otherwise.
Time complexity: O(1)
Space complexity: O(1)

Clearing a set:

set.clear() - Removes all elements from the set, making it empty.
Time complexity: O(1)
Space complexity: O(1)

Getting the size of a set:

len(set) - Returns the number of elements in the set.
Time complexity: O(1)
Space complexity: O(1)
Iterating over a set:

for element in set: - Iterates over each element in the set in an arbitrary order.
Time complexity: O(n), where n is the number of elements in the set.
Space complexity: O(1)

Union of sets:

set.union(*other_sets) - Returns a new set that is the union of the current set and the other sets.
set | other_set - Alternative syntax using the pipe operator.

Time complexity: O(n), where n is the total number of elements in all the sets being combined.
Space complexity: O(n), where n is the total number of elements in all the sets being combined.

Intersection of sets:

set.intersection(*other_sets) - Returns a new set that is the intersection of the current set
                                and the other sets.
set & other_set - Alternative syntax using the ampersand operator.
Time complexity: O(min(n, m)), where n is the number of elements in the current set
                 and m is the number of elements in the smallest set being intersected.
Space complexity: O(min(n, m)), where n is the number of elements in the current set
                  and m is the number of elements in the smallest set being intersected.

Difference between sets:

set.difference(*other_sets) - Returns a new set that contains the elements present in the current set but
                              not in the other sets.
set - other_set - Alternative syntax using the minus operator.
Time complexity: O(n), where n is the number of elements in the current set.
Space complexity: O(n), where n is the number of elements in the current set.

Symmetric difference between sets:

set.symmetric_difference(other_set) - Returns a new set that contains the elements present in either
                                      the current set or the other set, but not in both.
set ^ other_set - Alternative syntax using the caret operator.
Time complexity: O(n), where n is the total number of elements in both sets being compared.
Space complexity: O(n), where n is the total number of elements in both sets being compared.


Custom class:

    class Person:
        def __init__(self, name, age):
            self.name = name
            self.age = age

        def __str__(self):
            return f"{self.name} (Age: {self.age})"

        def __hash__(self):
            return hash((self.name, self.age))

        def __eq__(self, other):
            return isinstance(other, Person) and self.name == other.name and self.age == other.age


    # Create some instances of the Person class
    person1 = Person("John", 30)
    person2 = Person("Alice", 25)
    person3 = Person("Bob", 35)

    # Create an empty set to store Person objects
    person_set = set()

    # Add Person objects to the set
    person_set.add(person1)
    person_set.add(person2)
    person_set.add(person3)

    # Print the set
    for person in person_set:
        print(person)

Multiset (Repetitive keys):

Counter(iterable): Constructs a Counter object from an iterable.
Time complexity: O(n), Space complexity: O(k).

elements(): Returns an iterator over the elements.
Time complexity: O(n), Space complexity: O(1).

most_common([n]): Returns the n most common elements and counts.
Time complexity: O(n log k), Space complexity: O(k).

subtract(iterable): Decrements counts based on the iterable.
Time complexity: O(m), Space complexity: O(k).

update(iterable): Updates counts based on the iterable.
Time complexity: O(m), Space complexity: O(k).

get(key, default=0): Returns the count of a key.
 Time complexity: O(1), Space complexity: O(1).

keys(): Returns a list of unique elements.
Time complexity: O(k), Space complexity: O(k).

values(): Returns a list of counts.
Time complexity: O(k), Space complexity: O(k).

items(): Returns a list of element-count pairs.
Time complexity: O(k), Space complexity: O(k).

clear(): Removes all elements.
Time complexity: O(1), Space complexity: O(1).


from collections import Counter

# Create a Counter object
counter = Counter(['apple', 'banana', 'apple', 'orange', 'banana'])

# Count the occurrences of elements
print(counter)  # Output: Counter({'apple': 2, 'banana': 2, 'orange': 1})

# Get the most common elements
print(counter.most_common(2))  # Output: [('apple', 2), ('banana', 2)]

# Subtract counts from another iterable
counter.subtract(['apple', 'banana'])
print(counter)  # Output: Counter({'orange': 1, 'apple': 1, 'banana': 1})

# Update counts with another iterable
counter.update(['apple', 'banana', 'banana'])
print(counter)  # Output: Counter({'banana': 3, 'apple': 2, 'orange': 1})

# Access the count of a specific element
print(counter['apple'])  # Output: 2

# Get a list of all unique elements
print(list(counter.keys()))  # Output: ['apple', 'banana', 'orange']

# Get a list of counts
print(list(counter.values()))  # Output: [2, 3, 1]

# Get a list of tuples with element-count pairs
print(list(counter.items()))  # Output: [('apple', 2), ('banana', 3), ('orange', 1)]

# Clear the Counter object
counter.clear()
print(counter)  # Output: Counter()
