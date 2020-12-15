#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>

using std::cout, std::endl, std::size_t, std::string, std::cin;
struct Node {
    Node(int data);

    int data;


    Node* next;

    Node* _next();
    void setNext(Node* other);

// TODON'T(student): change the visibility, types, or names of the members
// TOMAYBE(student): the optional-rest of the Node
};

class LinkedList {
    private: 
        size_t _size; 

        Node* headPtr;

        Node* tailPtr;

        Node* prevPtr;

        Node* current;

    public:
        LinkedList();
        //rule of three

        LinkedList(const LinkedList& other);
        //     my_string copy assignment
        LinkedList& operator=(const LinkedList& rhs);
         //     destructor
        ~LinkedList();

        size_t size() const;
        
        const Node* head() const;
        
        void clear(); 

        void push_back(int value);
        // extra credit
        bool contains(int value) const;
        
        std::size_t find_last_of(int value) const;

        void remove(std::size_t index);
        ///////////////////
        void remove_duplicates();
        
        size_t length_max_decreasing() const;

        void printList();

// the type to use for sizes and indices is size_t.
// TODO(student): the rest of the LinkedList
};

#endif  // LINKEDLIST_H