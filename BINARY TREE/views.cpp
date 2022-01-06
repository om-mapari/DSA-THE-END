#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int height(node *root) 
{    //* TC = O(N)        
    //* SC = O(N) auxiliary space ?-> at the worst case if it is skew tree
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
int height2(node *root) 
{    //* TC = O(N)        
    //* SC = O(N) auxiliary space ?-> at the worst case if it is skew tree
    if (!root) return 0;
    int lh = height2(root->left);
    int rh = height2(root->right);
    return 1 + max(lh,rh);
}

void levelorder2(node *root)
{   //* TC => O(N) && SC => O(N)
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            node* fr = q.front();
            q.pop();
            cout<<fr->data<<" ";
            if(fr->left) q.push(fr->left);
            if(fr->right) q.push(fr->right);
        }
        cout<<endl;
    }
    cout<<endl;
}

void leftView(node* root)
{
    if(!root) return ;
    queue<node*> q;
    q.push(root);
    // cout<<root->data<<" ";
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto curr = q.front(); q.pop();
            if(i==0){cout<<curr->data<<" ";}
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);

        }
        cout<<endl;
    }
}
int maxLevel = 0;
void leftViewR(node* root,int level)
{
    if(!root) return ;
    if(maxLevel<level) {
        cout<<root->data<<endl;
        maxLevel= level;
    }

    leftViewR(root->left,level+1);
    leftViewR(root->right,level+1);

}

void rightView(node* root)
{
    if(!root) return ;
    queue<node*> q;
    q.push(root);
    // cout<<root->data<<" ";
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto curr = q.front(); q.pop();
            if(i==s-1){cout<<curr->data<<" ";}
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);

        }
        cout<<endl;
    }
}
void rightViewR(node *root,int level,vector<int> &res)
{
    if(!root) return;
    if(level==res.size()) res.push_back(root->data);
    rightViewR(root->right,level+1,res);
    rightViewR(root->left,level+1,res);
}





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
    leftView(root);
    rightView(root);
    cout<<endl;
    leftViewR(root,1);


    vector<int> v;
    rightViewR(root,0,v);
    // PrintV(v);
    return 0;
}