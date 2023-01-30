class Solution {
public:
    int search(vector<int> &in,int ins,int ine,int ele)
    {
        for(int i=ins;i<=ine;i++)
        {
            if(in[i]==ele) return i;
        }
        return -1;
    }
    TreeNode* help(vector<int>& pre,vector<int> &in,int &s,int ins,int ine)
    {
        if(ins>ine) return NULL;
        TreeNode* root = new TreeNode(pre[s]);
        int po = search(in,ins,ine,pre[s]);
        s++;
        root->left = help(pre,in,s,ins,po-1);
        root->right = help(pre,in,s,po+1,ine);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start =0;
        return help(preorder,inorder,start,0,inorder.size()-1);
    }
};