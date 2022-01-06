#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct node
{
    int val;
    node *left;
    node *right;
    node(int data)
    {
        val = data;
        left = right = NULL;
    }
};

vector<int> level_ord(node *root)
{   
    //* TC => O(N) && SC => at some point for each level all the nodes in that level will be in queue therefore O(n) 

    //* SC => worst case => O(2^h) or O(n)       as h = log(n) for balanced tree n = max node at level
    //*       best case  => O(1)                 skew trees or degenrate tree 
    queue<node *> q;
    vector<int> v;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        v.push_back(curr->val);
        q.pop();
        if (curr->left != NULL) q.push(curr->left);
        if (curr->right != NULL) q.push(curr->right);
    }
    return v;
}
vector<vector<int>> level_wise(node *root)
{   
    queue<node*> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            node* fr = q.front();
            q.pop();
            level.push_back(fr->val);
            if(fr->left) q.push(fr->left);
            if(fr->right) q.push(fr->right);
        }
        ans.push_back(level);
    }
    return ans;
}
vector<vector<int>> level_ord_rev_store(node *root)
{    //* TC => O(N) && SC => O(n)
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for(int i=0;i<size;i++)
        {
            node* fr = q.front();
            q.pop();
            v[size-i-1] = fr->val;
            if(fr->left) q.push(fr->left);
            if(fr->right) q.push(fr->right);
        }
        ans.push_back(v);
    }
    return ans;
}
vector<vector<int>> ZigZag(node *root)
{    //* TC => O(N) && SC => O(n)
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<node *> q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for(int i=0;i<size;i++)
        {
            node* fr = q.front();
            q.pop();
            if(flag) v[i]=fr->val;
            else v[size-i-1] = fr->val;
            if(fr->left) q.push(fr->left);
            if(fr->right) q.push(fr->right);
        }
        ans.push_back(v);
        flag=!flag;
    }
    return ans;
}

//=======================================================//
vector<int> level_ord_rev_store_2(node *root)
{
    vector<int> v;
    if (!root)
        return v;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        v.push_back(curr->val);
        q.pop();
        if (curr->right != NULL) q.push(curr->right);
        if (curr->left != NULL) q.push(curr->left);
    }
    return v;
}




//============================================================================//
// Boundry Order triversal 
// TC = O(N) --> (h) + (N) + (h)
// SC = O(h) 
void left_boundary_re(node* root,vector<int> &ans)
{
    if(!root) return ;
    if(root->left)
    {
        ans.push_back(root->val);
        left_boundary_re(root->left,ans);
    }
    else if(root->right)
    {
        ans.push_back(root->val);
        left_boundary_re(root->right,ans);
    }
}
void right_boundary_re(node* root,vector<int> &ans)
{
    if(!root) return ;
    if(root->right)
    {
        right_boundary_re(root->right,ans);
        ans.push_back(root->val);
    }
    else if(root->left)
    {
        right_boundary_re(root->left,ans);
        ans.push_back(root->val);
    }
}
void leaf_nodes_re(node* root,vector<int> &ans)
{
    if(!root) return ;
    leaf_nodes_re(root->left,ans);
    if(!root->left && !root->right) ans.push_back(root->val);
    leaf_nodes_re(root->right,ans);
}
vector<int> Boundry_order_re(node* root)
{
    vector<int> ans;
    left_boundary_re(root,ans);
    leaf_nodes_re(root,ans);
    right_boundary_re(root->right,ans);

    return ans;
}

//-------------------------------------//

void left(node* root,vector<int> &res)
{
    if(!root) return ;
    while(true){
        if(root->left) {
            res.push_back(root->val);
            root=root->left;
        }
        else if(root->right)
        {
            res.push_back(root->val);
            root=root->right;
        }
        else{
            break;
        }
    }
}
void right(node* root,vector<int> &res)
{
    if(!root) return ;
    vector<int> temp ;
    while(true){
        if(root->right) {
            temp.push_back(root->val);
            root=root->right;
        }
        else if(root->left)
        {
            temp.push_back(root->val);
            root=root->left;
        }
        else{
            break;
        }
    }

    for(int i = temp.size()-1 ;i>0;i--){
        res.push_back(temp[i]);
    }
}
void leaf(node* root,vector<int> &res){
    if(!root) return;
    leaf(root->left,res);
    if(!root->left && !root->right) res.push_back(root->val);
    leaf(root->right,res);
}
void answer(node* root)
{
    vector<int> res;
    left(root,res);
    leaf(root,res);
    right(root,res);
    for(auto &i : res) cout<<i<<" ";

}

//-----------------------------------------------------//

bool isleaf(node* &nod) // use isleaf method 
{
    if(!nod->left && !nod->right) return true;
    return false;
}
void left_boundery(node* root,vector<int> &ans)
{
    while(root)
    {
        if(!isleaf(root)) ans.push_back(root->val);
        if(root->left) root=root->left;
        else root=root->right;
    }
}
void right_boundery(node* root,vector<int> &ans)
{
    auto it = ans.end();
    while(root)
    {
        if(!isleaf(root)) ans.push_back(root->val);
        if(root->right) root=root->right;
        else root=root->left;
    }
}
void leaf_nodes(node* root,vector<int> &ans)
{
    if(!root) return ;
    leaf_nodes(root->left,ans);
    if(isleaf(root)) ans.push_back(root->val);
    leaf_nodes(root->right,ans);
}
vector<int> Boundry_order_it(node* root)
{
    vector<int> ans;
    left_boundery(root,ans);
    leaf_nodes(root,ans);
    right_boundery(root->right,ans);
    return ans;
}

//----------------------------------------------------//


void PrintV(vector<int> &v);
void PrintVV(vector<vector<int>> &v);
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
    vector<int> v;
    vector<vector<int>> vv;
    

    // v = level_ord(root);
    // PrintV(v);
    // vv = level_wise(root);
    // PrintVV(vv); 
    // vv = level_ord_rev_store(root);
    // PrintVV(vv); 
    // vv=ZigZag(root);
    // PrintVV(vv); 
    // cout<<endl;
    // vv = verticalTraversal(root);
    // PrintVV(vv);

    v = Boundry_order_re(root);
    PrintV(v);

    v = Boundry_order_it(root);
    PrintV(v);


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
    for(auto i: v)
    {
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }
}