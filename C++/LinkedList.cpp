Node Structure:

  Definition of the Node structure or class that represents a node in the linked list.
  Typically, a Node contains a data element and a pointer/reference to the next node in the list.

List Operations:

  insertFront(value): O(1) time complexity. It takes constant time to insert a new node at the front of the linked list.
                      Space complexity is O(1).
  insertEnd(value): O(n) time complexity in the worst case, where n is the number of nodes in the list.
                    It requires traversing the entire list to insert the new node at the end. Space complexity is O(1).
  insertAfter(node, value): O(1) time complexity. It takes constant time to insert a new node after the specified node.
                            Space complexity is O(1).
  deleteNode(node): O(n) time complexity in the worst case, where n is the number of nodes in the list.
                    It requires traversing the list to find the specified node to delete. Space complexity is O(1).
  deleteValue(value): O(n) time complexity in the worst case, where n is the number of nodes in the list.
                      It requires traversing the list to find the first occurrence of the specified value to delete.
                      Space complexity is O(1).
  clear(): O(n) time complexity, as it needs to deallocate memory for each node in the list. Space complexity is O(1).
  isEmpty(): O(1) time complexity. It simply checks if the head pointer is nullptr. Space complexity is O(1).
  size(): O(n) time complexity, as it needs to traverse the list to count the number of nodes. Space complexity is O(1).

Traversal and Printing:

  printList(): O(n) time complexity, as it traverses the list to print each element. Space complexity is O(1).
  reversePrintList(): O(n) time complexity, as it traverses the list in reverse order to print each element.
                      Space complexity is O(1).

Searching:

  search(value): O(n) time complexity in the worst case, where n is the number of nodes in the list.
                 It requires traversing the list to find the first occurrence of the specified value.
                 Space complexity is O(1).

Miscellaneous:

getHead(): O(1) time complexity. It simply returns the head pointer. Space complexity is O(1).
getNodeValue(node): O(1) time complexity. It retrieves the value stored in the specified node. Space complexity is O(1).
getNextNode(node): O(1) time complexity. It retrieves the next node after the specified node. Space complexity is O(1).


#include <iostream>

// Node structure for linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the front of the list
    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Print the elements of the linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    // Insert nodes
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertFront(5);

    // Print the list
    list.printList();

    return 0;
}


forward_list

  Construction:

    std::forward_list<T>: Creates an empty forward list of type T. Time complexity: O(1). Space complexity: O(1).
    std::forward_list<T> forward_list(iter_begin, iter_end): Creates a forward list with elements from the specified range.
                                                             Time complexity: O(n), where n is the number of elements
                                                             in the range. Space complexity: O(n).
  Iteration and Access:

    begin(), end(): Returns iterators pointing to the beginning and end of the forward list.
                    Time complexity: O(1). Space complexity: O(1).
    cbegin(), cend(): Returns constant iterators pointing to the beginning and end of the forward list.
                      Time complexity: O(1). Space complexity: O(1).
    front(): Returns a reference to the first element in the forward list.
             Time complexity: O(1). Space complexity: O(1).

  Capacity:

    empty(): Checks if the forward list is empty. Time complexity: O(1). Space complexity: O(1).

  Element Insertion:

    push_front(value): Inserts a new element with the given value at the beginning of the forward list.
                       Time complexity: O(1). Space complexity: O(1).

  Element Deletion:

    pop_front(): Removes the first element from the forward list. Time complexity: O(1). Space complexity: O(1).

  Iterators:

    insert_after(pos, value): Inserts a new element with the given value after the element pointed to by pos.
                              Time complexity: O(1). Space complexity: O(1).
    erase_after(pos): Removes the element after the element pointed to by pos.
                      Time complexity: O(1). Space complexity: O(1).

  List Modification:

    merge(other): Merges the elements from another forward list other into the current forward list,
                  assuming both lists are already sorted.
                  Time complexity: O(n+m), where n and m are the sizes of the two lists. Space complexity: O(1).
    remove(value): Removes all elements with the given value from the forward list.
                   Time complexity: O(n), where n is the number of elements in the forward list. Space complexity: O(1).
    reverse(): Reverses the order of the elements in the forward list.
               Time complexity: O(n), where n is the number of elements in the forward list. Space complexity: O(1).

  List Operations:

    splice_after(pos, other): Moves all elements from the forward list other after the element pointed to by pos.
                              Time complexity: O(1). Space complexity: O(1).
    sort(): Sorts the elements in the forward list in ascending order using the default comparison operator.
            Time complexity: O(n log n), where n is the number of elements in the forward list. Space complexity: O(log n).
