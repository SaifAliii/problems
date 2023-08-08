#include<iostream>
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
int findClosestValueInBst(BST* tree, int target) {
  if(tree == nullptr)
  {
    return -1;
  }
  if(tree->left == nullptr && tree->right == nullptr)
  {
    return tree->value;
  }
  int match = INT32_MAX;
  while(tree->left != nullptr || tree->right != nullptr)
  {
    if(target < tree->value && tree->left != nullptr)
    {
        if(target > tree->value)
        {
            if(target - tree->value < match)
            {
                match = target-tree->value;
            }
        }
        if(target < 0 && tree->value < 0 )
        {
            if(tree->value - target < match)
            {
                match = tree->value - target;
            }
        }
        cout << "Left side\n";
      tree = tree->left;
      
      cout << "Left side tree value: " << tree->value <<endl;
    }
    else if(target > tree->value && tree->right != nullptr)
    {
        cout << "Right Side\n";
      tree = tree->right;
      cout << "Right side Tree value: " << tree->value << endl;
    }
    else
    {
        cout << "Equal value\n";
      return tree->value;
    }
  }
  // Write your code here.
  return tree->value;
}

int main()
{
    BST tree(100);
    tree.insert(502);
    tree.insert(55000);
    tree.insert(1001);
    tree.insert(4500);
    tree.insert(204);
    tree.insert(205);
    tree.insert(207);
    tree.insert(208);
    tree.insert(206);
    tree.insert(203);
    tree.insert(5);
    tree.insert(15);
    tree.insert(22);
    tree.insert(57);
    tree.insert(60);
    tree.insert(5);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.insert(1);
    tree.insert(-51);
    tree.insert(-403);
    cout << "The Closest Value in BST is: " << findClosestValueInBst(&tree, 208);
}