#include <iostream>

// Node class to represent each element in the list
class Node {
public:
    int data;      // Data held by the node
    Node* next;    // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {} // Constructor to initialize data
};

// LinkedList class to manage nodes
class LinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    LinkedList() : head(nullptr) {} // Constructor to initialize an empty list

    // Function to insert a new node at the head of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = head; // Point new node to the current head
        head = newNode; // Update head to point to the new node
    }

    // Function to insert a new node at the tail of the list
    void insertAtTail(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (head == nullptr) { // If the list is empty
            head = newNode; // Set head to the new node
            return;
        }
        Node* current = head; // Start at the head
        while (current->next != nullptr) { // Traverse to the last node
            current = current->next;
        }
        current->next = newNode; // Set last node's next to the new node
    }

    // Function to display the list
    void display() {
        Node* current = head; // Start at the head
        while (current != nullptr) { // Traverse the list
            std::cout << current->data << " -> "; // Print the current node's data
            current = current->next; // Move to the next node
        }
        std::cout << "nullptr" << std::endl; // End of the list
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head; // Start at the head
        while (current != nullptr) { // Traverse the list
            Node* temp = current; // Store the current node
            current = current->next; // Move to the next node
            delete temp; // Delete the stored node
        }
    }
};

// Main function to demonstrate the LinkedList
int main() {
    LinkedList list;
    list.insertAtHead(1); // Insert 1 at the head
    list.insertAtHead(2); // Insert 2 at the head
    list.insertAtTail(3); // Insert 3 at the tail
    list.insertAtTail(4); // Insert 4 at the tail

    list.display(); // Display the list: Should output 2 -> 1 -> 3 -> 4 -> nullptr
    return 0;
}