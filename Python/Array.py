Array-

  len(array): Returns the length (number of elements) of the array.
  array[index]: Returns the element at the specified index.
  array.append(element): Adds an element to the end of the array.
  array.insert(index, element): Inserts an element at the specified index.
  array.remove(element): Removes the first occurrence of the specified element from the array.
  array.pop(index): Removes and returns the element at the specified index.
  array.index(element): Returns the index of the first occurrence of the specified element.
  array.count(element): Returns the number of occurrences of the specified element in the array.
  array.sort(): Sorts the elements of the array in ascending order.
  array.reverse(): Reverses the order of the elements in the array.
  array.copy(): Returns a shallow copy of the array.
  array.clear(): Removes all elements from the array.
  array.extend(iterable): Appends the elements from an iterable to the end of the array.
  array.index(element, start, end): Returns the index of the first occurrence of the specified element within the given range.
  array.pop(): Removes and returns the last element from the array.

  Sort Array:
    sorted(iterable): Returns a new list containing all elements from the iterable in ascending order.
    Example:
      numbers = [3, 1, 4, 1, 5, 9, 2, 6]
      sorted_numbers = sorted(numbers)
      print(sorted_numbers)  # Output: [1, 1, 2, 3, 4, 5, 6, 9]

    sorted(iterable, key): Returns a new list containing all elements from the iterable sorted according to the provided key function.
    Example:
      names = ["Alice", "Bob", "John", "David"]
      sorted_names = sorted(names, key=len)
      print(sorted_names)  # Output: ['Bob', 'John', 'Alice', 'David']


    sorted(iterable, key, reverse): Returns a new list containing all elements from the iterable sorted according to the provided key function,
    with an optional reverse order.
    Example:
      names = ["Alice", "Bob", "John", "David"]
      sorted_names = sorted(names, key=len, reverse=True)
      print(sorted_names)  # Output: ['David', 'Alice', 'John', 'Bob']

    list.sort(): Sorts the elements of the list in ascending order using the default comparison operator.
    Example:
      names = ["Alice", "Bob", "John", "David"]
      sorted_names = sorted(names, key=len, reverse=True)
      print(sorted_names)  # Output: ['David', 'Alice', 'John', 'Bob']

    list.sort(key): Sorts the elements of the list according to the provided key function.
    Example:
      names = ["Alice", "Bob", "John", "David"]
      names.sort(key=len)
      print(names)  # Output: ['Bob', 'John', 'Alice', 'David']

    list.sort(key, reverse): Sorts the elements of the list according to the provided key function, with an optional reverse order.
    Example:
      names = ["Alice", "Bob", "John", "David"]
      names.sort(key=len, reverse=True)
      print(names)  # Output: ['David', 'Alice', 'John', 'Bob']


  Custom sort:

    Custom class:
      class Person:
        def __init__(self, name, age):
            self.name = name
            self.age = age

        def __repr__(self):
            return f"Person(name='{self.name}', age={self.age})"


      people = [
        Person("Alice", 25),
        Person("Bob", 30),
        Person("John", 20),
        Person("David", 35)
      ]

      # Sort in ascending order based on age
      ascending_age = sorted(people, key=lambda p: p.age)
      print(ascending_age)
      # Output: [Person(name='John', age=20), Person(name='Alice', age=25),
      #          Person(name='Bob', age=30), Person(name='David', age=35)]

      # Sort in descending order based on age
      descending_age = sorted(people, key=lambda p: p.age, reverse=True)
      print(descending_age)
      # Output: [Person(name='David', age=35), Person(name='Bob', age=30),
      #          Person(name='Alice', age=25), Person(name='John', age=20)]


      Another approach:

      class Student:
        def __init__(self, name, age):
            self.name = name
            self.age = age

        def __lt__(self, other):
            return self.age < other.age


      students = [
          Student("Alice", 20),
          Student("Bob", 18),
          Student("John", 22),
          Student("David", 19)
      ]

      # Sort the list of students based on their age
      students.sort()

      # Print sorted list of students
      for student in students:
          print(student.name, student.age)


    Array of Arrays:

    sorted()

      data = [[3, 10, 5], [1, 6, 2], [4, 8, 1], [2, 4, 3]]

      # Sort the array based on the second index in ascending order
      ascending_order = sorted(data, key=lambda x: x[1])
      print(ascending_order)
      # Output: [[2, 4, 3], [1, 6, 2], [4, 8, 1], [3, 10, 5]]

      # Sort the array based on the second index in descending order
      descending_order = sorted(data, key=lambda x: x[1], reverse=True)
      print(descending_order)
      # Output: [[3, 10, 5], [4, 8, 1], [1, 6, 2], [2, 4, 3]]

    sort()

      data = [[3, 10, 5], [1, 6, 2], [4, 8, 1], [2, 4, 3]]

      # Sort the array based on the second index in ascending order
      data.sort(key=lambda x: x[1])
      ascending_order = data
      print(ascending_order)
      # Output: [[2, 4, 3], [1, 6, 2], [4, 8, 1], [3, 10, 5]]

      # Sort the array based on the second index in descending order
      data.sort(key=lambda x: x[1], reverse=True)
      descending_order = data
      print(descending_order)
      # Output: [[3, 10, 5], [4, 8, 1], [1, 6, 2], [2, 4, 3]]


    Array of tuples:

    sorted()

      data = [(3, 10, 5), (1, 6, 2), (4, 8, 1), (2, 4, 3)]

      # Sort the array based on the second index in ascending order
      ascending_order = sorted(data, key=lambda x: x[1])
      print(ascending_order)
      # Output: [(2, 4, 3), (1, 6, 2), (4, 8, 1), (3, 10, 5)]

      # Sort the array based on the second index in descending order
      descending_order = sorted(data, key=lambda x: x[1], reverse=True)
      print(descending_order)
      # Output: [(3, 10, 5), (4, 8, 1), (1, 6, 2), (2, 4, 3)]

    sort()

      data = [(3, 10, 5), (1, 6, 2), (4, 8, 1), (2, 4, 3)]

      # Sort the array based on the second index in ascending order
      data.sort(key=lambda x: x[1])
      ascending_order = data
      print(ascending_order)
      # Output: [(2, 4, 3), (1, 6, 2), (4, 8, 1), (3, 10, 5)]

      # Sort the array based on the second index in descending order
      data.sort(key=lambda x: x[1], reverse=True)
      descending_order = data
      print(descending_order)
      # Output: [(3, 10, 5), (4, 8, 1), (1, 6, 2), (2, 4, 3)]



      sorted() vs sort()

        1. sorted() returns a new sorted list, leaving the original list unchanged.
            This can be useful if you want to preserve the original order or need to keep a copy of the original list.
        2. sort() sorts the list in place, modifying the original list.
            This can be advantageous if you don't need to keep the original order and want to save memory by avoiding the creation of a new list.
        3. If you need to sort a list multiple times or perform sorting operations on different variations of the list,
            using sorted() each time can be more convenient and safer, as it avoids unintentional modifications to the original list.
        4. If memory efficiency is a concern or you're working with a large list, using sort() can be more efficient,
            as it avoids the overhead of creating a new list.
        5. If you want to sort a list and immediately iterate over the sorted elements, using sort() can be more efficient,
            as it avoids the need to create an additional list.

        In summary, use sorted() when you want to preserve the original list, need to create a new sorted list, or want to avoid modifying the original list.
        Use sort() when you don't need to keep the original order and want to sort the list in place for efficiency.
        Consider your specific requirements and trade-offs between memory usage, convenience, and performance when choosing between sorted() and sort().
