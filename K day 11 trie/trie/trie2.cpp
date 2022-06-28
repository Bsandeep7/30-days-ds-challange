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

class Trie {

public:
      TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
         root=new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertNode(TrieNode * root,string word)
{
    if(word.length()==0)
    {
        root->terminal=true;
        return;
    }
    char temp=word[0];
    int index=temp-'A';
    if(root->children[index]!=NULL)
    {
        cout<<"1";
        insertNode(root->children[index],word.substr(1));
    }
    else
    {
        cout<<"2";
        TrieNode *child=new TrieNode(temp);
        root->children[index]=child;
        insertNode(child,word.substr(1));
    }

}
    void insert(string word) {
         insertNode(root,word);
    }

    /** Returns if the word is in the trie. */
 bool searchWord(TrieNode * root,string word)
{
    if(word.size()==0)
    {
        return root->terminal;
    }
   char temp=word[0];
    int index=temp-'A';
    TrieNode *child;


    if(root->children[index]!=NULL)
    {

       child=root->children[index];
    }
    else{

        return false;
    }
     return searchWord(child,word.substr(1));
}
    bool search(string word) {
           return searchWord(root,word);
    }
};
int main()
{
    Trie* obj = new Trie();
    obj->insert("SANDEEP");
    bool check2 = obj->search("SANDEEP");
    cout<<check2;


}
