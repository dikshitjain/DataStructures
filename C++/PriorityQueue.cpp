std::priority_queue Initialization:

Syntax: std::priority_queue<Type, Container, Compare> pq;
Time Complexity: O(1)
Space Complexity: O(N), where N is the number of elements in the priority queue.
push():

Syntax: pq.push(value);
Time Complexity: O(log N), where N is the number of elements in the priority queue.
Space Complexity: O(1)
top():

Syntax: pq.top();
Time Complexity: O(1)
Space Complexity: O(1)
pop():

Syntax: pq.pop();
Time Complexity: O(log N), where N is the number of elements in the priority queue.
Space Complexity: O(1)
size():

Syntax: pq.size();
Time Complexity: O(1)
Space Complexity: O(1)
empty():

Syntax: pq.empty();
Time Complexity: O(1)
Space Complexity: O(1)

Implementation of PriorityQueue

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class PriorityQueue {
private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        if (index <= 0)
            return;

        int parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    const T& top() const {
        return heap.front();
    }

    void push(const T& value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (empty())
            return;

        std::swap(heap.front(), heap.back());
        heap.pop_back();
        heapifyDown(0);
    }
};

int main() {
    PriorityQueue<int> pq;

    // Push elements into the priority queue
    pq.push(5);
    pq.push(2);
    pq.push(10);
    pq.push(1);

    // Print the top element (highest priority)
    std::cout << "Top element: " << pq.top() << std::endl;

    // Pop elements from the priority queue
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

MinHeap:

#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Insert elements into the min heap
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(10);
    minHeap.push(1);

    // Print and remove elements from the min heap
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}

MaxHeap:

#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;

    // Insert elements into the max heap
    maxHeap.push(5);
    maxHeap.push(2);
    maxHeap.push(10);
    maxHeap.push(1);

    // Print and remove elements from the max heap
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    return 0;
}

Using std::make_heap from <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector to store the elements
    std::vector<int> maxHeap = {5, 2, 10, 1};

    // Convert the vector into a max heap
    std::make_heap(maxHeap.begin(), maxHeap.end());

    // Print and remove elements from the max heap
    while (!maxHeap.empty()) {
        std::cout << maxHeap.front() << " ";
        std::pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
    }

    return 0;
}

Implementation of MaxHeap:

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;

    // Helper function to perform heapify operation on a subtree rooted at index i
    void heapify(int i) {
        int largest = i;             // Initialize largest as the root
        int left = 2 * i + 1;        // Index of left child
        int right = 2 * i + 2;       // Index of right child

        // If left child is larger than root
        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        // If right child is larger than current largest
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        // If largest is not the root, swap the elements and heapify the affected subtree
        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Insert an element into the max heap
    void insert(const T& element) {
        heap.push_back(element);
        int index = heap.size() - 1;

        // Fix the heap by moving the inserted element up as necessary
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Remove and return the maximum element from the max heap
    T removeMax() {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");

        T maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        // Fix the heap by heapifying the root
        heapify(0);

        return maxElement;
    }

    // Check if the max heap is empty
    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    // Create a max heap of integers
    MaxHeap<int> maxHeap;

    // Insert elements into the max heap
    maxHeap.insert(5);
    maxHeap.insert(2);
    maxHeap.insert(10);
    maxHeap.insert(1);

    // Print and remove elements from the max heap
    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.removeMax() << " ";
    }

    return 0;
}

Using priority_queue for Min Heap and MaxHeap:

#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Create a min heap using priority_queue (default behavior)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(10);
    minHeap.push(1);

    // Print and remove elements from the min heap (ascending order)
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }

    std::cout << std::endl;

    // Create a max heap using priority_queue with custom comparator
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
    maxHeap.push(5);
    maxHeap.push(2);
    maxHeap.push(10);
    maxHeap.push(1);

    // Print and remove elements from the max heap (descending order)
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    return 0;
}

// Create a priority_queue of strings for lexicographically increasing order
    std::priority_queue<std::string> increasingQueue;

// Create a priority_queue of strings for lexicographically decreasing order
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> decreasingQueue;


Custom class comparator:

Functor:
  #include <iostream>
  #include <queue>
  #include <functional>

  // Custom class
  class MyClass {
  public:
      int priority;
      std::string name;

      // Constructor
      MyClass(int priority, const std::string& name)
          : priority(priority), name(name) {}

      // Functor for comparison
      struct CompareFunctor {
          bool operator()(const MyClass& a, const MyClass& b) const {
              return a.priority > b.priority;
          }
      };
  };

  int main() {
      std::priority_queue<MyClass, std::vector<MyClass>, MyClass::CompareFunctor> pq;
      pq.push(MyClass(2, "John"));
      pq.push(MyClass(1, "Alice"));
      pq.push(MyClass(3, "Bob"));

      while (!pq.empty()) {
          std::cout << pq.top().priority << " - " << pq.top().name << std::endl;
          pq.pop();
      }

      return 0;
  }

Lambda:

  #include <iostream>
  #include <queue>

  // Custom class
  class MyClass {
  public:
      int priority;
      std::string name;

      // Constructor
      MyClass(int priority, const std::string& name)
          : priority(priority), name(name) {}
  };

  int main() {
      auto compareLambda = [](const MyClass& a, const MyClass& b) {
          return a.priority > b.priority;
      };

      std::priority_queue<MyClass, std::vector<MyClass>, decltype(compareLambda)> pq(compareLambda);
      pq.push(MyClass(2, "John"));
      pq.push(MyClass(1, "Alice"));
      pq.push(MyClass(3, "Bob"));

      while (!pq.empty()) {
          std::cout << pq.top().priority << " - " << pq.top().name << std::endl;
          pq.pop();
      }

      return 0;
  }

Operator overloading:

  #include <iostream>
  #include <queue>

  // Custom class
  class MyClass {
  public:
      int priority;
      std::string name;

      // Constructor
      MyClass(int priority, const std::string& name)
          : priority(priority), name(name) {}

      // Overloading less than operator
      bool operator<(const MyClass& other) const {
          return priority < other.priority;
      }
  };

  int main() {
      std::priority_queue<MyClass> pq;
      pq.push(MyClass(2, "John"));
      pq.push(MyClass(1, "Alice"));
      pq.push(MyClass(3, "Bob"));

      while (!pq.empty()) {
          std::cout << pq.top().priority << " - " << pq.top().name << std::endl;
          pq.pop();
      }

      return 0;
  }

Storing vector of elements in priority_queue:

Functor:

  #include <iostream>
  #include <queue>
  #include <vector>

  // Custom functor for comparison
  struct CompareFunctor {
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        return a[1] > b[1]; // Compare based on the second element
    }
  };

  int main() {

     std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, CompareFunctor> pq1;
     pq1.push({1, 10});
     pq1.push({2, 5});
     pq1.push({3, 8});
     pq1.push({4, 2});

     std::cout << "Priority queue using a functor:" << std::endl;
     while (!pq1.empty()) {
         const std::vector<int>& vec = pq1.top();
         std::cout << "(" << vec[0] << ", " << vec[1] << ") ";
         pq1.pop();
     }
     std::cout << std::endl;
  }

Lambda:

  #include <iostream>
  #include <queue>
  #include <vector>

  int main() {
      // Custom comparison function for the priority queue
      auto compare = [](const std::vector<int>& a, const std::vector<int>& b) {
          return a[1] > b[1]; // Compare based on the second element
      };

      // Priority queue to store vectors with custom comparison function
      std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare)> pq(compare);

      // Add vectors to the priority queue
      pq.push({1, 10});
      pq.push({2, 5});
      pq.push({3, 8});
      pq.push({4, 2});

      // Print and remove elements from the priority queue
      while (!pq.empty()) {
          const std::vector<int>& vec = pq.top();
          std::cout << "(" << vec[0] << ", " << vec[1] << ") ";
          pq.pop();
      }

      return 0;
  }

Operator overloading:

  #include <iostream>
  #include <queue>
  #include <vector>

  struct CompareStruct {
       bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
           return a[1] > b[1]; // Compare based on the second element
       }
   };

   int main() {

      std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, CompareStruct> pq3;
      pq3.push({1, 10});
      pq3.push({2, 5});
      pq3.push({3, 8});
      pq3.push({4, 2});

      std::cout << "Priority queue using a custom struct with operator<:" << std::endl;
      while (!pq3.empty()) {
          const std::vector<int>& vec = pq3.top();
          std::cout << "(" << vec[0] << ", " << vec[1] << ") ";
          pq3.pop();
      }
      std::cout << std::endl;
  }
