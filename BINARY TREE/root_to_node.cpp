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

class Solution
{
public:
    void answer(node *root)
    {
        vector<int> path;
        int n = 8;
        cout<<root_to_any_node_path(root, path, n)<<endl;
        for(auto i: path) cout<<i<<" ";
        cout<<endl;


    }
    // https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/

    bool root_to_any_node_path(node *root, vector<int> &path, int n)
    {
        if (!root) return false;
        path.push_back(root->val);
        if (root->val == n) return true;
        
        if(root_to_any_node_path(root->left, path, n) ||
        root_to_any_node_path(root->right, path, n)) return true;

        path.pop_back();
        return false ;
    }

    bool root_to_any_node_path_sum(node *root, vector<int> &path, int n)
    {
        if (!root) return false;
        path.push_back(root->val);
        if (root->val == n) return true;
        
        if(root_to_any_node_path_sum(root->left, path, n) ||
        root_to_any_node_path_sum(root->right, path, n)) return true;

        path.pop_back();
        return false ;
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
    root->left->right->left = new node(7);
    root->right->right->left = new node(8);
    root->right->right->right = new node(9);
    root->left->right->left->left = new node(10);
    root->right->right->left->left = new node(11);
    root->right->right->right->right = new node(12);
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