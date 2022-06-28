/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void preorder(TreeNode<int>* root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    preorder(root->left,v);
    v.push_back(root->data);
    preorder(root->right,v);
    
}
TreeNode<int>* minBST(vector<int>& v,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>* root=new TreeNode<int>(v[mid]);
    root->left=minBST(v,s,mid-1);
    root->right=minBST(v,mid+1,e);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int>v;
    preorder(root,v);
    int s=0;
    int e=v.size()-1;
    return minBST(v,s,e);
    
}
