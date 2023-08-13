#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//This code of BST class is generated by Chat gpt to save time
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
vector<int> branchSumHelper(BinaryTree* root, int sum, vector<int> result)
{
    if(root == nullptr)
    {
        cout << "Root is Returned\n";
        return result;
    }
    sum = sum + root->value;
    if(root->left)
    {
        cout << "left side\n";
        result = branchSumHelper(root->left, sum, result);
        cout << "Sum is sum: " << sum << endl;
    }
    if(root->right)
    {
        cout << "right side\n";
        result = branchSumHelper(root->right, sum, result);
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        result.push_back(sum);
    }
    cout << "vector returned sum is: " << sum << endl; 
    return result;
}
vector<int> branchSum(BinaryTree * root)
{
    vector<int> result;
    int sum = 0;
    return branchSumHelper(root, sum, result);
}

int main()
{
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(2);
    root->right = new BinaryTree(3);
    root->left->left = new BinaryTree(4);
    root->left->right = new BinaryTree(5);
    root->right->left = new BinaryTree(6);
    root->right->right = new BinaryTree(7);
    root->left->left->left = new BinaryTree(8);
    root->left->left->right = new BinaryTree(9);
    root->left->right->left = new BinaryTree(10);
    vector<int> result = branchSum(root);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
