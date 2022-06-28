// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
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
***************/
void preorder(BinaryTreeNode<int>* root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    preorder(root->left,v);
    v.push_back(root->data);
    preorder(root->right,v);
    
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> v;
    preorder(root,v);
    int s=0;
    int e=v.size()-1;
    while(s<e)
    {
        int sum=v[s]+v[e];
        if(sum==target)
        {
            return true;
        }
        if(sum>target)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    return false;
    
}