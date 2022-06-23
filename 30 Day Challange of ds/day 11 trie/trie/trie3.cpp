
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
class Trie{

   public:
       TrieNode *root;


       void insertWord(TrieNode* root.string word)
       {
           if(word.length()==0){
            root->terminal=true;
            return;

           }

           int index=word[0]-'A';

           TrieNode* child;

           if(root->children[index]!=NULL)
           {
               child=root

           }




       }
       void insert(string word)
       {
           insertWord(root,word);
       }

};
int main();
{


}
