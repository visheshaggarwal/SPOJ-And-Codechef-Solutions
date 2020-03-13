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
    int max_sum = INT_MIN;

    int maxpath(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l = max(0,maxpath(root->left));
        int r = max(0,maxpath(root->right));

        max_sum = max(max_sum,l+r+root->val);

        return root->val + max(l,r);

    }
    int maxPathSum(TreeNode* root) {
        maxpath(root);
        return max_sum;
    }
};
