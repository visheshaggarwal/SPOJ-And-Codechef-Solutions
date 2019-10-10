#include <iostream>
#include<climits>
using namespace std;
class Tree{
    public:
        long long prefix_sum,suffix_sum,best_sum,total_sum;
};
void buildTree(Tree *tree,long *arr,int ind,int s,int e)
{
    if(s==e)
    {
        tree[ind].prefix_sum = arr[s];
        tree[ind].suffix_sum = arr[s];
        tree[ind].best_sum = arr[s];
        tree[ind].total_sum = arr[s];
        return;
    }

    int mid = (s+e)/2;
    buildTree(tree,arr,2*ind,s,mid);
    buildTree(tree,arr,2*ind+1,mid+1,e);

    tree[ind].prefix_sum = max(tree[2*ind].prefix_sum,tree[2*ind].total_sum + tree[2*ind+1].prefix_sum);
    tree[ind].suffix_sum = max(tree[2*ind+1].suffix_sum,tree[2*ind].suffix_sum + tree[2*ind+1].total_sum);
    tree[ind].total_sum = tree[2*ind].total_sum + tree[2*ind+1].total_sum;
    tree[ind].best_sum = max(tree[2*ind].suffix_sum + tree[2*ind+1].prefix_sum , max(tree[2*ind].best_sum,tree[2*ind+1].best_sum));

    return;
}

Tree query(Tree* tree,long *arr,int ind,int s,int e,int qs,int qe)
{
    Tree t;

    if(s>e || qs>e || qe<s)
    {
        t.prefix_sum = t.suffix_sum = t.best_sum = INT_MIN;
        t.total_sum = 0;
        return t;
    }

    if(qs<=s && qe>=e)
    {
        return tree[ind];
    }

    int mid = (s+e)/2;
    Tree left = query(tree,arr,2*ind,s,mid,qs,qe);
    Tree right = query(tree,arr,2*ind+1,mid+1,e,qs,qe);

    t.prefix_sum = max(left.prefix_sum, left.total_sum + right.prefix_sum);
    t.suffix_sum = max(right.suffix_sum, left.suffix_sum + right.total_sum);
    t.total_sum = left.total_sum + right.total_sum;
    t.best_sum = max(left.suffix_sum+right.prefix_sum,max(left.best_sum,right.best_sum));
    return t;
}

void Update(Tree* tree,long* arr,int ind,int s,int e,int x,long val)
{
    if(s>e || s>x || e<x)
        return;

    if(s==e)
    {
        tree[ind].prefix_sum = val;
        tree[ind].suffix_sum = val;
        tree[ind].total_sum = val;
        tree[ind].best_sum = val;
        arr[x] = val;
        return;
    }

    int mid = (s+e)/2;
    Update(tree,arr,2*ind,s,mid,x,val);
    Update(tree,arr,2*ind+1,mid+1,e,x,val);

    tree[ind].prefix_sum = max(tree[2*ind].prefix_sum,tree[2*ind].total_sum + tree[2*ind+1].prefix_sum);
    tree[ind].suffix_sum = max(tree[2*ind+1].suffix_sum,tree[2*ind].suffix_sum + tree[2*ind+1].total_sum);
    tree[ind].total_sum = tree[2*ind].total_sum + tree[2*ind+1].total_sum;
    tree[ind].best_sum = max(tree[2*ind].suffix_sum + tree[2*ind+1].prefix_sum , max(tree[2*ind].best_sum,tree[2*ind+1].best_sum));
    return;
}

int main() {
    int n;cin>>n;
    long arr[1000000];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Tree* tree = new Tree[4*n + 1];
    buildTree(tree,arr,1,0,n-1);

    int q;cin>>q;
    for(int i=0;i<q;i++)
    {
        int t;cin>>t;
        if(t==1)
        {
            int l,r;cin>>l>>r;
            cout<<query(tree,arr,1,0,n-1,l-1,r-1).best_sum<<endl;
        }
        else
        {
            int x;
            long y;
            cin>>x>>y;
            Update(tree,arr,1,0,n-1,x-1,y);
        }
    }
}
