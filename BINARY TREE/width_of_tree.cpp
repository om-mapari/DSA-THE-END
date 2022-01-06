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
int maxi = 0;

int width(node *root)
{
    if(!root) return 0;
    int widthMax = 1;
    deque<node *> d;
    d.push_back(root);
    while (!d.empty())
    {
        cout<<"size bef = "<<d.size()<<" | ";
        while (!d.empty() && d.front() == NULL) d.pop_front();
        while (!d.empty() && d.back() == NULL) d.pop_back();
        
        int size = d.size();
        cout<<"size aft = "<<size<<endl;
        for (int i = 0; i < size; i++)
        {
            node *curr = d.front();d.pop_front();
            if (!curr)
            {
                d.push_back(NULL);
                d.push_back(NULL);
            }
            else
            {
                d.push_back(curr->left);
                d.push_back(curr->right);
            }
        }
        widthMax = max(widthMax, size);
    }
    return widthMax;
}
void widthBFS(node *root)
{
    queue<pair<node *,int>> q;
    int maxWidth = 1;
    q.push({root,1});
    while (!q.empty())
    {
        int size = q.size();
        int first = 0, last = 0;
        for (int i = 0; i < size; i++)
        {
            auto fr = q.front(); q.pop();
            
            node* nod = fr.first;
            if(i==0) first=fr.second;
            if(i==size-1) last = fr.second;
            if (nod->left) q.push({nod->left,fr.second*2});
            if (nod->right) q.push({nod->right,fr.second*2+1});
        }
        maxWidth = max(maxWidth,last-first+1);
    }
    cout<<"maxWidth = "<<maxWidth<<endl;
}

void answer(node *root)
{
    cout<<"Width with sol 1\n"<<width(root)<<endl;
    widthBFS(root) ;
}

//===================================================================//
vector<vector<int>> level_wise(node *root);
void PrintV(vector<int> &v);
void PrintVV(vector<vector<int>> &v);
int main()
{
   
/*           1
           /  \
         2     3
        /  \    \
       4    5    6
          /     / \
         7     8   9
*/
    // node* root = NULL;
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->right->right->left = new node(8);
    root->right->right->right = new node(9);
    // root->left->right->left->left = new node(10);
    // root->right->right->left->left = new node(11);
    // root->right->right->right->right = new node(12);

    // root->left = new node(2);
    // root->left->left = new node(3);
    // root->left->left->right = new node(4);
    // root->left->left->right->left = new node(5);
    // root->left->left->right->right = new node(6);
    // root->right = new node(7);
    // root->right->right = new node(8);
    // root->right->right->left = new node(9);
    // root->right->right->left->left = new node(10);
    // root->right->right->left->right = new node(11);

    vector<int> v;
    vector<vector<int>> vv;
    vv = level_wise(root);
    PrintVV(vv);
    cout << "============Answer=============" << endl;
    answer(root);
    // printVerticalOrder(root);

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
    if(!root) return {{}};
    queue<node *> q;
    vector<vector<int>> ans;
    q.push(root);
    cout << "LevelWise Triversal => " << endl;
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