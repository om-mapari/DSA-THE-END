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

        // Question 1 : Diameter of tree
        // No. of Node including two node
        int d = INT_MIN;
        dimeter(root, d);
        cout << "Diameter of Tree => " << d << endl;

        // Question 2 : Max path sum
        // maximum sum between two nodes
        int res = INT_MIN;
        max_path_sum(root, res);
        cout << "Maximum Path sum => " << res << endl;

        // Question 3 : Max path sum
        // maximum sum between leaf nodes

        cout << "Maximum Path from leaf to leaf => " << maxPathSum(root) << endl;
    }

    int dimeter(node *root, int &d)
    {
        if (!root)
            return 0;
        int l = dimeter(root->left, d);
        int r = dimeter(root->right, d);
        int temp = max(l, r) + 1;       // case 1 : I will pass
        int ans = max(temp, l + r + 1); // case 2 : I am ans
        d = max(d, ans);
        return temp;
    }

    int max_path_sum(node *root, int &res) 
    {
        if (!root)
            return 0;
        int l = max_path_sum(root->left, res);
        int r = max_path_sum(root->right, res);
        int temp = max(max(l, r) + root->val, root->val); // case 1 : I will pass
        int ans = max(temp, l + r + root->val);           // case 2 : I am ans
        res = max(res, ans);
        return temp;
    }

    int max_path_sum_leaf_to_leaf(node *root, int &res)
    {
        if (!root)
            return 0;
        int l = max_path_sum_leaf_to_leaf(root->left, res);
        int r = max_path_sum_leaf_to_leaf(root->right, res);
        int temp = max(l, r) + root->val;       // case 1 : I will pass
        int ans = max(temp, l + r + root->val); // case 2 : I am ans
        res = max(res, ans);
        return temp;
    }

    
    int solve(node *root, int &res)
    {
        if (!root) // base condition
            return 0;
        if (root->left == NULL && root->right == NULL)
        {
            return root->val;
        } // base condition ends
        // hypothesis
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        // induction
        // if both left andright part of tree
        // present
        if (root->left && root->right)
        {
            int temp = max(l, r) + root->val;
            // temp gives us the value which this node will
            // transfer to the calling node
            int ans = (l + r + root->val);
            // ans gives us the value if the node is
            // giving the maxPath as the ultimate parent
            res = max(res, ans);
            // res is just taking the max value for
            // output
            return temp;
        }
        if (root->left == NULL)
        {
            int temp = r + root->val;
            // here there is no ans variable
            // as skew part cant be the maxPathSum
            return temp;
        }
        if (root->right == NULL)
        {
            int temp = l + root->val;
            return temp;
        }
    }
    int maxPathSum(node *root)
    {
        // code here
        int res = INT_MIN;
        int ans = solve(root, res);
        if (res != INT_MIN)
        {
            return res;
        }
        else
        {
            return ans;
        }
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
    cout << "\n======= Level Wise Triversal =======\n";
    vv = level_wise(root);
    PrintVV(vv);
    cout << "============= Soluation ============\n";
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