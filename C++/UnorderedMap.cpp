insert(key, value): Inserts a key-value pair into the map.
O(1) average case, O(n) worst case for collision resolution. O(1) space complexity.

erase(key): Removes the key-value pair with the given key from the map.
O(1) average case, O(n) worst case for collision resolution. O(1) space complexity.

clear(): Removes all key-value pairs from the map.
O(n) time complexity to clear all elements. O(1) space complexity.

find(key): Returns an iterator pointing to the key-value pair with the given key.
O(1) average case, O(n) worst case for collision resolution. O(1) space complexity.

count(key): Returns the number of key-value pairs with the given key in the map (0 or 1 for unique keys).
O(1) average case, O(n) worst case for collision resolution. O(1) space complexity.

size(): Returns the number of key-value pairs in the map.
O(1) time complexity.

empty(): Checks if the map is empty.
O(1) time complexity.

operator[]: Accesses or inserts the value associated with the given key.
O(1) average case, O(n) worst case for collision resolution. O(1) space complexity.

begin(): Returns an iterator pointing to the first key-value pair in the map.
O(1) time complexity.

end(): Returns an iterator pointing to the past-the-end key-value pair in the map.
O(1) time complexity.

Example:

  Using Functor

  #include <iostream>
  #include <unordered_map>

  int main() {
      // Create an unordered map
      std::unordered_map<std::string, int> myMap;

      // Insert key-value pairs
      myMap["apple"] = 3;
      myMap["banana"] = 2;
      myMap["orange"] = 5;

      // Access values by key
      std::cout << "Value of apple: " << myMap["apple"] << std::endl;
      std::cout << "Value of banana: " << myMap["banana"] << std::endl;

      // Update values
      myMap["apple"] = 4;

      // Iterate over key-value pairs
      for (const auto& pair : myMap) {
          std::cout << pair.first << ": " << pair.second << std::endl;
      }

      // Check if a key exists
      if (myMap.count("orange")) {
          std::cout << "Orange exists in the map." << std::endl;
      }

      // Remove a key-value pair
      myMap.erase("banana");

      // Check the size of the map
      std::cout << "Size of map: " << myMap.size() << std::endl;

      // Clear the map
      myMap.clear();

      // Check if the map is empty
      if (myMap.empty()) {
          std::cout << "Map is empty." << std::endl;
      }

      return 0;
  }

if std::pair is the key:

  #include <iostream>
  #include <unordered_map>
  #include <functional>

  // Custom hash function for std::pair
  struct PairHash {
      template <typename T, typename U>
      std::size_t operator()(const std::pair<T, U>& p) const {
          auto h1 = std::hash<T>{}(p.first);
          auto h2 = std::hash<U>{}(p.second);
          return h1 ^ h2;
      }
  };

  // Custom equality operator for std::pair
  struct PairEqual {
      template <typename T, typename U>
      bool operator()(const std::pair<T, U>& p1, const std::pair<T, U>& p2) const {
          return p1.first == p2.first && p1.second == p2.second;
      }
  };

  int main() {
      // Create an unordered map with std::pair as key
      std::unordered_map<std::pair<int, int>, std::string, PairHash, PairEqual> myMap;

      // Insert key-value pairs
      myMap[{1, 2}] = "apple";
      myMap[{3, 4}] = "banana";
      myMap[{5, 6}] = "orange";

      // Access values by key
      std::cout << "Value of {1, 2}: " << myMap[{1, 2}] << std::endl;
      std::cout << "Value of {3, 4}: " << myMap[{3, 4}] << std::endl;

      // Iterate over key-value pairs
      for (const auto& pair : myMap) {
          std::cout << "{" << pair.first.first << ", " << pair.first.second << "}: " << pair.second << std::endl;
      }

      return 0;
  }

  Using lambda:

  #include <iostream>
  #include <unordered_map>

  int main() {
      std::unordered_map<std::pair<int, int>, std::string, decltype([](const auto& p) {
          auto h1 = std::hash<int>{}(p.first);
          auto h2 = std::hash<int>{}(p.second);
          return h1 ^ h2;
      }), decltype([](const auto& p1, const auto& p2) {
          return p1.first == p2.first && p1.second == p2.second;
      })> myMap;

      myMap[{1, 2}] = "apple";
      myMap[{3, 4}] = "banana";
      myMap[{5, 6}] = "orange";

      for (const auto& pair : myMap) {
          std::cout << "{" << pair.first.first << ", " << pair.first.second << "}: " << pair.second << std::endl;
      }

      return 0;
  }

if Vector is the key:

  Using functor:

  #include <iostream>
  #include <unordered_map>
  #include <vector>

  // Functor for custom hash function
  struct VectorHash {
      std::size_t operator()(const std::vector<int>& v) const {
          std::size_t seed = 0;
          for (const auto& elem : v) {
              seed ^= std::hash<int>{}(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
          }
          return seed;
      }
  };

  // Functor for custom equality operator
  struct VectorEqual {
      bool operator()(const std::vector<int>& v1, const std::vector<int>& v2) const {
          return v1 == v2;
      }
  };

  int main() {
      std::unordered_map<std::vector<int>, std::string, VectorHash, VectorEqual> myMap;

      std::vector<int> key1 = {1, 2, 3};
      std::vector<int> key2 = {4, 5, 6};
      std::vector<int> key3 = {7, 8, 9};

      myMap[key1] = "apple";
      myMap[key2] = "banana";
      myMap[key3] = "orange";

      for (const auto& pair : myMap) {
          const auto& key = pair.first;
          std::cout << "Key: ";
          for (const auto& elem : key) {
              std::cout << elem << " ";
          }
          std::cout << ", Value: " << pair.second << std::endl;
      }

      return 0;
  }


  Using lambda:

  #include <iostream>
  #include <unordered_map>
  #include <vector>

  int main() {
      std::unordered_map<std::vector<int>, std::string, decltype([](const auto& v) {
          std::size_t seed = 0;
          for (const auto& elem : v) {
              seed ^= std::hash<int>{}(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
          }
          return seed;
      }), decltype([](const auto& v1, const auto& v2) {
          return v1 == v2;
      })> myMap;

      std::vector<int> key1 = {1, 2, 3};
      std::vector<int> key2 = {4, 5, 6};
      std::vector<int> key3 = {7, 8, 9};

      myMap[key1] = "apple";
      myMap[key2] = "banana";
      myMap[key3] = "orange";

      for (const auto& pair : myMap) {
          const auto& key = pair.first;
          std::cout << "Key: ";
          for (const auto& elem : key) {
              std::cout << elem << " ";
          }
          std::cout << ", Value: " << pair.second << std::endl;
      }

      return 0;
  }

Custom class:

  #include <iostream>
  #include <unordered_map>

  // Custom class for the key
  class MyClass {
  public:
    int id;
    std::string name;

    // Constructor
    MyClass(int id, const std::string& name) : id(id), name(name) {}

    // Equality operator
    bool operator==(const MyClass& other) const {
        return id == other.id && name == other.name;
    }
  };

  // Functor for custom hash function
  struct MyClassHash {
    std::size_t operator()(const MyClass& key) const {
        std::size_t hash1 = std::hash<int>{}(key.id);
        std::size_t hash2 = std::hash<std::string>{}(key.name);
        return hash1 ^ hash2;
    }
  };

  int main() {
    std::unordered_map<MyClass, int, MyClassHash> myMap;

    MyClass key1(1, "apple");
    MyClass key2(2, "banana");
    MyClass key3(3, "orange");

    myMap[key1] = 10;
    myMap[key2] = 20;
    myMap[key3] = 30;

    for (const auto& pair : myMap) {
        const auto& key = pair.first;
        std::cout << "Key: id=" << key.id << ", name=" << key.name << ", Value: " << pair.second << std::endl;
    }

    return 0;
  }
