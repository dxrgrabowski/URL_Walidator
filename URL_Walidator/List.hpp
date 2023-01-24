#pragma once

#include <iostream>
#include <memory>

template <typename T>
class DoublyLinkedList {
public:
    // Default constructor
    DoublyLinkedList();

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList& rhs);

    // Move constructor
    DoublyLinkedList(DoublyLinkedList&& rhs) noexcept;

    // Destructor
    ~DoublyLinkedList();

    // Assignment operator
    DoublyLinkedList& operator=(const DoublyLinkedList& rhs);

    // Move assignment operator
    DoublyLinkedList& operator=(DoublyLinkedList&& rhs) noexcept;

    // Add element to list
    void add(const T& element);

    // Search for an item in the list
    bool search(const T& element) const;

    // Sort the contents of the list
    void sort();
    // Iterate the contents of the list
    void iterate();

private:
    struct Node {
        Node(const T& element) : element(element) {}
        T element;
        std::unique_ptr<Node> previous;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;
    std::unique_ptr<Node> tail;
    size_t size;
};

// No-argument constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {
}

// Copy constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& rhs) : head(nullptr), tail(nullptr), size(0) {
    Node* node = rhs.head.get();
    while (node) {
        add(node->element);
        node = node->next.get();
    }
}

// Move constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList&& rhs) noexcept
    : head(std::move(rhs.head)), tail(std::move(rhs.tail)), size(rhs.size) {
    rhs.tail = nullptr;
    rhs.head = nullptr;
    rhs.size = 0;
}

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node* node = head.get();
    while (node) {
        Node* next = node->next.get();
        delete node;
        node = next;
    }
}

// Assignment operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& rhs) {
    if (this != &rhs) {
        DoublyLinkedList<T> temp(rhs);
        std::swap(head, temp.head);
        std::swap(tail, temp.tail);
        std::swap(size, temp.size);
    }
    return *this;
}

// Move operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList&& rhs) noexcept {
    if (this != &rhs) {
        head = std::move(rhs.head);
        tail = std::move(rhs.tail);
        size = rhs.size;
        rhs.tail = nullptr;
        rhs.head = nullptr;
        rhs.size = 0;
    }
    return *this;
}
// Add an item to the list
template <typename T>
void DoublyLinkedList<T>::add(const T& element) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(element);
    if (tail) {
        newNode->previous = std::move(tail);
        tail->next = std::move(newNode);
        tail = std::move(newNode);
    }
    else {
        head = std::move(newNode);
        tail = std::move(head);
    }
    ++size;
}


// Search for an item in the list
template <typename T>
bool DoublyLinkedList<T>::search(const T& element) const {
    Node* node = head.get();
    while (node) {
        if (node->element == element) {
            return true;
        }
        node = node->next.get();
    }
    return false;
}

// Sort the contents of the list
template <typename T>
void DoublyLinkedList<T>::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        Node* minNode = head.get();
        Node* node = minNode->next.get();
        while (node) {
            if (node->element < minNode->element) {
                minNode = node;
            }
            node = node->next.get();
        }
        if (minNode != head.get()) {
            std::swap(minNode->element, head.get()->element);
        }
        head = std::move(head.get()->next);
    }
}

template <typename T>
void DoublyLinkedList<T>::iterate() {
    Node* node = head.get();
    while (node) {
        
        for (auto& s : node->element) {
            std::cout << s << std::endl;
        }

        node = node->next.get();
    }
}