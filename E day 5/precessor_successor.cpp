/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void findsp(BinaryTreeNode<int>*root,pair<int,int>& ans,int key)
{
    if(root==NULL)
    {
        return;
        ans=make_pair(-1,-1);
    }
    if(root->data==key)
    {
        if(root->left!=NULL)
        {
            BinaryTreeNode<int>*temp=root->left;
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            ans.first=temp->data;
            
        }
       
        
        if(root->right!=NULL)
        {
           BinaryTreeNode<int>*temp=root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            ans.second=temp->data;
            

        }
       
        return;
       
    }
    if(root->data>key)
    {
        ans.second=root->data;
        findsp(root->left,ans,key);
    }
    else
    {
        ans.first=root->data;
        findsp(root->right,ans,key);
    }
    
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    pair<int,int> ans=make_pair(-1,-1);
   findsp(root,ans,key);
    return ans;
}
