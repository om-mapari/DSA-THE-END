class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1; q1.push(root->left);
        queue<TreeNode*> q2; q2.push(root->right);
        
        while(!q1.empty() || !q2.empty())
        {
            TreeNode* l = q1.front(); q1.pop();
            TreeNode* r = q2.front(); q2.pop();
            
            if(l==NULL && r==NULL) continue;
            if(l==NULL || r==NULL) return false;
            if(l->val != r->val) return false;
            
            q1.push(l->left);
            q1.push(l->right);
            q2.push(r->right);
            q2.push(r->left);
        }

        return true;
    }
};