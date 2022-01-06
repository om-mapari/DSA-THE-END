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


void topViewBFS(node* root){ // BFS 
    queue<pair<int,node*>> q;
    map<int,int> m;
    q.push({0,root});
    while(!q.empty())
    {
        auto curr = q.front(); q.pop();
        node* currNode = curr.second;
        int hd = curr.first;
        if(m.find(hd) == m.end()) m[hd] = currNode->val;
        if(currNode->left) q.push({hd-1,currNode->left});
        if(currNode->right) q.push({hd+1,currNode->right});
    }
    for(auto i : m){
        cout<<i.second<<" ";    
    }
    cout<<endl;
}
void BottomViewBFS(node* root){ // BFS 
    queue<pair<int,node*>> q;
    map<int,int> m;
    q.push({0,root});
    while(!q.empty())
    {
        auto curr = q.front(); q.pop();
        node* currNode = curr.second;
        int hd = curr.first;
        m[hd] = currNode->val;
        if(currNode->left) q.push({hd-1,currNode->left});
        if(currNode->right) q.push({hd+1,currNode->right});
    }
    for(auto i : m){
        cout<<i.second<<" ";    
    }
    cout<<endl;
}

// https://youtu.be/zoagmWU1yD8

void bottom_view_DFS(node *root, map<int, pair<int,int>>& m, int dist, int level)
{
    if (root == NULL)return;
    if (m.count(dist) == 0 || m[dist].second < level)
        m[dist] = make_pair(root->val, level);

    bottom_view_DFS(root->left, m, dist-1, level + 1);
    bottom_view_DFS(root->right, m, dist+1, level + 1);
}

void top_view_DFS(node *root, map<int, pair<int,int>>& m, int dist, int level)
{
    if (!root) return;
    if (m.count(dist) == 0 || m[dist].second > level)
        m[dist] = make_pair(root->val, level);

    top_view_DFS(root->left, m, dist-1, level + 1);
    top_view_DFS(root->right, m, dist+1, level + 1);
}

void answer(node* root){
    BottomViewBFS(root);
    // map<dist,pair<node,level>> m
    map<int,pair<int,int>> m;
    
    bottom_view_DFS(root, m, 0, 0);
    for (auto i : m)
        cout << i.second.first << " ";
    cout << endl;
    vector<int> v = {2,3,5}; 
    PrintV(v);
    // topViewBFS(root);

}


//===================================================================//
vector<vector<int>> level_wise(node *root);

void PrintVV(vector<vector<int>> &v);
int main()
{
/*
         1
       /  \
     2     3
    /  \    \  
   4    5    6
      /     / \
     7     8   9
    /    /      \
  10    11       12

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
    root->right->right->right->right = new node(12);

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
    cout<<"============Answer============="<<endl; 
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
    for(auto i: v)
    {
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }
}
vector<vector<int>> level_wise(node *root)
{   
    queue<node*> q;
    vector<vector<int>> ans;
    q.push(root);
    cout<<"LevelWise Triversal => "<<endl;
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