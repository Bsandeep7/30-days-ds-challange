class Solution {
  public:

  int height(struct Node* node){
        // code here 
        if(node==NULL)
        {
            return 0;
        }
        return max(height(node->left),height(node->right))+1;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if(root==NULL)
        {
            return 0;
        }
        int left=diameter(root->left);
        int right=diameter(root->right);
        int both=height(root->left)+height(root->right)+1;
        return max(left,max(right,both));
        
        

        
        
    }
};