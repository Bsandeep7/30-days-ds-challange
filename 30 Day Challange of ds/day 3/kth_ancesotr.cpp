void find(Node *root,vector<int>path,int k,int node,int &ans)
{
    if(root==NULL)
    {
        
        return ;
    }
    if(node==root->data)
    {
        if(path.size()>=k)
        {
            ans=path[path.size()-k];
        }
        return;
    }
    path.push_back(root->data);
    if(ans==-1)
    {
    find(root->left,path,k,node,ans);
    find(root->right,path,k,node,ans);
    }
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans=-1;
    vector<int>path;
    find(root,path,k,node,ans);
    return ans;
    
    
}