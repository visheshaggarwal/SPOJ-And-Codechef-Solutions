/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void find(TreeNode* root,TreeNode* &tmp,int x)
    {
        if(root==NULL)
            return;
        if(root->val == x)
        {
            tmp = root;
            return;
        }
        find(root->left,tmp,x);
        find(root->right,tmp,x);
    }
    int count(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* tmp = NULL;
        find(root,tmp,x);
        int l = count(tmp->left);
        int r = count(tmp->right);
        int t = n-l-r-1;
        if(t>l+r+1)
            return true;
        else if(l>t+r+1)
            return true;
        else if(r>t+l+1)
            return true;
        else
            return false;
    }
};
