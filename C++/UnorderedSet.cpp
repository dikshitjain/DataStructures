insert(value): Inserts an element into the unordered set.

Time Complexity: Average case O(1), Worst case O(n)
Space Complexity: O(1) amortized

erase(value): Removes the element with the specified value from the unordered set.

Time Complexity: Average case O(1), Worst case O(n)
Space Complexity: O(1) amortized

find(value): Searches for the element with the specified value in the unordered set.

Time Complexity: Average case O(1), Worst case O(n)
Space Complexity: O(1)

count(value): Returns the number of elements with the specified value in the
unordered set (0 or 1 for unordered set).

Time Complexity: Average case O(1), Worst case O(n)
Space Complexity: O(1)

size(): Returns the number of elements in the unordered set.

Time Complexity: O(1)
Space Complexity: O(1)

empty(): Checks if the unordered set is empty.

Time Complexity: O(1)
Space Complexity: O(1)

clear(): Removes all elements from the unordered set.

Time Complexity: Linear in the number of elements in the set
Space Complexity: O(1)

Set Operations:

Set Union:

API: std::ranges::set_union
Time Complexity: O(N + M), where N and M are the sizes of the input ranges.
Space Complexity: O(N + M), where N and M are the sizes of the input ranges.
Set Intersection:

API: std::ranges::set_intersection
Time Complexity: O(N + M), where N and M are the sizes of the input ranges.
Space Complexity: O(N + M), where N and M are the sizes of the input ranges.
Set Difference:

API: std::ranges::set_difference
Time Complexity: O(N + M), where N and M are the sizes of the input ranges.
Space Complexity: O(N), where N is the size of the input range.
Symmetric Difference:

API: std::ranges::set_symmetric_difference
Time Complexity: O(N + M), where N and M are the sizes of the input ranges.
Space Complexity: O(N + M), where N and M are the sizes of the input ranges.
Subset Check:

API: std::ranges::includes
Time Complexity: O(N + M), where N and M are the sizes of the input ranges.
Space Complexity: O(1).

  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <ranges>

  int main() {
      std::vector<int> set1 = {1, 2, 3, 4, 5};
      std::vector<int> set2 = {4, 5, 6, 7, 8};

      // Set union
      std::vector<int> unionSet;
      std::ranges::set_union(set1, set2, std::back_inserter(unionSet));

      // Set intersection
      std::vector<int> intersectionSet;
      std::ranges::set_intersection(set1, set2, std::back_inserter(intersectionSet));

      // Print the results
      std::cout << "Set Union: ";
      for (int value : unionSet) {
          std::cout << value << " ";
      }
      std::cout << std::endl;

      std::cout << "Set Intersection: ";
      for (int value : intersectionSet) {
          std::cout << value << " ";
      }
      std::cout << std::endl;

      return 0;
  }


  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <ranges>

  int main() {
      std::vector<int> set1 = {1, 2, 3, 4, 5};
      std::vector<int> set2 = {4, 5, 6, 7, 8};

      std::vector<int> differenceSet;
      std::ranges::set_difference(set1, set2, std::back_inserter(differenceSet));

      std::cout << "Set Difference: ";
      for (int value : differenceSet) {
          std::cout << value << " ";
      }
      std::cout << std::endl;

      return 0;
  }


  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <ranges>

  int main() {
      std::vector<int> set1 = {1, 2, 3, 4, 5};
      std::vector<int> set2 = {4, 5, 6, 7, 8};

      std::vector<int> symmetricDifferenceSet;
      std::ranges::set_symmetric_difference(set1, set2, std::back_inserter(symmetricDifferenceSet));

      std::cout << "Symmetric Difference: ";
      for (int value : symmetricDifferenceSet) {
          std::cout << value << " ";
      }
      std::cout << std::endl;

      return 0;
  }


  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <ranges>

  int main() {
      std::vector<int> set1 = {1, 2, 3, 4, 5};
      std::vector<int> set2 = {2, 4, 5};

      bool isSubset = std::ranges::includes(set1, set2);

      std::cout << "Is Subset: " << std::boolalpha << isSubset << std::endl;

      return 0;
  }
