#include<iostream>
#include <vector>
#include<string>
#include<queue>
using namespace std;


// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
    string name;
    vector<Node*> children;

    Node(string str) { name = str; }
    vector<string> breadthFirstSearch(vector<string>* array) 
    {
        cout << "function Called\n";
        queue<Node*> elements;
        Node *temp;
        elements.push(this);
        while(!elements.empty())
        {
            cout << "Condition true\n";
            temp = elements.front();
            cout << "temp->name: " << temp->name << " size: " << temp->children.size() << " \n";
            elements.pop();
            for(int i = 0; i < temp->children.size(); i++)
            {
                cout << "Adding childs i: " << i << "\n";
                elements.push(temp->children[i]);
            }
            array->push_back(temp->name);
        }
        return *array;
    }

    Node* addChild(string name) {
        Node* child = new Node(name);
        children.push_back(child);
        return this;
    }
};
int main()
{
    Node * p;
    p->name = "A";
    p->addChild("B");
    p->addChild("C");
    p->addChild("D");
    p->children[0]->addChild("E");
    p->children[0]->addChild("F");
    p->children[2]->addChild("G");
    p->children[2]->addChild("H");
    p->children[0]->children[1]->addChild("I");
    p->children[0]->children[1]->addChild("J");
    p->children[2]->children[0]->addChild("K");
    vector<string> array;
    array = p->breadthFirstSearch(&array);
    for(int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
    return 0;
}