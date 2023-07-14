Node Structure:

    Definition of the Node structure or class that represents a node in the linked list.
    Typically, a Node contains a data element and a pointer/reference to the next node in the list.

Linked List Operations:

    __init__(): Initializes the linked list.
                Time complexity: O(1). Space complexity: O(1).
    insert_front(value): Inserts a new node with the given value at the front of the linked list.
                         Time complexity: O(1). Space complexity: O(1).
    insert_end(value): Inserts a new node with the given value at the end of the linked list.
                       Time complexity: O(n), where n is the number of nodes in the list. Space complexity: O(1).
    insert_after(node, value): Inserts a new node with the given value after the specified node in the linked list.
                               Time complexity: O(1). Space complexity: O(1).
    delete_node(node): Removes the specified node from the linked list.
                       Time complexity: O(n), where n is the number of nodes in the list. Space complexity: O(1).
    delete_value(value): Removes the first occurrence of the specified value from the linked list.
                         Time complexity: O(n), where n is the number of nodes in the list. Space complexity: O(1).
    clear(): Clears the entire linked list, deallocating memory.
             Time complexity: O(n), where n is the number of nodes in the list. Space complexity: O(1).
    is_empty(): Checks if the linked list is empty.
                Time complexity: O(1). Space complexity: O(1).
    size(): Returns the number of nodes in the linked list.
            Time complexity: O(n), where n is the number of nodes in the list. Space complexity: O(1).

Traversal and Printing:

print_list(): Prints the elements of the linked list.
              Time complexity: O(n), where n is the number of nodes in the list. Space complexity: O(1).
reverse_print_list(): Prints the elements of the linked list in reverse order.
                      Time complexity: O(n), where n is the number of nodes in the list. Space complexity: O(1).

Searching:

search(value): Searches for the first occurrence of the specified value in the linked list and returns the
               corresponding node or None if not found.
               Time complexity: O(n), where n is the number of nodes in the list. Space complexity: O(1).

Miscellaneous:

get_head(): Returns the head node of the linked list.
            Time complexity: O(1). Space complexity: O(1).
get_node_value(node): Returns the value stored in the specified node.
                      Time complexity: O(1). Space complexity: O(1).
get_next_node(node): Returns the next node after the specified node.
                     Time complexity: O(1). Space complexity: O(1).


Example code:

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_front(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node

    def insert_end(self, value):
        new_node = Node(value)

        if self.head is None:
            self.head = new_node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = new_node

    def print_list(self):
        current = self.head
        while current is not None:
            print(current.data, end=" ")
            current = current.next
        print()

# Example usage
linked_list = LinkedList()

# Insert nodes
linked_list.insert_end(10)
linked_list.insert_front(5)
linked_list.insert_end(20)

# Print the list
linked_list.print_list()
