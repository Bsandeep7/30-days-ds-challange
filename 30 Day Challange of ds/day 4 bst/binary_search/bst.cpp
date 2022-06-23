#include<iostream>
using namespace std;
class Node{
   public:
       int data;
       Node *left;
       Node *right;

       Node(int d)
       {
           data=d;
           left=right=NULL;

       }
};
void insertBst(Node *&root,int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        return;

    }
    if(data<root->data)
    {
        insertBst(root->left,data);

    }
    if(data>root->data)
    {

        insertBst(root->right,data);
    }

}
void takeInput(Node* &root)
{
    int data;
    cout<<"Enter data  for root node Of BST ";
    cin>>data;
    while(data!=-1)
    {
        insertBst(root,data);
        cout<<"Enter more data for child node of BST ";
        cin>>data;

    }

}
void inorder(Node *root)
{
    if(root==NULL)
    {

        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(Node *root, int x) {
    // Write your code here.
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    bool right=false;
    bool left=false;
    if(root->data>x)
    {
        left=searchInBST(root->left,x);
    }
    if(root->data<x)
    {
        right=searchInBST(root->right,x);

    }
    if(!left && !right)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void deleteBSTNode(Node *&root,int key)
{
    if(root==NULL)
    {
        return;

    }
    if(root->data==key)
    {
        if(!root->left && !root->right)
        {
            Node* temp=root;
            root=NULL;
            delete temp;
            return;
        }
        if(root->left!=NULL && root->right==NULL)
        {
            Node *temp=root;
            root=temp->left;
            delete temp;
            return;

        }
        if(root->left==NULL && root->right !=NULL)
        {
            Node * temp=root;
            root=temp->right;
            delete temp;
            return;

        }
        if(root->left !=NULL && root->right!=NULL)
        {
            Node *temp=root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;

            }
            root->data=temp->data;
            deleteBSTNode(root,temp->data);
            return;

        }
    }
    if(root->data>key)
    {
        deleteBSTNode(root->left,key);
        return;

    }
    if(root->data<key)
    {
        deleteBSTNode(root->right,key);
        return;

    }

}

int main()
{
    Node *root=NULL;
    takeInput(root);
    inorder(root);
    //cout<<"Enter data for search";
    //int x;
    //cin>>x;
    //cout<<searchInBST(root,x);
    cout<<"Enter data for delete"<<endl;
    int x;
    cin>>x;
    deleteBSTNode(root,x);
    inorder(root);




}

