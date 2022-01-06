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

void levelorder2(node *root)
{ //* TC => O(N) && SC => O(N)
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *fr = q.front();
            q.pop();
            cout << fr->data << " ";
            if (fr->left)
                q.push(fr->left);
            if (fr->right)
                q.push(fr->right);
        }
        cout << endl;
    }
    cout << endl;
}
int Search(vector<int> in, int ins, int ine, int ele)
{
    for (int i = ins; i <= ine; i++)
    {
        if (in[i] == ele)
            return i;
    }
    return -1;
}
node *From_Preorder_Inorder(vector<int> pre, vector<int> in, int &pres, int ins, int ine)
{
    if (ins > ine)
        return NULL;
    node *newNode = new node(pre[pres]);

    int po = Search(in, ins, ine, pre[pres]);
    pres++;
    newNode->left = From_Preorder_Inorder(pre, in, pres, ins, po - 1);
    newNode->right = From_Preorder_Inorder(pre, in, pres, po + 1, ine);
    return newNode;
}

node *help(vector<int> &pre, unordered_map<int,int> in, int &s, int ins, int ine)
{
    if (ins > ine)
        return NULL;
    node *root = new node(pre[s]);
    int po = in[pre[s]];
    s++;
    root->left = help(pre, in, s, ins, po - 1);
    root->right = help(pre, in, s, po + 1, ine);
    return root;
}
node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int start = 0;
    unordered_map<int,int> in;
    for (int i = 0; i < inorder.size(); i++)
    {
        in.insert({preorder[i], i});
    }
    return help(preorder, in, start, 0, inorder.size() - 1);
}

int main()
{

    vector<int> pre = {1, 2, 4, 5, 3, 7};
    vector<int> in = {4, 2, 5, 1, 3, 7};
    int st = 0;
    node *root = From_Preorder_Inorder(pre, in, st, 0, in.size() - 1);
    levelorder2(root);
    return 0;
}

//     /*
//          1
//        /  \
//       2    3
//     /  \    \  
//    4   5     6
//       /    /  \
//      7    8    9
//         /
//       10

//     node *root = new node(1);
//     root->left = new node(2);
//     root->right = new node(3);
//     root->left->left = new node(4);
//     root->left->right = new node(5);
//     root->right->right = new node(6);
//     root->left->right->left = new node(7);
//     root->right->right->left = new node(8);
//     root->right->right->right = new node(9);
//     root->right->right->left->left = new node(10);
// levelorder2(root);