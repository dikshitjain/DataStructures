push_back(item): Adds an item to the rear of the deque.
Time complexity: Amortized O(1) (constant time on average). Space complexity: O(1).

push_front(item): Adds an item to the front of the deque.
Time complexity: Amortized O(1) (constant time on average). Space complexity: O(1).

pop_back(): Removes the item from the rear of the deque.
Time complexity: Amortized O(1) (constant time on average). Space complexity: O(1).

pop_front(): Removes the item from the front of the deque.
Time complexity: Amortized O(1) (constant time on average). Space complexity: O(1).

front(): Returns a reference to the item at the front of the deque.
Time complexity: O(1). Space complexity: O(1).

back(): Returns a reference to the item at the rear of the deque.
Time complexity: O(1). Space complexity: O(1).

at(index): Returns a reference to the item at the specified index in the deque.
Time complexity: O(1). Space complexity: O(1).

empty(): Checks if the deque is empty.
Time complexity: O(1). Space complexity: O(1).

size(): Returns the number of elements in the deque.
Time complexity: O(1). Space complexity: O(1).

clear(): Removes all elements from the deque, leaving it with a size of 0.
Time complexity: Linear O(N) in the number of elements. Space complexity: O(1).


#include <iostream>
#include <stdexcept>

template<typename T>
class Deque {
private:
    T* buffer;
    int capacity;
    int frontIndex;
    int rearIndex;
    int size;

public:
    Deque() : capacity(8), frontIndex(0), rearIndex(0), size(0) {
        buffer = new T[capacity];
    }

    ~Deque() {
        delete[] buffer;
    }

    void push_back(const T& item) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        buffer[rearIndex] = item;
        rearIndex = (rearIndex + 1) % capacity;
        size++;
    }

    void push_front(const T& item) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        buffer[frontIndex] = item;
        size++;
    }

    T pop_back() {
        if (size == 0) {
            throw std::runtime_error("Deque is empty");
        }
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        T item = buffer[rearIndex];
        size--;
        if (size <= capacity / 4) {
            resize(capacity / 2);
        }
        return item;
    }

    T pop_front() {
        if (size == 0) {
            throw std::runtime_error("Deque is empty");
        }
        T item = buffer[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        if (size <= capacity / 4) {
            resize(capacity / 2);
        }
        return item;
    }

    T& front() {
        if (size == 0) {
            throw std::runtime_error("Deque is empty");
        }
        return buffer[frontIndex];
    }

    T& back() {
        if (size == 0) {
            throw std::runtime_error("Deque is empty");
        }
        return buffer[(rearIndex - 1 + capacity) % capacity];
    }

    bool empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }

private:
    void resize(int newCapacity) {
        T* newBuffer = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newBuffer[i] = buffer[(frontIndex + i) % capacity];
        }
        delete[] buffer;
        buffer = newBuffer;
        capacity = newCapacity;
        frontIndex = 0;
        rearIndex = size;
    }
};


Using a std::vector for implementing a deque-like data structure is indeed a valid approach.
In fact, the C++ Standard Library (std::deque) itself uses a combination of multiple std::vector segments to implement a deque.

The reason for not using std::vector directly in the provided implementation is to demonstrate an alternative approach that
uses a dynamically allocated buffer as the underlying storage for the deque.
This approach highlights the core concepts of a deque, such as the ability to efficiently insert and remove elements at both ends,
without relying on the more complex structure of a segmented vector.

However, using std::vector as the underlying container for implementing a deque has its advantages.

Some benefits of using std::vector include:

Simplicity: std::vector provides a straightforward and intuitive interface, making the implementation and
usage of a deque-like data structure more concise.
Continuous memory: std::vector guarantees that its elements are stored in contiguous memory, which can improve cache performance
in certain scenarios.
Efficiency: std::vector provides efficient random access and supports operations like insert() and erase() in the middle,
which can be useful in some deque operations.
If you choose to use std::vector for implementing a deque, you can utilize its existing functions like push_back(),
push_front(), pop_back(), pop_front(), and other operations to achieve the desired functionality.

Implemntation using vector


#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Deque {
private:
    std::vector<T> data;

public:
    void push_back(const T& item) {
        data.push_back(item);
    }

    void push_front(const T& item) {
        data.insert(data.begin(), item);
    }

    T pop_back() {
        if (is_empty()) {
            throw std::runtime_error("Deque is empty");
        }
        T item = data.back();
        data.pop_back();
        return item;
    }

    T pop_front() {
        if (is_empty()) {
            throw std::runtime_error("Deque is empty");
        }
        T item = data.front();
        data.erase(data.begin());
        return item;
    }

    T& front() {
        if (is_empty()) {
            throw std::runtime_error("Deque is empty");
        }
        return data.front();
    }

    T& back() {
        if (is_empty()) {
            throw std::runtime_error("Deque is empty");
        }
        return data.back();
    }

    bool is_empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};

Dynamic size: Doubly linked lists allow for efficient resizing and dynamic memory allocation as
elements are added or removed from the deque.

Constant-time insertion and removal: Insertion and removal operations at both ends of a
doubly linked list can be performed in constant time, while arrays/vectors require shifting/moving
elements.

Efficient element removal: Removing elements from a doubly linked list requires updating neighboring
pointers, resulting in more efficient removal compared to arrays/vectors.

Easy reordering of elements: Doubly linked lists allow for easy reordering of elements by changing
pointers, making them useful in scenarios requiring frequent element rearrangement.

Reduced memory overhead: Doubly linked lists offer more efficient memory utilization as they don't
require upfront allocation of a fixed-size buffer like arrays/vectors.

Implemntation using Doubly Linked List

#include <iostream>
#include <stdexcept>

template<typename T>
struct Node {
    T value;
    Node* prev;
    Node* next;

    Node(const T& val) : value(val), prev(nullptr), next(nullptr) {}
};

template<typename T>
class Deque {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Deque() : head(nullptr), tail(nullptr), size(0) {}

    ~Deque() {
        clear();
    }

    void append(const T& item) {
        Node<T>* new_node = new Node<T>(item);
        if (is_empty()) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void appendleft(const T& item) {
        Node<T>* new_node = new Node<T>(item);
        if (is_empty()) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }

    T pop() {
        if (is_empty()) {
            throw std::runtime_error("Deque is empty");
        }
        T item = tail->value;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
        return item;
    }

    T popleft() {
        if (is_empty()) {
            throw std::runtime_error("Deque is empty");
        }
        T item = head->value;
        Node<T>* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
        return item;
    }

    bool is_empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};
