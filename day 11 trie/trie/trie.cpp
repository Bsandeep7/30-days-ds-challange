#include<iostream>
using namespace std;

class TrieNode
{
    public:
     char data;
     TrieNode *children[26];
     bool terminal;

     TrieNode(char ch)
     {
         data=ch;
         for(int i=0;i<26;i++)
         {
             children[i]=NULL;
         }
         terminal=false;

     }
};

void insert(TrieNode * &root,string word,int i)
{
    if(i==word.size())
    {
        root->terminal=true;
        return;
    }
    char temp=word[i];
    int index=temp-'A';
    if(root->children[index]!=NULL)
    {

        insert(root->children[index],word,i+1);
    }
    else
    {

        TrieNode *child=new TrieNode(temp);
        root->children[index]=child;
        insert(child,word,i+1);
    }

}
bool searchWord(TrieNode * root,string word,int i)
{
    if(i==word.size())
    {
        return root->terminal;
    }
   char temp=word[i];
    int index=temp-'A';
    TrieNode *child;

    if(root->children[index]!=NULL)
    {

       child=root->children[index];
    }
    else{

        return false;
    }
     return searchWord(child,word,i+1);
}
void removeWord(TrieNode *root,string word,int i)
{
     if(i==word.size())
    {
        root->terminal=false;
        return;
    }
    char temp=word[i];
    int index=temp-'A';
    TrieNode *child;

    if(root->children[index]!=NULL)
    {

       child=root->children[index];
    }
    else{

        return ;
    }
    removeWord(child,word,i+1);
}
void remove(TrieNode *root,string word)
{
    int i=0;
    bool isterminal=searchWord(root,word,i);
    if(isterminal)
    {
        removeWord(root,word,i);
    }else
    {
        cout<<"Word Not Exist in Dict";
        return;
    }


}
int main()
{
    TrieNode *root=new TrieNode('\0');
    int i=0;
    insert(root,"SANDEEP",i);
    TrieNode *temp=root->children[0];
    cout<<searchWord(root,"SANDEEP",i);
    remove(root,"SANDEEP");
    cout<<searchWord(root,"SANDEEP",i);
    remove(root,"SINGH");

}
