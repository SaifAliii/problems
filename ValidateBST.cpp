#include<iostream>
#include<climits> 
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
bool validateBstHelper(BST* tree, int min, int max) 
{
    if(tree->value < min || tree->value >= max)
    {
        return false;
    }
    if(tree->left != nullptr && !validateBstHelper(tree->left, min, tree->value))
    {
        return false;
    }
    if(tree->right != nullptr && !validateBstHelper(tree->right, tree->value, max))
    {
        return false;
    }
    return true;
}
bool validateBst(BST* tree) 
{
    return validateBstHelper(tree, INT_MIN, INT_MAX);
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