class Solution {
public:
 
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return minDepth(root->right)+1;
        if(!root->right) return minDepth(root->left)+1;
        
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
    
};

class Solution {
public:
 
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int s=q.size();
            level++;
            
            for(int i=0;i<s;i++)
            {
                auto curr= q.front(); q.pop();
                if(!curr->left & !curr->right) return level;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return -1;
    }
    
};