https://grantjenks.com/docs/sortedcontainers/sorteddict.html

The SortedDict class is not available as a built-in class in Python. However, you can achieve similar functionality using the sortedcontainers library, which provides a SortedDict implementation. Here are the common APIs of SortedDict along with their time and space complexities:

__getitem__(key): Get the value associated with the specified key.

Time Complexity: O(log n)
Space Complexity: O(1)

__setitem__(key, value): Set the value associated with the specified key.

Time Complexity: O(log n)
Space Complexity: O(1)

__delitem__(key): Remove the key-value pair with the specified key.

Time Complexity: O(log n)
Space Complexity: O(1)

__contains__(key): Check if the specified key exists in the SortedDict.

Time Complexity: O(log n)
Space Complexity: O(1)

__len__(): Get the number of key-value pairs in the SortedDict.

Time Complexity: O(1)
Space Complexity: O(1)

keys(): Get a view of all the keys in the SortedDict.

Time Complexity: O(n)
Space Complexity: O(n)

values(): Get a view of all the values in the SortedDict.

Time Complexity: O(n)
Space Complexity: O(n)

items(): Get a view of all the key-value pairs in the SortedDict.

Time Complexity: O(n)
Space Complexity: O(n)

get(key, default=None): Get the value associated with the specified key, or a default value if the key is not present.

Time Complexity: O(log n)
Space Complexity: O(1)

pop(key, default=None): Remove the key-value pair with the specified key and return its value, or a default value if the key is not present.

Time Complexity: O(log n)
Space Complexity: O(1)

clear(): Remove all key-value pairs from the SortedDict.
Time Complexity: O(1)
Space Complexity: O(1)

Example:
    from sortedcontainers import SortedDict

    # Create a SortedDict
    sorted_dict = SortedDict()

    # Add key-value pairs
    sorted_dict[3] = "Value 3"
    sorted_dict[1] = "Value 1"
    sorted_dict[4] = "Value 4"
    sorted_dict[2] = "Value 2"

    # Access values by key
    print(sorted_dict[3])  # Output: Value 3

    # Iterate over keys and values
    for key, value in sorted_dict.items():
        print(key, value)

    # Check if a key exists
    print(2 in sorted_dict)  # Output: True

    # Get the number of key-value pairs
    print(len(sorted_dict))  # Output: 4

    # Remove a key-value pair
    del sorted_dict[1]

    # Get a view of all keys
    keys = sorted_dict.keys()
    print(keys)  # Output: [2, 3, 4]

    # Get a view of all values
    values = sorted_dict.values()
    print(values)  # Output: ['Value 2', 'Value 3', 'Value 4']

    # Clear the SortedDict
    sorted_dict.clear()

    # Check if the SortedDict is empty
    print(len(sorted_dict) == 0)  # Output: True


Custom Class:

    from sortedcontainers import SortedDict

    # Custom class for keys
    class KeyClass:
        def __init__(self, value):
            self.value = value

        def __repr__(self):
            return f"KeyClass({self.value})"

        def __lt__(self, other):
            return self.value < other.value

    # Create a SortedDict with custom class keys
    sorted_dict = SortedDict()

    # Add key-value pairs with custom class keys
    sorted_dict[KeyClass(3)] = "Value 3"
    sorted_dict[KeyClass(1)] = "Value 1"
    sorted_dict[KeyClass(4)] = "Value 4"
    sorted_dict[KeyClass(2)] = "Value 2"

    # Access values by custom class key
    print(sorted_dict[KeyClass(3)])  # Output: Value 3

    # Iterate over keys and values
    for key, value in sorted_dict.items():
        print(key, value)

    # Check if a custom class key exists
    print(KeyClass(2) in sorted_dict)  # Output: True

    # Get the number of key-value pairs
    print(len(sorted_dict))  # Output: 4

    # Remove a key-value pair with a custom class key
    del sorted_dict[KeyClass(1)]

    # Get a view of all keys
    keys = sorted_dict.keys()
    print(keys)  # Output: [KeyClass(2), KeyClass(3), KeyClass(4)]

    # Get a view of all values
    values = sorted_dict.values()
    print(values)  # Output: ['Value 2', 'Value 3', 'Value 4']

    # Clear the SortedDict
    sorted_dict.clear()

    # Check if the SortedDict is empty
    print(len(sorted_dict) == 0)  # Output: True

Upper Bound and Lower Bound:

    from sortedcontainers import SortedDict
    import bisect

    def lower_bound(sorted_dict, key):
        keys = sorted_dict.keys()
        index = bisect.bisect_left(keys, key)
        if index == len(keys):
            return None
        return keys[index]

    def upper_bound(sorted_dict, key):
        keys = sorted_dict.keys()
        index = bisect.bisect_right(keys, key)
        if index == len(keys):
            return None
        return keys[index]

    # Create a SortedDict
    sorted_dict = SortedDict()
    sorted_dict[3] = "Value 3"
    sorted_dict[1] = "Value 1"
    sorted_dict[4] = "Value 4"
    sorted_dict[2] = "Value 2"

    # Get lower bound and upper bound
    lb_key = lower_bound(sorted_dict, 2)
    ub_key = upper_bound(sorted_dict, 2)

    if lb_key is not None:
        print("Lower Bound:", lb_key, sorted_dict[lb_key])
    else:
        print("Lower Bound: Not Found")

    if ub_key is not None:
        print("Upper Bound:", ub_key, sorted_dict[ub_key])
    else:
        print("Upper Bound: Not Found")
