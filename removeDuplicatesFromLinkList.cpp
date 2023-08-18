#include<iostream>
using namespace std;
class LinkedList {
public:
    int value;
    LinkedList* next = nullptr;
    LinkedList(int value) { this->value = value; }
};
LinkedList* removeDuplicatesFromLinkedList(LinkedList* linkedList) 
{
    LinkedList *ptr;
    while(linkedList->next->next != nullptr)
    {
        if(linkedList->value == linkedList->next->value)
        {
            ptr = linkedList->next;
            delete[] ptr;
            linkedList->next = linkedList->next->next;
        }
        linkedList = linkedList->next;
    }
    return linkedList;
}
int main()
{
    return 0;
}