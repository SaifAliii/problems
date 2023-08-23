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
bool validateBstHelper(BST* tree, int value) 
{
    bool lStatus;
    bool rStatus;
    if(tree->left)
    {
        if(value > tree->left->value && tree->value > tree->left->value)
        {
            lStatus = validateBstHelper(tree->left, value);
        }
        else
        {
            return false;
        }
    }    
    if(tree->right)
    {
        if(value <= tree->right->value && tree->value <= tree->right->value)
        {
            rStatus = validateBstHelper(tree->right, value);
        }
        else
        {
            return false;
        }
    }
    if(lStatus == false || rStatus == false)
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
    return validateBstHelper(tree, tree->value);
}
int main()
{
    
    return 0;
}