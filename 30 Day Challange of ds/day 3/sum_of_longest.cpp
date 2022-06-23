class Solution
{
public:
    pair<int,int>ans=make_pair(0,INT_MIN);
    void checkSum(Node* root,pair<int,int>temp)
    {
        if(root==NULL)
        {
            if(temp.first>ans.first)
            {
                ans.first=temp.first;
                ans.second=temp.second;
            }
            if(temp.first==ans.first && ans.second<temp.second)
            {
                ans.second=temp.second;
            }
            return;
            
        }
        temp.second+=root->data;
        temp.first++;
        checkSum(root->left,temp);
        checkSum(root->right,temp);
        return;
        
        
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        //code hereceh
        pair<int,int>temp=make_pair(0,0);
        checkSum(root,temp);
        return ans.second;
        
      
        
    }
};