Implementation of Deque

#include <iostream>
#include <memory>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> prev;
    std::shared_ptr<Node<T>> next;

    Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertFront(const T& value) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertBack(const T& value) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeFront() {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        std::shared_ptr<Node<T>> temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
    }

    void removeBack() {
        if (isEmpty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        std::shared_ptr<Node<T>> temp = tail;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
    }

    void printList() {
        std::shared_ptr<Node<T>> current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};


DoublyLinkedList vs Deque

A doubly linked list and a deque (double-ended queue) are two different data structures, but they share some similarities.
Here are the key differences between a doubly linked list and a deque:

Structure and Access:

Doubly Linked List: A doubly linked list is a linear data structure where each node contains a value and two pointers:
one pointing to the previous node and another pointing to the next node. It allows traversal in both directions
(forward and backward) and provides efficient insertion and deletion operations at any position within the list.
Deque: A deque, on the other hand, is a generalized queue that allows insertion and deletion at both ends (front and rear).
It does not support random access or direct traversal to a specific position within the deque like a linked list does.
Operations:

Doubly Linked List: A doubly linked list supports various operations such as insertion and deletion at the front, rear,
or any arbitrary position. It also allows traversal in both directions.
Deque: A deque supports operations like push (insertion) and pop (deletion) at both ends. It offers constant-time
complexity (O(1)) for these operations, making it efficient for scenarios where elements need to be added or removed
from both ends.

Flexibility:

Doubly Linked List: A doubly linked list is more flexible and can handle operations like insertion and deletion at any position
within the list. It is suitable when you need to frequently modify the structure by adding or removing elements from arbitrary
positions.
Deque: A deque is more focused on providing efficient insertion and deletion at both ends. It is particularly useful when you
need to implement data structures like stacks or queues where elements are inserted and removed from the front or rear.

Memory Overhead:

Doubly Linked List: A doubly linked list has a higher memory overhead compared to a deque because each node needs to store
two additional pointers (previous and next).
Deque: A deque has a lower memory overhead compared to a doubly linked list because it does not require storing additional
pointers for traversal.
In summary, a doubly linked list is a linear data structure that allows insertion and deletion at any position with bidirectional
traversal, while a deque is a generalized queue that supports insertion and deletion at both ends with efficient constant-time
operations. The choice between the two depends on the specific requirements of your use case, such as the need for random access,
flexibility in modifying the structure, and the performance characteristics required for specific operations.
