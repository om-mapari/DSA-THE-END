class Solution {
public:
    bool issame(TreeNode* p,TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        
       return issame(p->left,q->left) && issame(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto curr = q.front(); q.pop();
            if(curr->val == subRoot->val)
            {
                
                if(issame(curr,subRoot)) {
                    return true;
                }
                    
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return false;
    }
    

};