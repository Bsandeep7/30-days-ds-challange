#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node * right;

    Node(int d)
    {
      data=d;
      left=right=NULL;

    }
};
Node *bulidTree(Node *root)
{
    cout<<"Enter the data:";
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1)
    {
        return NULL;

    }

    cout<<"Enter the data for left node of"<<data;
    root->left=bulidTree(root->left);
    cout<<"Enter the data for right node of"<<data;
    root->right=bulidTree(root->right);

    return root;


}
void levelorderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        {

        q.push(temp->left);

        }
        if(temp->right)
        {
            q.push(temp->right);

        }
    }

}
void morrisTravesal(Node *root)
{
    Node *curr=root;
    while(curr)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;


        }
        else{

            Node*pred=curr->left;
            while(pred->right!=NULL && pred->right!=curr)
            {
                pred=pred->right;

            }

            if(pred->right==NULL)
            {
                pred->right=curr;
                curr=curr->left;

            }
            else{
                pred->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
                }
        }

    }

}

int main()
{
    Node *root=NULL;
    root=bulidTree(root);

    //inorderTraversal(root);
   //
    //root=levelorderBuildtree(root);
   // levelorderTraversal(root);
    //preorderTraversal(root);
    morrisTravesal(root);
    return 0;


}

