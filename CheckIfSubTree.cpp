/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
vector<Node*> v;
void find(Node* T,Node* S,Node* &T1)
{
    if(T==NULL)
        return;
    if(T->data == S->data){
        T1 = T;
        v.push_back(T);
    }
    find(T->left,S,T1);
    find(T->right,S,T1);
}
bool isPresent(Node* T,Node* S)
{
    if(S==NULL && T==NULL)
        return true;
    if(S==NULL || T==NULL)
        return false;

    return T->data == S->data && isPresent(T->left,S->left) && isPresent(T->right,S->right);
}
/*you are required to
complete this function */
bool isSubTree(Node* T, Node* S) {
    // Your code here
    // return 1 if S is subtree of T else 0
    Node* T1 = NULL;
    find(T,S,T1);
    bool ans = false;
    for(int i=0;i<v.size();i++){
        ans = ans || isPresent(v[i],S);
        if(ans)
            return ans;
    }
    return ans;
}
