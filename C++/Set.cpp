insert(const value_type& val): Inserts an element into the set.

Time Complexity: Average case O(log N), Worst case O(N) if the insertion triggers a re-balancing of the tree.
Space Complexity: O(1)

erase(const value_type& val): Removes an element from the set.

Time Complexity: Average case O(log N), Worst case O(N) if the removal triggers a re-balancing of the tree.
Space Complexity: O(1)

find(const value_type& val): Searches for an element in the set.

Time Complexity: Average case O(log N), Worst case O(N) if the search triggers a re-balancing of the tree.
Space Complexity: O(1)

lower_bound(const value_type& val): Returns an iterator pointing to the first element that is not
                                    less than the given value.

Time Complexity: Average case O(log N), Worst case O(N) if the search triggers a re-balancing of the tree.
Space Complexity: O(1)

upper_bound(const value_type& val): Returns an iterator pointing to the first element that is
                                    greater than the given value.

Time Complexity: Average case O(log N), Worst case O(N) if the search triggers a re-balancing of the tree.
Space Complexity: O(1)

begin(): Returns an iterator to the first element in the set.

Time Complexity: O(1)
Space Complexity: O(1)

end(): Returns an iterator to the past-the-end element in the set.

Time Complexity: O(1)
Space Complexity: O(1)

size(): Returns the number of elements in the set.

Time Complexity: O(1)
Space Complexity: O(1)

empty(): Checks if the set is empty.

Refer Map.cpp for custom class changes

Time Complexity: O(1)
Space Complexity: O(1)

Lower bound and upper bound:

  #include <iostream>
  #include <set>

  int main() {
      std::set<int> mySet = {10, 20, 30, 40, 50};

      // Find lower bound and upper bound for key 25
      auto lower = mySet.lower_bound(25);
      auto upper = mySet.upper_bound(25);

      if (lower != mySet.end()) {
          std::cout << "Lower Bound: " << *lower << std::endl;
      } else {
          std::cout << "Lower Bound not found" << std::endl;
      }

      if (upper != mySet.end()) {
          std::cout << "Upper Bound: " << *upper << std::endl;
      } else {
          std::cout << "Upper Bound not found" << std::endl;
      }

      return 0;
  }
