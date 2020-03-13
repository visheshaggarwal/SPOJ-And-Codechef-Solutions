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
    bool isMirror(TreeNode* r1,TreeNode* r2)
    {
        if(r1==NULL && r2==NULL)
            return true;
        if(r1==NULL || r2==NULL)
            return false;
        return r1->val==r2->val && isMirror(r1->left,r2->right) && isMirror(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};
