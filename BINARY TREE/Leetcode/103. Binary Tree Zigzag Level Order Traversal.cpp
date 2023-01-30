class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode* > q;
    q.push(root);
    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for(int i=0;i<size;i++)
        {
            TreeNode* fr = q.front();
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
};