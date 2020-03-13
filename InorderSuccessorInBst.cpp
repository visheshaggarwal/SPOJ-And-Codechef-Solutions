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
    TreeNode* ans = NULL;
    void inorder(TreeNode* root,TreeNode* p,TreeNode* &prev)
    {
        if(root==NULL)
            return;
        inorder(root->left,p,prev);
        if(prev!=NULL && prev->val==p->val && root->val >= prev->val)
            ans = root;
        prev = root;
        inorder(root->right,p,prev);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* prev = NULL;
        inorder(root,p,prev);
        return ans;
    }
};
