class Solution {
public:
    void checkLeft(Node* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL || root->right!=NULL)
        {
           ans.push_back(root->data);
        }
        
        checkLeft(root->left,ans);
        if(root->left==NULL && root->right!=NULL)
        {
            checkLeft(root->right,ans);
        }
        
    }
    void checkRight(Node* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
         
        checkRight(root->right,ans);
        if(root->right==NULL && root->left!=NULL)
        {
            checkRight(root->left,ans);
        }
        if(root->left!=NULL || root->right!=NULL)
        {
           ans.push_back(root->data);
        }
        
    }
    void checkLeaf(Node *root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->data);
            return;
        }
        checkLeaf(root->left,ans);
        checkLeaf(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        ans.push_back(root->data);
        if(root->left==NULL && root->right==NULL)
        {
            return ans;
        }
        checkLeft(root->left,ans);
        checkLeaf(root,ans);
        checkRight(root->right,ans);
       return ans;
    }
};
