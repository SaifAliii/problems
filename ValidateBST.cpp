#include<iostream>
#include<vector>
#include<string>
using namespace std;
class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);
};
// Constructor for BST
BST::BST(int val) {
  value = val;
  left = nullptr;
  right = nullptr;
}

// Insert method for BST
BST& BST::insert(int val) {
  if (val < value) {
    if (left == nullptr) {
      left = new BST(val);
      return *left;
    } else {
      return left->insert(val);
    }
  } else {
    if (right == nullptr) {
      right = new BST(val);
      return *right;
    } else {
      return right->insert(val);
    }
  }
}
bool insertInArray(int value, vector<int>* array, string direction)
{
    cout << "Member Function, Value: " << value << "\n";
    array->push_back(value);
    if(array->size() >= 2)
    {

        cout << " More than 2 elements, size: " << array->size() << "; \n";
        cout << "Last element: " << (*array)[array->size() - 1] << endl;
        cout << "Second Last element: " << (*array)[array->size() - 2] << endl;
        if(direction != "right")
        {
            cout << "Called from left or middle\n";
            
            if((*array)[array->size() - 1] > (*array)[array->size() - 2])
            {
                cout << "Condition True return true\n";
                return true;
            }
            else
            {
                cout << "Return False\n";
                return false;
            }
        }
        else
        {
            cout<< "Called from right side\n";
            if((*array)[array->size() - 1] >= (*array)[array->size()-2])
            {
                cout << "Condition True return true\n";
                return true;
            }
            else
            {
                cout << "Condition False return false\n";
                return false;
            }
        }
    }
    cout << "Returning true\n";
    return true;
}
bool validateBstHelper(BST* tree, vector<int>* array, string direction) 
{
    cout << "Helper Function\n";
    bool lStatus = true;
    bool rStatus = true;
    bool mStatus = true;
    if(tree->left == nullptr && tree->right == nullptr)
    {
        cout << "End Node\n";
       return insertInArray(tree->value, array, direction);
    }
    if(tree->left)
    {
        cout << "Moving Left\n";
        lStatus = validateBstHelper(tree->left, array, "left");
    }    
    cout << "Moving Middle\n";
    mStatus = insertInArray(tree->value, array, direction);
    if(tree->right)
    {
        cout << "Moving Right\n";
        rStatus = validateBstHelper(tree->right, array, "right");
    }
    if(lStatus == false || rStatus == false || mStatus == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool validateBst(BST* tree) 
{
    cout << "Parent function\n";
    vector<int> array;
    return validateBstHelper(tree, &array, "middle");
}
int main()
{
    BST tree(5000);
    tree.left = new BST(5);
    tree.left->left = new BST(2);
    tree.left->right = new BST(15);
    tree.left->right->right = new BST(22);
    tree.left->right->left = new BST(5);
   
    cout << validateBst(&tree) << endl;
    
    return 0;
}