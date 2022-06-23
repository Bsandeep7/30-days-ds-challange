/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
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
void createList(TreeNode<int>* &temp,vector<int>v,int &i)
{
    if(i==v.size())
    {
        return;
    }
    temp=new TreeNode<int>(v[i++]);
    createList(temp->right,v,i);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code herevector<int> v;
    vector<int> v;
    preorder(root,v);
    TreeNode<int>*temp=NULL;
    int i=0;
    createList(temp,v,i);
        return temp;
    
    
}
