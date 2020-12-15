#include "LinkedList.h"



int main(){
    LinkedList list; 
    LinkedList list2;
    list.push_back(1);
    list.printList();

    list.push_back(2);
    list.push_back(3);
    list.push_back(12);
    cout << "Max length " << list.length_max_decreasing() <<endl;
    list.push_back(1);
    list.push_back(23);
    list.push_back(12);
    list.push_back(231);
    list.push_back(23);
    cout << "Remove duplicates ";
    list.remove_duplicates();
    cout << list.contains(1) << endl;
    list.remove(2);
    list.printList();
    list2 = list;
    cout << list.find_last_of(23) << endl;
    list.printList(); 
    list2.printList();
    cout << list.length_max_decreasing() << endl;
    LinkedList a; 
    a.push_back(2);
    a.head(); 
    a.size(); 
    a.push_back(4);
    a.push_back(12);
    cout << "Last of " << a.find_last_of(123124) << endl;
    LinkedList b(a);
    b.printList(); 
    return 0; 
}