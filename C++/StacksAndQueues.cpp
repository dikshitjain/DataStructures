
In the C++ Standard Library (STL), the underlying data structure used for std::stack and std::queue is typically
a std::deque (double-ended queue). However, it's worth noting that the choice of the underlying data structure
may vary depending on the STL implementation and the compiler used.

By default, std::stack and std::queue are implemented on top of a std::deque, which provides efficient insertion and removal
at both ends. The use of std::deque allows for constant-time complexity (O(1)) for push, pop, enqueue, and dequeue operations.

It's important to mention that you can also specify a different underlying container for std::stack and std::queue by providing
an allocator parameter. For example, you can use a std::vector as the underlying container for std::stack or std::list for
std::queue if the specific requirements of your use case make these choices more suitable.

In summary, the default underlying data structure for std::stack and std::queue in the STL is a std::deque,
but it's possible to use other containers as well, depending on the requirements and desired performance characteristics.

#include <vector>
#include <stack>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};

    // Use std::vector as the underlying container for std::stack
    std::stack<int, std::vector<int>> myStack(data);

    // Perform stack operations
    myStack.push(6);
    int topElement = myStack.top();
    myStack.pop();

    return 0;
}


#include <list>
#include <queue>

int main() {
    std::list<int> data = {1, 2, 3, 4, 5};

    // Use std::list as the underlying container for std::queue
    std::queue<int, std::list<int>> myQueue(data);

    // Perform queue operations
    myQueue.push(6);
    int frontElement = myQueue.front();
    myQueue.pop();

    return 0;
}


Stack and Queue STLs:

Stack:

push(item): Adds an item to the top of the stack (push operation). Time complexity: O(1). Space complexity: O(1).
pop(): Removes and returns the item from the top of the stack (pop operation). Time complexity: O(1). Space complexity: O(1).
top(): Returns the item at the top of the stack without removing it (top operation). Time complexity: O(1). Space complexity: O(1).
empty(): Checks if the stack is empty. Time complexity: O(1). Space complexity: O(1).
size(): Returns the number of elements in the stack. Time complexity: O(1). Space complexity: O(1).

Queue:

push(item): Adds an item to the rear of the queue (enqueue operation). Time complexity: O(1). Space complexity: O(1).
pop(): Removes and returns the item from the front of the queue (dequeue operation). Time complexity: O(1). Space complexity: O(1).
front(): Returns the item at the front of the queue without removing it (front operation). Time complexity: O(1). Space complexity: O(1).
empty(): Checks if the queue is empty. Time complexity: O(1). Space complexity: O(1).
size(): Returns the number of elements in the queue. Time complexity: O(1). Space complexity: O(1).

Sstack implementation:

#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int item) {
        data.push_back(item);
    }

    int pop() {
        if (!is_empty()) {
            int item = data.back();
            data.pop_back();
            return item;
        } else {
            std::cout << "Stack is empty." << std::endl;
            return -1;  // Return a default value indicating failure
        }
    }

    int top() {
        if (!is_empty()) {
            return data.back();
        } else {
            std::cout << "Stack is empty." << std::endl;
            return -1;  // Return a default value indicating failure
        }
    }

    bool is_empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};

Queue Implementation:

#include <iostream>
#include <deque>

class Queue {
private:
    std::deque<int> data;

public:
    void enqueue(int item) {
        data.push_back(item);
    }

    int dequeue() {
        if (!is_empty()) {
            int item = data.front();
            data.pop_front();
            return item;
        } else {
            std::cout << "Queue is empty." << std::endl;
            return -1;  // Return a default value indicating failure
        }
    }

    int front() {
        if (!is_empty()) {
            return data.front();
        } else {
            std::cout << "Queue is empty." << std::endl;
            return -1;  // Return a default value indicating failure
        }
    }

    bool is_empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};
