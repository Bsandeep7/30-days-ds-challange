#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
    int data;
    node *left,*right;

    node(int d)
    {
        data=d;
        left=right=NULL;

    }

};
void createBST(node * &root,int data)
{
    if(root==NULL)
    {
        root=new node(data);
        return;
    }
    if(data<root->data)
    {
        createBST(root->left,data);
    }
    if(data>root->data)
    {
        createBST(root->right,data);
    }

}
void inorder(node *root,vector<int>&arr)
{
    if(root==NULL)
    {

        return ;
    }
    inorder(root->left,arr);

    arr.push_back(root->data);

    inorder(root->right,arr);


}
void minheap(node* &root,vector<int>arr,int &i)
{
    if(root==NULL)
       {

           return;
       }

       root->data=arr[i++];
       minheap(root->left,arr,i);
       minheap(root->right,arr,i);

}
void convertBSTtoMinHeap(node *&root)
{
    vector<int>arr;

    inorder(root,arr);

    int i=0;

    minheap(root,arr,i);

}
void preorder(node* root)
{

    if(root==NULL)
    {

        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
int main()


{
    node * root=NULL;
    cout<<"Enter data for creating bst";
    int data;
    while(data!=-1)
    {
        cin>>data;
        cout<<endl<<"Enter -1 for exit";
        createBST(root,data);
    }
    convertBSTtoMinHeap(root);
    preorder(root);




}

