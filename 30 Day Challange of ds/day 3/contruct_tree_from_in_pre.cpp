// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    
    public:
    void create(Node * &root,int in[],int pre[],int startIndex,int endIndex,int &preIndex,int n)
    {
        
        if(preIndex >=n || endIndex<startIndex)
        {
            return;
        }
        int element=pre[preIndex++];
        root=new Node(element);
        int index;
        for(int j=0;j<=endIndex;j++)
        {
            if(element==in[j])
            {
               index=j;
               break;
            }
        }
        create(root->left,in,pre,startIndex,index-1,preIndex,n);
        create(root->right,in,pre,index+1,endIndex,preIndex,n);
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int startIndex=0;
        int endIndex=n-1;
        int preIndex=0;
        Node *root=NULL;
        create(root,in,pre,startIndex,endIndex,preIndex,n);
        return  root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends