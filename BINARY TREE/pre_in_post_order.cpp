#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct node
{
    int val;
    node* left;
    node* right;
    node(int data) 
    {
        val = data;
        left = right = NULL;
    }
};
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

//* TC = O(N) 
//* SC = O(h)    maximum stack filled or height of

//* worst case sc = O(N) skew tree (h == N)
//* best / avg case = O(log(n)) perfect binery tree (h == log(n)) : n = leaf nodes
void preorder(node *root)
{
    if(!root) return ;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if(!root) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(node *root)
{
    if(!root) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
//* TC => O(N) && SC => O(h) and in worst case : O(N) skew tree
void it_pre(node *root)
{    
    if(!root) return ;
    stack<node*> st; st.push(root);
    while (!st.empty())
    {
        node *curr = st.top(); st.pop();
        cout<<curr->val<<" ";
        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    } 
}
//* TC => O(N) && SC => O(h) or O(N) skew tree
void it_in(node *root)
{   
    stack<node*> st ;
    while (true)
    {
        if(root)
        {
            st.push(root);
            root=root->left; // go to left most 
        }
        else // if NULL
        {
            if(st.empty()) break;
            root = st.top(); st.pop(); // root point to parent
            cout<<root->val<<" ";
            root = root->right; // root point to its right
        }
    }  
}
//* two stack
//* TC => O(N) && SC => O(N) stack 2 space
void it_post(node *root) 
{   
    stack<node*> s;
    vector<int> v;
    s.push(root);
    while(!s.empty())
    {
        node *curr = s.top(); s.pop();
        v.push_back(curr->val);
        if(curr->left) s.push(curr->left);
        if(curr->right) s.push(curr->right);
    }
    reverse(v.begin(),v.end());
    for(auto i:v) cout<<i<<" ";
}
//* one stack
void it_post_2(node *root)
{
    stack<node*> st ;
    while (true)
    {
        if(root)
        {
            st.push(root);
            root=root->left; // (1) go to leftmost 
        }
        else
        {
            if(st.empty()) break;
            if(st.top()->right == NULL) // (3) if both left and right NULL
            {
                root = st.top(); st.pop();
                cout<<root->val<<" ";
                while (root==st.top()->right) // special case (4) if root is right of its parent 
                {
                    root=st.top();
                    cout<<root->val<<" "; 
                    st.pop();
                }
            }
            if(!st.empty()) root=st.top()->right; // (2) go to rightmost
            else root = NULL;
        }
    }
}
void pre_in_post(node *root) //* TC = O(3N) & SC = O(N)
{
    stack<pair<node*,int>> st;
    st.push({root,0});
    vector<int> pre,in,post;
    while (!st.empty())
    {
        node* curr = st.top().first;
        int x = st.top().second; st.pop();
        
        if(x==0)
        {
            pre.push_back(curr->val);
            st.push({curr,++x});
            if(curr->left) st.push({curr->left,0});
        }
        else if (x==1)
        {
            in.push_back(curr->val);
            st.push({curr,++x});
            if(curr->right) st.push({curr->right,0});
        }
        else 
        {
            post.push_back(curr->val);
        }
    }
    PrintV(pre);
    PrintV(in);
    PrintV(post);
    cout<<"End"<<endl;
    //  x  order  push
    // ------------------
    //  0  pre    left
    //  1  in     right
    //  2  post   nothing 
}
int main()
{
/*
         1
       /  \
      2    3
    /  \    \  
   4   5     6

*/
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    preorder(root); cout<<endl;
    it_pre(root); cout<<endl;

    inorder(root); cout<<endl;
    it_in(root) ; cout<<endl;

    postorder(root); cout<<endl;
    it_post(root); cout<<endl;
    it_post_2(root); cout<<endl;
    cout<<"All Triversal => "<<endl;
    // pre_in_post(root);
    return 0;
}
// 1 2 4 5 3 6 
// 1 2 4 5 3 6 
// 4 2 5 1 3 6 
// 4 2 5 1 3 6 
// 4 5 2 6 3 1 
// 4 5 2 6 3 1 
// 4 5 2 6 3 1 
// 1 2 4 5 3 6 
// 4 2 5 1 3 6 
// 4 5 2 6 3 1 

