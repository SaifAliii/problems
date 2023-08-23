#include<iostream>
#include <vector>
#include<string>
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
    void getAllChilds(vector<string> * childs)
    {
        for(const auto& el: children)
        {
            childs->push_back(el->name);
        }
        for(const auto& el: children)
        {
            el->getAllChilds(childs);
        }

    }
    vector<string> breadthFirstSearch(vector<string>* array) 
    {
        getAllChilds(array);
        for(int i = 0; i < array->size(); i++)
        {
            cout << (*array)[i] << endl;

        }
        return (*array);
    }

    Node* addChild(string name) {
        Node* child = new Node(name);
        children.push_back(child);
        return this;
    }
};