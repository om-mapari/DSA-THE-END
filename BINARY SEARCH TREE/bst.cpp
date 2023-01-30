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
void printv(vector<int> &v);
void printvv(vector<vector<int>> &v);
/*            8
            /   \    
          4      12
        /  \    /  \
      2    6  10    14
*/

class Solution
{
public:
    int c = -1;
    void answer(node* root){
        
        int x = 4;

        solve(root,x);
        cout<<"ceil "<<c<<endl;
    }

    bool solve(node* root,int x)
    {
        if(!root) return false;

        if(root->val>x){
            c = root->val;
            return solve(root->left,x);
        }
        else if(root->val<x)
        {
            return solve(root->right,x);
        }
        else{
            return true;
        }
    }



};






















//==================== UnUsed Part =======================//
vector<vector<int>> level_wise(node *root);
void inorder(node *root);
int main()
{

    node *root = new node(8);
    root->left = new node(5);
    root->right = new node(10);
    root->left->left = new node(2);
    root->left->right = new node(6);
    root->left->right->left = new node(7);
    // root->right->left = new node(10);
    // root->right->right = new node(14);
/*            8
            /   \    
          4      12
        /  \    /  \
      2    6  10    14
*/
    vector<int> v;
    vector<vector<int>> vv;
    // cout << "======== Inorder Triversal =========\n" ;
    // cout << "Inorder = " ; inorder(root); 
    cout << "\n======= Level Wise Triversal =======\n" ;
    vv = level_wise(root);
    printvv(vv);
    cout << "============= Soluation ============\n" ;
    Solution s;
    s.answer(root);

    return 0;
}

void printv(vector<int> &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
void printvv(vector<vector<int>> &v)
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
void inorder(node* root){
    if(!root) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}