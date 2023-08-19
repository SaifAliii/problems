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
    cout << "\nfunction called\n";
    LinkedList *head = linkedList;
    LinkedList *ptr;
    cout << "Dont know\n";
    cout << "\n";
    while(linkedList->next->next != nullptr)
    {
        cout << "Loop\n";
        if(linkedList->value == linkedList->next->value)
        {
            cout << "value matched\n";
            ptr = linkedList->next;
            linkedList->next = linkedList->next->next;
            delete[] ptr;
            ptr = nullptr;
        }
        linkedList = linkedList->next;
    }
    return head;
}
int main()
{
    LinkedList *list = new LinkedList(1);
    list->next = new LinkedList(1);
    list->next->next = new LinkedList(3);
    list->next->next->next = new LinkedList(4);
    list->next->next->next->next = new LinkedList(4);
    list->next->next->next->next->next = new LinkedList(4);
    list->next->next->next->next->next->next = new LinkedList(5);
    list->next->next->next->next->next->next->next = new LinkedList(6);
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