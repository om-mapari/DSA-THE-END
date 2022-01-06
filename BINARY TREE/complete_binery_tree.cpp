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

/*            1
           /    \
          2      3
        /  \    / \
       4     5 9   6
     7 
*/

class Solution
{
public:
    void answer(node* root){
        cout<<noofNodes(root);
        // TC
    }
    int noofNodes(node* root)
    {
        if(!root) return 0;
        int lh = leftExtremHeight(root);
        int rh = rightExtremHeight(root);
        if(lh==rh) return ((1 << lh) - 1);
        return noofNodes(root->left) + noofNodes(root->right) + 1; 
    }
    int leftExtremHeight(node* root){
        if(!root) return 0;
        int h = 0;
        while(root){ 
            root=root->left;
            h++;
        }
        return h;
    }
    int rightExtremHeight(node* root){
        if(!root) return 0;
        int h = 0;
        while(root){ 
            root=root->right;
            h++;
        }
        return h;
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
    root->right->left = new node(9);
    // root->left->left->left = new node(7);
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