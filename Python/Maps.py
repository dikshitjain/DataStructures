dict() or {}: Create an empty dictionary.
dict(key1=value1, key2=value2, ...): Create a dictionary with initial key-value pairs.
len(dict): Get the number of key-value pairs in the dictionary.
key in dict: Check if a key exists in the dictionary.
dict[key]: Access the value associated with a key.
dict[key] = value: Assign a value to a key or update an existing key-value pair.
del dict[key]: Remove a key-value pair from the dictionary.
dict.keys(): Get a list of all keys in the dictionary.
dict.values(): Get a list of all values in the dictionary.
dict.items(): Get a list of all key-value pairs in the dictionary as tuples.
dict.get(key, default): Get the value associated with a key, or a default value
                        if the key does not exist.
dict.pop(key, default): Remove and return the value associated with a key, or a default value
                        if the key does not exist.
dict.popitem(): Remove and return an arbitrary key-value pair from the dictionary.
dict.clear(): Remove all key-value pairs from the dictionary.

To add a value to a dictionary if it is not present and increment it by 1 if it is already present

Approach 1:

    my_dict = {}

    # Example key
    key = "apple"

    # Check if the key exists in the dictionary
    if key in my_dict:
        # Key exists, increment the value by 1
        my_dict[key] += 1
    else:
        # Key does not exist, set the value to 1
        my_dict[key] = 1

    print(my_dict)

Approach 2:

    from collections import defaultdict

    my_dict = defaultdict(int)

    # Example key
    key = "apple"

    # Increment the value by 1
    my_dict[key] += 1

    print(my_dict)

If key is a list of integers:

    my_dict = {}

    # Example key as a list
    key = [1, 2, 3]

    # Convert the list to a tuple
    key_tuple = tuple(key)

    # Store a value using the tuple as the key
    my_dict[key_tuple] = "Value"

    # Retrieve the value using the tuple as the key
    value = my_dict[key_tuple]

    print(value)  # Output: Value

Custom class:

    class MyClass:
        def __init__(self, id, name):
            self.id = id
            self.name = name

        def __hash__(self):
            return hash((self.id, self.name))

        def __eq__(self, other):
            if isinstance(other, MyClass):
                return self.id == other.id and self.name == other.name
            return False

    # Create instances of MyClass
    obj1 = MyClass(1, "Alice")
    obj2 = MyClass(2, "Bob")
    obj3 = MyClass(3, "Charlie")

    # Store instances in a dictionary
    my_dict = {
        obj1: "Value 1",
        obj2: "Value 2",
        obj3: "Value 3"
    }

    # Access values using custom class instances as keys
    print(my_dict[obj1])  # Output: Value 1
    print(my_dict[obj2])  # Output: Value 2
    print(my_dict[obj3])  # Output: Value 3

Multimap (Repetitive keys):

    from collections import defaultdict

    multimap = defaultdict(list)

    # Add elements to the multimap
    multimap["key1"].append("value1")
    multimap["key1"].append("value2")
    multimap["key2"].append("value3")
    multimap["key2"].append("value4")

    # Retrieve values for a key
    print(multimap["key1"])  # Output: ['value1', 'value2']
    print(multimap["key2"])  # Output: ['value3', 'value4']
