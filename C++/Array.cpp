Array/Vector-

  std::array: A container class template that encapsulates fixed-size arrays.
  std::vector: A dynamic array that can resize itself.
  std::array::size(): Returns the size (number of elements) of the array.
  std::vector::size(): Returns the size (number of elements) of the vector.
  std::array::at(index): Returns a reference to the element at the specified index, performing bounds checking.
  std::vector::at(index): Returns a reference to the element at the specified index, performing bounds checking.
  std::array::operator[](index): Returns a reference to the element at the specified index, without bounds checking.
  std::vector::operator[](index): Returns a reference to the element at the specified index, without bounds checking.
  std::array::front(): Returns a reference to the first element in the array.
  std::vector::front(): Returns a reference to the first element in the vector.
  std::array::back(): Returns a reference to the last element in the array.
  std::vector::back(): Returns a reference to the last element in the vector.
  std::array::data(): Returns a pointer to the underlying array.
  std::vector::data(): Returns a pointer to the underlying array.
  std::array::fill(value): Assigns the specified value to all elements in the array.
  std::vector::push_back(value): Adds an element to the end of the vector.
  std::vector::pop_back(): Removes the last element from the vector.
  std::array::swap(other): Swaps the contents of the array with another array of the same type and size.
  std::vector::swap(other): Swaps the contents of the vector with another vector of the same type and size.
  std::copy(source_begin, source_end, dest_begin): Copies a range of elements from the source array to the destination array.

  Sort Array:
    std::sort(begin, end): Sorts the elements in the specified range in ascending order using the default comparison operator.
    std::sort(begin, end, comp): Sorts the elements in the specified range using the provided comparison function or lambda expression.
    std::stable_sort(begin, end): Sorts the elements in the specified range in ascending order while preserving the relative order of equal elements.
    std::stable_sort(begin, end, comp): Sorts the elements in the specified range using a stable sorting algorithm and the provided comparison function.
    std::partial_sort(begin, middle, end): Rearranges the elements in the range [begin, end) such that the elements before 'middle' are sorted in ascending order.
    std::partial_sort(begin, middle, end, comp): Rearranges the elements in the range [begin, end) using the provided comparison function, with the elements before 'middle' sorted in ascending order.

  Ranges Sort Array:
    std::ranges::sort(range): Sorts the elements in the range in ascending order using the default comparison operator.
    std::ranges::sort(range, comp): Sorts the elements in the range using the provided comparison function or lambda expression.
    std::ranges::stable_sort(range): Sorts the elements in the range in ascending order while preserving the relative order of equal elements.
    std::ranges::stable_sort(range, comp): Sorts the elements in the range using a stable sorting algorithm and the provided comparison function.
    std::ranges::partial_sort(range, middle): Rearranges the elements in the range such that the elements before 'middle' are sorted in ascending order.
    std::ranges::partial_sort(range, middle, comp): Rearranges the elements in the range using the provided comparison function, with the elements before 'middle' sorted in ascending order.

  Custom Sorting:

      Lambda Functions:

        Lambda functions provide a concise and inline way to define a comparison function on the fly.
        They are convenient for simple and one-time comparisons where you don't need to reuse the comparison logic elsewhere.
        Lambda functions are especially useful when the comparison logic is straightforward and doesn't involve complex operations.

        Ascending-
          #include <iostream>
          #include <vector>
          #include <ranges>
          #include <algorithm>

          struct MyClass {
              int id;
              std::string name;
              // ... other members and methods
          };

          int main() {
              std::vector<MyClass> myVector = { {2, "John"}, {1, "Alice"}, {3, "Bob"} };

              std::ranges::sort(myVector, [](const MyClass& a, const MyClass& b) {
                  return a.id < b.id;
              });

              // Print sorted vector
              for (const auto& obj : myVector) {
                  std::cout << obj.id << " - " << obj.name << std::endl;
              }

              return 0;
          }

        Descending-

          #include <iostream>
          #include <vector>
          #include <ranges>
          #include <algorithm>

          struct MyClass {
            int id;
            std::string name;
            // ... other members and methods
          };

          int main() {
            std::vector<MyClass> myVector = { {2, "John"}, {1, "Alice"}, {3, "Bob"} };

            std::ranges::sort(myVector, [](const MyClass& a, const MyClass& b) {
                return a.id > b.id;
            });

            // Print sorted vector
            for (const auto& obj : myVector) {
                std::cout << obj.id << " - " << obj.name << std::endl;
            }

            return 0;
          }


      Functors (Function Objects):

        Functors are objects that behave like functions. You define a class with an overloaded operator() that implements the comparison logic.
        Functors offer more flexibility and reusability compared to lambda functions.
        They allow you to define multiple comparison functions within a single class.
        Functors can store additional state and have member variables, enabling more advanced sorting behavior.

        Ascending-

          #include <iostream>
          #include <vector>
          #include <ranges>
          #include <algorithm>

          struct MyClass {
              int id;
              std::string name;
              // ... other members and methods
          };

          // Functor for sorting MyClass objects based on 'id'
          struct CompareById {
              bool operator()(const MyClass& a, const MyClass& b) const {
                  return a.id < b.id;
              }
          };

          int main() {
              std::vector<MyClass> myVector = { {2, "John"}, {1, "Alice"}, {3, "Bob"} };

              std::ranges::sort(myVector, CompareById{});

              // Print sorted vector
              for (const auto& obj : myVector) {
                  std::cout << obj.id << " - " << obj.name << std::endl;
              }

              return 0;
          }

        Descending-

          #include <iostream>
          #include <vector>
          #include <ranges>
          #include <algorithm>

          struct MyClass {
            int id;
            std::string name;
            // ... other members and methods
          };

          // Functor for sorting MyClass objects based on 'id' in descending order
          struct CompareByIdDescending {
            bool operator()(const MyClass& a, const MyClass& b) const {
                return a.id > b.id;
            }
          };

          int main() {
            std::vector<MyClass> myVector = { {2, "John"}, {1, "Alice"}, {3, "Bob"} };

            std::ranges::sort(myVector, CompareByIdDescending{});

            // Print sorted vector
            for (const auto& obj : myVector) {
                std::cout << obj.id << " - " << obj.name << std::endl;
            }

            return 0;
          }

      Operator Overriding:

        Operator overriding involves defining comparison operators (<, >, etc.) directly within the class definition.
        It provides a natural and intuitive way to compare objects using the built-in operators.
        Operator overriding is useful when the comparison logic is an inherent part of the class's behavior.
        It allows for seamless integration with standard library algorithms that rely on operators for comparisons.

        Ascending-
          #include <iostream>
          #include <vector>
          #include <ranges>
          #include <algorithm>

          struct MyClass {
              int id;
              std::string name;
              // ... other members and methods
          };

          int main() {
              std::vector<MyClass> myVector = { {2, "John"}, {1, "Alice"}, {3, "Bob"} };

              // By providing &MyClass::id as the projection argument, it instructs std::ranges::sort to sort the vector based on the id field of MyClass objects.
              std::ranges::sort(myVector, {}, &MyClass::id);

              // Print sorted vector
              for (const auto& obj : myVector) {
                  std::cout << obj.id << " - " << obj.name << std::endl;
              }

              return 0;
          }

          Descending (with Projection)-

            #include <iostream>
            #include <vector>
            #include <ranges>
            #include <algorithm>

            struct MyClass {
                int id;
                std::string name;
                // ... other members and methods
            };

            int main() {
                std::vector<MyClass> myVector = { {2, "John"}, {1, "Alice"}, {3, "Bob"} };

                std::ranges::sort(myVector, std::greater{}, &MyClass::id);

                // Print sorted vector
                for (const auto& obj : myVector) {
                    std::cout << obj.id << " - " << obj.name << std::endl;
                }

                return 0;
            }

  A projection argument is a concept in the C++20 Standard Library that allows you to specify the key or value used for
  comparisons, transformations, or filtering during range-based operations.
  It allows you to extract specific values from elements in a range without modifying the original elements.
  For example, in sorting, a projection argument specifies the key on which the sorting
  should be based, such as a member variable or a custom function. It provides flexibility and customization
  in range-based algorithms by defining the criterion for the operation.
