/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode<int>* root,int &count,int k)
{
    if(root==NULL)
    {
        return -1;
    }
   
    int left=solve(root->left,count,k);
    if(left!=-1)
    {
        return left;
    }
    count++;
     if(count==k)
    {
        return root->data;
    }
    
    return solve(root->right,count,k);
    
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int count=0;
    return solve(root,count,k);
}