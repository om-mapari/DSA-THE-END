#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

bool isSameTree(TreeNode *p,TreeNode *q)
{
    if(!p and !q ) return true; //left & right node is NULL 
    if(!p || !q) return false; //one of them is Not NULL
    if(p->val != q->val) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

// comparing left subtree's left child with right subtree's right child 
// --AND-- comparing left subtree's right child with right subtree's left child


int main() 
{
/*
         1
       /  \
      2    3
    /  \    \  
   4   5     6
      /    /  \
     7    8    9
    /   /
   10  11  

*/
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->left->right->left->left = new TreeNode(10);
    root->right->right->left->left = new TreeNode(11);
    
    TreeNode *root2 = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->right->right = new TreeNode(9);
    root2->right->left = new TreeNode(8);
    root2->right->left->left = new TreeNode(11);

    TreeNode *root3 = new TreeNode(3);
    root3->right = new TreeNode(6);
    root3->right->right = new TreeNode(9);
    root3->right->left = new TreeNode(8);
    root3->right->left->left = new TreeNode(11);
    

    cout<<"\n Check if same => "<<isSameTree(root2,root3);
    return 0;
}