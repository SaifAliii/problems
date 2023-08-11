#include<iostream>
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
using namespace std;
int findClosestValueInBst(BST* tree, int target) {
    if(tree==nullptr)
    {
        return -1;
    }
    if(tree->left == nullptr && tree->right == nullptr)
    {
        return tree->value;
    }
    int difference = INT16_MAX;
    int possible;
    while(tree->left != nullptr || tree->right != nullptr)
    {
        if(target < tree->value && tree->left != nullptr)
        {
            if(tree->value - target < difference)
            {
                difference = tree->value-target;
                possible = tree->value;
                cout << "possible: " << possible << endl;
            }
            tree = tree->left;
            cout << "Left Side Value: " << tree->value << "\n";
        }
        else if(target > tree->value && tree->right != nullptr)
        {
            if(target - tree->value < difference)
            {
                difference = target - tree->value;
                possible = tree->value;
            }
            tree = tree->right;
        }
        else
        {
            break;
        }
    }
    if(tree->value >= target)
    {
         if(tree->value - target < difference)
            {
                return tree->value;
        }
          
        
    }
    else
    {
        if(target - tree->value < difference)
        {
            return tree->value;
        }
    }
    return possible;
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
    int target = 2000;
    cout << "The Closest Value to target: " << target <<  " in BST is: " << findClosestValueInBst(&tree, target);
}