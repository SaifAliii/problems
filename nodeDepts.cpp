#include<iostream>
using namespace std;
class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};
int nodeDepthsHelper(BinaryTree * root, int depth)
{
    cout << "Recursive Calls\n";
    int leftDepth = 0;
    int rightDepth = 0;
    if(root == nullptr)
    {
        return depth;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        return depth;
    }
    if(root->left)
    {
        leftDepth = nodeDepthsHelper(root->left, depth + 1);
    }
    if(root->right)
    {
        rightDepth = nodeDepthsHelper(root->right, depth + 1);
    }
    depth = depth + leftDepth + rightDepth;
    return depth;
}
int nodeDepths(BinaryTree* root) {
    int depth = 0;
    return nodeDepthsHelper(root, depth);
}
int main()
{
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    // root->right = new BinaryTree(3);
    // root->left->left = new BinaryTree(4);
    // root->left->right = new BinaryTree(5);
    // root->right->left = new BinaryTree(6);
    // root->right->right = new BinaryTree(7);
    // root->left->left->left = new BinaryTree(8);
    // root->left->left->right = new BinaryTree(9);
    cout << "The Depth of tree is: " << nodeDepths(root) << endl;
    return 0;
}