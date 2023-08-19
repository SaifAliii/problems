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
    LinkedList *head = linkedList;
    LinkedList *ptr;
    bool status = true;
    if(linkedList == nullptr)
    {
        return nullptr;
    }
    if(linkedList->next == nullptr)
    {
        return linkedList;
    }
    while(linkedList->next->next != nullptr)
    {
        while(status && linkedList->value == linkedList->next->value)
        {
            ptr = linkedList->next;
            linkedList->next = linkedList->next->next;
            delete[] ptr;
            ptr = nullptr;
            if(linkedList->next == nullptr || linkedList->next->next == nullptr)
            {
                status = false;
            }
        }
        if(status == false)
        {
            break;
        }
        linkedList = linkedList->next;
    }
    while(linkedList != nullptr && linkedList->next != nullptr)
    {
        if(linkedList->value == linkedList->next->value)
        {
            delete [] linkedList->next;
            linkedList->next = nullptr;
        }
        linkedList = linkedList->next;
    }
    return head;
}
int main()
{
    LinkedList *list = new LinkedList(1);
    list->next->next = new LinkedList(3);
    list->next->next->next = new LinkedList(4);
    list->next->next->next->next = new LinkedList(4);
    list->next->next->next->next->next = new LinkedList(4);
    list->next->next->next->next->next->next = new LinkedList(5);
    list->next->next->next->next->next->next->next = new LinkedList(6);
    list->next->next->next->next->next->next->next->next = new LinkedList(6);
    list->next->next->next->next->next->next->next->next->next = new LinkedList(6);
    list->next->next->next->next->next->next->next->next->next->next = new LinkedList(6);
    cout << "Before Removing Duplicates\n";
    LinkedList *list1 = list;
    cout << "HI\n";
    list = removeDuplicatesFromLinkedList(list1);
    cout << "\nAfter Removing Duplicates\n";
    while(list != nullptr)
    {
        cout << list->value << " ";
        list = list->next;
    }
    return 0;
}