class Solution{
  public:
    void countPath(Node *root,int k,vector<int>temp,int &count)
    {
        if(root==NULL)
        {
            return;
        }
        temp.push_back(root->data);
        countPath(root->left,k,temp,count);
        countPath(root->right,k,temp,count);
        int ans=0;
        int size=temp.size();
        for(int i=size-1;i>=0;i--)
        {
            ans+=temp[i];
            if(ans==k)
            {
                count++;
            }
        }
        temp.pop_back();

    }
    int sumK(Node *root,int k)
    {
        // code here 
        vector<int> ans;
        int count=0;
        countPath(root,k,ans,count);
        return count;
        
    }
};