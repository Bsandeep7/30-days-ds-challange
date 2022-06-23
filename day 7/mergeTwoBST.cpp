/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorderVector(TreeNode<int> *root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    inorderVector(root->left,v);
    v.push_back(root->data);
    inorderVector(root->right,v);
}
TreeNode<int>* minBST(vector<int>& v,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    TreeNode<int>* root=new TreeNode<int>(v[mid]);
    root->left=minBST(v,s,mid-1);
    root->right=minBST(v,mid+1,e);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int>v1;
    vector<int>v2;
    inorderVector(root1,v1);
    inorderVector(root2,v2);
    vector<int> mv;
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]<v2[j])
        {
            mv.push_back(v1[i++]);
        }
        else
        {
            mv.push_back(v2[j++]);
        }
    }
    while(i<v1.size())
    {
        mv.push_back(v1[i++]);
    }
    while(j<v2.size())
    {
        mv.push_back(v2[j++]);
    }
    int s=0;
    int e=mv.size()-1;
    return minBST(mv,s,e);
}