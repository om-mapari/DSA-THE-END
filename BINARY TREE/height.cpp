#include <iostream>
using namespace std;
#include <bits/stdc++.h>
class node
{
    public:
    int val;
    node *left;
    node *right;
    node(int data)
    {
        val = data;
        left = right = NULL;
    }
};
/*
             1
           /   \
          2     3
        /  \     \
       4     5    6
           /     / \
          7     8   9
        /    /       \
      10    11        12

*/
//* TC = O(N)        
//* SC = O(N) auxiliary space -> at the worst case if it is skew tree
class Solution
{
public:

    void answer(node* root){

        // Question 1 : Find Height or Depth of tree
        // Totel No of nodes in longest path to root 
        cout<<"Height => " <<height(root)<<endl;

        // Question 2 : Balanced tree
        // if(isBal()) abs(lh-rh) > 1
        bool isbal = true;
        isBalanced(root,isbal);
        cout<<"Check Balanced => "<<isbal<<endl;

        // Question 3 : Min Depth
    }
    int height(node* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
    int isBalanced(node* root,bool &isbal){
        if(!root) return 0;
        int lh = isBalanced(root->left,isbal);
        int rh = isBalanced(root->right,isbal);
        if(abs(lh-rh)>1) isbal = false;
        return max(lh,rh) + 1;
    }
    int minDepth(node* root){
        if(!root) return 0;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }


};






















//==================== UnUsed Part =======================//
vector<vector<int>> level_wise(node *root);
void PrintV(vector<int> &v);
void PrintVV(vector<vector<int>> &v);
int main()
{

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    // root->left->right->left = new node(7);
    // root->right->right->left = new node(8);
    // root->right->right->right = new node(9);
    // root->left->right->left->left = new node(10);
    // root->right->right->left->left = new node(11);
    // root->right->right->right->right = new node(12);
    vector<int> v;
    vector<vector<int>> vv;
    cout << "\n======= Level Wise Triversal =======\n" ;
    vv = level_wise(root);
    PrintVV(vv);
    cout << "============= Soluation ============\n" ;
    Solution s;
    s.answer(root);

    return 0;
}

void PrintV(vector<int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

void PrintVV(vector<vector<int>> &v)
{
    for (auto i : v)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}
vector<vector<int>> level_wise(node *root)
{
    queue<node *> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *fr = q.front();
            q.pop();
            level.push_back(fr->val);
            if (fr->left)
                q.push(fr->left);
            if (fr->right)
                q.push(fr->right);
        }
        ans.push_back(level);
    }
    return ans;
}