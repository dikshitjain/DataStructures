Insertion:

map.insert({key, value}) or map[key] = value
Time Complexity: Average case: O(log N), Worst case: O(N) if the map needs to be resized
Space Complexity: O(N), where N is the number of elements in the map
Deletion:

map.erase(key)
Time Complexity: Average case: O(log N), Worst case: O(N) if the map needs to be resized
Space Complexity: O(N), where N is the number of elements in the map
Accessing elements:

map[key]
Time Complexity: Average case: O(log N), Worst case: O(N) if the map needs to be resized
Space Complexity: O(1)
Finding elements:

map.find(key)
Time Complexity: Average case: O(log N), Worst case: O(N) if the map needs to be resized
Space Complexity: O(1)
Check if an element exists:

map.count(key)
Time Complexity: Average case: O(log N), Worst case: O(N) if the map needs to be resized
Space Complexity: O(1)
Size of the map:

map.size()
Time Complexity: O(1)
Space Complexity: O(1)
Clear the map:

map.clear()
Time Complexity: O(N), where N is the number of elements in the map
Space Complexity: O(1)

Please note that the time and space complexities mentioned here are based on the assumption that
the map is implemented as a balanced binary search tree (e.g., Red-Black Tree) and not a hash map.

Example:
  #include <iostream>
  #include <map>

  int main() {
      std::map<std::string, int> omap;

      // Inserting key-value pairs into the ordered map
      omap.insert({"apple", 5});
      omap.insert({"banana", 3});
      omap.insert({"orange", 2});
      omap.insert({"grape", 4});

      // Accessing elements by key
      std::cout << "Number of apples: " << omap["apple"] << std::endl;
      std::cout << "Number of bananas: " << omap["banana"] << std::endl;

      // Checking if a key exists
      if (omap.count("orange") > 0) {
          std::cout << "Orange is present in the ordered map" << std::endl;
      }

      // Updating the value for a key
      omap["banana"] = 6;

      // Removing a key-value pair
      omap.erase("grape");

      // Iterating over the ordered map
      for (const auto& pair : omap) {
          std::cout << "Fruit: " << pair.first << ", Count: " << pair.second << std::endl;
      }

      return 0;
  }

Pair is the key:

  #include <iostream>
  #include <map>

  int main() {
      std::map<std::pair<int, int>, std::string> myMap;

      // Inserting key-value pairs into the map
      myMap.insert({{1, 1}, "One"});
      myMap.insert({{2, 3}, "Two"});
      myMap.insert({{4, 5}, "Three"});

      // Accessing elements by key
      std::cout << "Value at key (2, 3): " << myMap[{2, 3}] << std::endl;

      // Iterating over the map
      for (const auto& pair : myMap) {
          std::cout << "Key: (" << pair.first.first << ", " << pair.first.second << "), Value: " << pair.second << std::endl;
      }

      return 0;
  }

Vector is the key:

  #include <iostream>
  #include <map>
  #include <vector>
  #include <functional>

  // Custom comparison function for comparing vectors
  struct VectorCompare {
      bool operator()(const std::vector<int>& v1, const std::vector<int>& v2) const {
          return v1 < v2; // Custom comparison logic
      }
  };

  int main() {
      std::map<std::vector<int>, std::string, VectorCompare> myMap;

      // Inserting key-value pairs into the map
      myMap.insert({{1, 2, 3}, "One"});
      myMap.insert({{4, 5, 6}, "Two"});
      myMap.insert({{7, 8, 9}, "Three"});

      // Accessing elements by key
      std::vector<int> key = {4, 5, 6};
      std::cout << "Value at key {4, 5, 6}: " << myMap[key] << std::endl;

      // Iterating over the map
      for (const auto& pair : myMap) {
          const auto& key = pair.first;
          const auto& value = pair.second;
          std::cout << "Key: ";
          for (int num : key) {
              std::cout << num << " ";
          }
          std::cout << ", Value: " << value << std::endl;
      }

      return 0;
  }

Custom class:

  Operator overloading:

    #include <iostream>
    #include <map>
    #include <string>

    // Custom class used as the key
    class CustomKey {
    public:
      int id;
      std::string name;

      // Custom comparison function for ordering keys
      bool operator<(const CustomKey& other) const {
          return id < other.id;
      }
    };

    int main() {
      std::map<CustomKey, std::string> myMap;

      // Inserting key-value pairs into the map
      CustomKey key1{1, "One"};
      CustomKey key2{2, "Two"};
      CustomKey key3{3, "Three"};
      myMap[key1] = "Value1";
      myMap[key2] = "Value2";
      myMap[key3] = "Value3";

      // Accessing elements by key
      std::cout << "Value at key {2, 'Two'}: " << myMap[key2] << std::endl;

      // Iterating over the map
      for (const auto& pair : myMap) {
          const auto& key = pair.first;
          const auto& value = pair.second;
          std::cout << "Key: {id: " << key.id << ", name: " << key.name << "}, Value: " << value << std::endl;
      }

      return 0;
    }

    Functor:

      #include <iostream>
      #include <map>
      #include <string>

      // Custom class used as the key
      class CustomKey {
      public:
          int id;
          std::string name;
      };

      // Functor for comparing keys
      struct CustomKeyComparator {
          bool operator()(const CustomKey& key1, const CustomKey& key2) const {
              return key1.id < key2.id;
          }
      };

      int main() {
          // Using a functor for comparison
          std::map<CustomKey, std::string, CustomKeyComparator> mapWithFunctor;

          CustomKey key1{1, "One"};
          CustomKey key2{2, "Two"};
          CustomKey key3{3, "Three"};

          mapWithFunctor[key1] = "Value1";
          mapWithFunctor[key2] = "Value2";
          mapWithFunctor[key3] = "Value3";

          std::cout << "Using functor comparison:" << std::endl;
          for (const auto& pair : mapWithFunctor) {
              const auto& key = pair.first;
              const auto& value = pair.second;
              std::cout << "Key: {id: " << key.id << ", name: " << key.name << "}, Value: " << value << std::endl;
          }

          return 0;
      }

      Lambda:

        #include <iostream>
        #include <map>
        #include <string>

        int main() {

            // Using a lambda function for comparison
            std::map<CustomKey, std::string, decltype([](const CustomKey& k1, const CustomKey& k2) {
                                                   return k1.id < k2.id;
                                               })> mapWithLambda;

            mapWithLambda[key1] = "Value1";
            mapWithLambda[key2] = "Value2";
            mapWithLambda[key3] = "Value3";

            std::cout << "Using lambda comparison:" << std::endl;
            for (const auto& pair : mapWithLambda) {
                const auto& key = pair.first;
                const auto& value = pair.second;
                std::cout << "Key: {id: " << key.id << ", name: " << key.name << "}, Value: " << value << std::endl;
            }

          return 0;
        }

        Lower bound and Upper bound:

          #include <iostream>
          #include <map>

          int main() {
              std::map<std::pair<int, int>, std::string> myMap;
              myMap[{10, 20}] = "Value1";
              myMap[{30, 40}] = "Value2";
              myMap[{50, 60}] = "Value3";

              // Find lower bound and upper bound for key {30, 35}
              auto lower = myMap.lower_bound({30, 35});
              auto upper = myMap.upper_bound({30, 35});

              if (lower != myMap.end()) {
                  std::cout << "Lower Bound: " << lower->first.first << ", " << lower->first.second << " - " << lower->second << std::endl;
              } else {
                  std::cout << "Lower Bound not found" << std::endl;
              }

              if (upper != myMap.end()) {
                  std::cout << "Upper Bound: " << upper->first.first << ", " << upper->first.second << " - " << upper->second << std::endl;
              } else {
                  std::cout << "Upper Bound not found" << std::endl;
              }

              return 0;
          }
