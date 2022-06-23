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
void inorderTraversal(Node *root)
{
    stack<Node*>q;

    Node* temp=root;
    while(!q.empty() || temp)
    {

       while(temp)
       {
           q.push(temp);
           temp=temp->left;

       }
       temp=q.top();
       q.pop();
       cout<<temp->data<<" ";
       temp=temp->right;


    }

}
void preorderTraversal(Node *root)
{
    stack<Node*>q;

    Node* temp=root;
    while(!q.empty() || temp)
    {

       while(temp)
       {
           cout<<temp->data<<" ";
           if(temp->right)
            {
           q.push(temp->right);
           }
           temp=temp->left;

       }
       if(!q.empty())
       {
                  }
       temp=q.top();
       q.pop();
       }

    }


Node *levelorderBuildtree(Node *root)
{

    queue<Node*>q;
    cout<<"Enter data for the root";
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();

        int l ,r;
        cout<<"Enter left node of the"<<" "<<temp->data<<" ";
        cin>>l;
        Node *t1=new Node(l);
        if(l!=-1)
        {
         temp->left=t1;
         q.push(temp->left);
        }

        cout<<"Enter right node of the"<<" "<<temp->data<<" ";
        cin>>r;
        Node *t2=new Node(r);
        if(r!=-1)
        {
         temp->right=t2;
         q.push(temp->right);
        }

        q.pop();


    }
    return root;
}


int main()
{
    Node *root=NULL;
    //root=bulidTree(root);

    //inorderTraversal(root);
   //
    root=levelorderBuildtree(root);
    levelorderTraversal(root);
    preorderTraversal(root);
    return 0;


}

