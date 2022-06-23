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
Node * succ(Node * root,int key)
{
    if(root==NULL)
    {
        return NULL;

    }
    if(key==root->data)
    {
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            return temp;
        }

    }
    if(root->data>key)
    {

        return NULL;

    }
    else
    {
         Node *temp=root;
         temp=succ(root->right,key);
       return temp;
    }

}
void findsp(Node *root,pair<int,int>& ans,int key)
{
    if(root==NULL)
    {
        return;
        ans=make_pair(-1,-1);
    }
    if(root->data==key)
    {
        if(root->left!=NULL)
        {
            BinaryTreeNode<int>*temp=root->left;
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            ans.first=temp->data;

        }


        if(root->right!=NULL)
        {
           BinaryTreeNode<int>*temp=root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            ans.second=temp->data;


        }

        return;

    }
    if(root->data>key)
    {
        ans.second=root->data;
        findsp(root->left,ans,key);
    }
    else
    {
        ans.first=root->data;
        findsp(root->right,ans,key);
    }

}

int main()
{
    Node *root=NULL;
    takeInput(root);

    cout<<"For what value want to find successor"<<endl;
    int x;
    cin>>x;
    pair<int,int>ans;
    Node *temp=succ(root,ans,x);
    if(temp!=NULL)
    {
        cout<<x<<" Successor is "<<temp->data;
    }
    else
    {
        cout<<"Successor is not availaable";
    }





}

