int countNode(struct Node* tree)
{
    if(tree==NULL)
    {
        return 0;
    }
    return 1+countNode(tree->left)+countNode(tree->right);
    
}
bool isCBT(struct Node* root,int i,int tn)
{
    if(root==NULL)
    {
        return true;
    }
    if(i>tn)
    {
        return false;
    }
    bool left=isCBT(root->left,i*2,tn);
    bool right=isCBT(root->right,i*2+1,tn);
    if(left && right)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool isMaxheap(struct Node* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        return true;
    }
     if(root->left==NULL && root->right!=NULL)
    {
        return false;
    }
    if(root->right==NULL)
    {
        return root->data>root->left->data;
    }
    else 
    {
        bool left= isMaxheap(root->left);
        bool right= isMaxheap(root->right);
         
        return left && right && ((root->data > root->left->data)&& (root->data>root->right->data));
    }
}
class Solution {
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int totalNode=countNode(tree);  
        if(isCBT(tree,1,totalNode) && isMaxheap(tree))
        {
            return true;
        }
        
        
    }
};