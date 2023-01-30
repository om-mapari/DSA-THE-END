class Solution {
public:
    int helpDimeter(TreeNode *root, int &d)
    {
        if (!root) return 0;
        int lh = helpDimeter(root->left, d);
        int rh = helpDimeter(root->right, d);
        d = max(d, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        int h = helpDimeter(root, d);
        return d;
    }
};