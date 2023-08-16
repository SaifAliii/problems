#include<iostream>
#include<string>
#include <vector>
using namespace std;
// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
 public:
  string name;
  vector<Node*> children;

  Node(string str) { name = str; }

    vector<string> depthFirstSearchHelper(vector<string> array) 
    {
        array.push_back(this->name);
        cout << this->name << endl;
        for(int i = 0; i < children.size(); i++)
        {   
            array = children[i]->depthFirstSearchHelper(array);
        }
        return array;
    }

    vector<string> depthFirstSearch(vector<string>* array) 
    {
        return depthFirstSearchHelper(*array);
    }

  Node* addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
  }
};