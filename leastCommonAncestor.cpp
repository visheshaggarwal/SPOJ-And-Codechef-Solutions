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
    TreeNode* ans;
    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
            return false;

        int left = traverse(root->left,p,q);
        int right = traverse(root->right,p,q);
        int mid = root==p || root==q;

        if(left + right + mid >=2)
            ans = root;
        if(left || right || mid)
            return true;
        else
            return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root,p,q);
        return ans;
    }
};
