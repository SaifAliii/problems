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
    array->push_back(value);
    if(array->size() >= 2)
    {
        if(direction != "right")
        {
            
            if((*array)[array->size() - 1] > (*array)[array->size() - 2])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if((*array)[array->size() - 1] >= (*array)[array->size()-2])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
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
        return insertInArray(tree->value, array, direction);
    }
    if(tree->left)
    {
        lStatus = validateBstHelper(tree->left, array, direction);
        if(lStatus == false)
        {
            return false;
        }
    }    
    mStatus = insertInArray(tree->value, array, direction);
    if(mStatus == false)
    {
        return false;
    }
    if(tree->right)
    {
        direction = "right";
        rStatus = validateBstHelper(tree->right, array, direction);
        if(rStatus == false)
        {
            return false;
        }
    }
    return true;
}
bool validateBst(BST* tree) 
{
    cout << "Parent function\n";
    vector<int> array;
    return validateBstHelper(tree, &array, "left");
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