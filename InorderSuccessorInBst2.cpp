/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution{
public:
    Node* Right(Node* root)
    {
        if(root==NULL)
            return NULL;
        if(root->left == NULL)
            return root;
        return Right(root->left);
    }
    Node* inorderSuccessor(Node* node) {
        Node* ans = Right(node->right);
        if(ans!=NULL)
            return ans;
        else
        {
            Node* tmp = node->parent;
            while(tmp!=NULL && tmp->val <= node->val)
            {
                tmp = tmp->parent;
            }
            return tmp;
        }
    }
};
