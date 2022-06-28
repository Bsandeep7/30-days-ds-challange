class Solution
{
    pair<bool,int> check(Node* root)
    {
        if(root==NULL)
        {
            return make_pair(true,0);
        }
        if(root->left==NULL && root->right==NULL)
        {
            return make_pair(true,root->data);
        }
        pair<bool,int>ls=check(root->left);
        pair<bool,int>rs=check(root->right);
        
        if(ls.first==true && rs.first==true && root->data==ls.second+rs.second)
        {
            return make_pair(true,2*root->data);
        }
        else
        {
            return make_pair(false,0);
        }
        
        
        
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         pair<bool,int>ans=check(root);
         return ans.first;
         
    }
};
