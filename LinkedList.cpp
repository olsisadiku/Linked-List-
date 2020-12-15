#include "LinkedList.h"



Node::Node(int data) : data(data), next(nullptr)
{
}

LinkedList :: LinkedList() : _size(0) , headPtr(nullptr), tailPtr(nullptr), prevPtr(nullptr),  current(nullptr)    
{
    
}

size_t LinkedList :: size() const
{
    return _size; 
}

const Node* LinkedList::head() const 
{
    if(_size == 0){
        return nullptr; 
    }
    return headPtr;
}

// RULE OF THREE
LinkedList::LinkedList(const LinkedList& other): _size(0), headPtr(nullptr), tailPtr(nullptr), prevPtr(nullptr), current(nullptr)
{
    Node* other_curr = other.headPtr;
    while(other_curr != nullptr){
        int datas = other_curr->data;
        this->push_back(datas);
        other_curr = other_curr->next;


    }

}
        //     my_string copy assignment
LinkedList& LinkedList::operator=(const LinkedList& rhs){
    current = tailPtr;
    Node* rhs_current = rhs.headPtr; 

    if(this != &rhs){
        while(this->headPtr != nullptr){
        this->current = this->headPtr;
        this->headPtr = this->headPtr->_next();
        delete this->current;
        }
        this->headPtr = nullptr;
        this->current = nullptr;
        this->tailPtr = nullptr;
        this->_size = 0;
        for(size_t i = 0; i < rhs._size; i++){
            this->push_back(rhs_current->data);
            
            
            rhs_current = rhs_current->next;
        }
    }

    return *this;
}
         //     destructor
LinkedList::~LinkedList(){
    while(headPtr != nullptr){
        current = headPtr;
        headPtr = headPtr->_next();
        delete current;
    }
    headPtr = nullptr;
    current = nullptr;
    tailPtr = nullptr;
    _size = 0;
}

    
/////////////


void LinkedList::push_back(int value){
    Node* a = new Node(value);
    if(_size == 0){
        headPtr = a; 
        tailPtr = a;
        a->setNext(nullptr);
        _size++;
    }
    else{

        tailPtr->setNext(a);
        tailPtr = a;
        a->setNext(nullptr);
        _size++;
    }
}



void Node::setNext(Node* other){
    next = other;
}

Node* Node::_next() {
    return next;
}

void LinkedList::remove_duplicates() {
    
    if(_size == 1){
        return; 
    }
    else if(_size == 2){
        current = headPtr;
        prevPtr = nullptr; 
        if(headPtr->data == tailPtr->data){

            // prevPtr = current;
            // current = current->next;
            // current->setNext(current->next);
            headPtr->next = tailPtr->next;
            delete tailPtr;
            _size--;
            return;
        }
        else { 
            return; 
        }
    }
    else{
        Node* copy; 
        Node* run; 
        current = headPtr;
        prevPtr = nullptr; 
        copy = current;

        while(current != nullptr ){
            while(current->next != nullptr ){
                if(copy->data == current->next->data){
                    run = current->next;
                    prevPtr = current; 
                    current->next = current->next->next;
                    _size--;
                    delete run;  
                }
                else{
                    current = current->next;
                }
            }
            prevPtr = copy;
            copy = copy->next;
            current = copy; 

        }
        return; 
}
}

size_t LinkedList::length_max_decreasing() const 
{
    if(_size == 0){
        return 0; 
    }
    Node* curr = headPtr; 
    size_t cnt = 1;
    size_t holder = 1;
    while(curr != nullptr && curr->next != nullptr){
        int first_num = curr->data;
        if(first_num > curr->next->data){
            cnt++;
            
        }
        else{ 
            cnt = 1;
        }
        if(cnt > holder){
            holder = cnt; 
        }
        curr = curr->next;
    }
    return holder; 
}

// extra credit
bool LinkedList::contains(int value) const{
        Node* currentt = headPtr;
        while(currentt != nullptr){
            if(currentt->data == value){
                return true;
            }
            currentt = currentt->next;
        }
        return false; 
}
        
std::size_t LinkedList::find_last_of(int value) const{
        size_t holder =0;
        size_t cnt = 0; 
        Node* currentt = headPtr;
        bool found = false; 
        while(currentt != nullptr){
            if(currentt->data == value){
                found = true; 
                if(cnt > holder){
                    holder = cnt; 
                }
            }
            currentt = currentt->next;
            cnt++;
        }
        if(!found){
            return static_cast<std::size_t>(-1);
        }
        else{
        return holder; 
    }
}
void LinkedList::remove(std::size_t index)
{   
    if(index >= _size){
        throw(std::out_of_range("out of range"));
    }

    if(_size == 1 && index == 0 ){
        delete headPtr;
        headPtr = nullptr; 
        return;
    }
    current = headPtr;
    prevPtr = nullptr;
    if(index == 0){
        Node* temp; 
        temp = headPtr;
        headPtr = headPtr->next;
        delete temp; 
    }
    else{
    for(size_t i = 0; i < _size; i++){
        if(i == index-1){
            Node* temp; 
            temp = current->next; 
            current->next = current->next->next; 
            delete temp; 

        }
        else{
        prevPtr = current; 
        current = current->next;
            }
        }
    }
    _size--;
}


//////////////////////

void LinkedList::printList() {
    current = headPtr;
    if (current == nullptr) {
        cout << "empty" << endl;
        return;
    }

    while (current != nullptr) {
        cout << current->data << ", "; 
        current = current->_next();
    }
    cout << endl; 
}
