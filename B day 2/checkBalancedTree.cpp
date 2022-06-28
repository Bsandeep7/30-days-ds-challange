class Solution{
    public:
    int height(struct Node* node){
        // code here 
        if(node==NULL)
        {
            return 0;
        }
        return max(height(node->left),height(node->right))+1;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL)
        {
            return true;
        }
        bool lb=isBalanced(root->left);
        bool rb=isBalanced(root->right);
        
        int left=height(root->left);
        int right=height(root->right);
        bool both=false;
        if(abs(left-right)<=1)
        {
            both=true;
        }
        if(lb && rb && both)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
