#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;
class graph
{
    public:
    unordered_map<int,list<int>>node;

    void create(int u,int v,bool direction)
    {
        node[u].push_back(v);
        //if direction equal to false then
        if(direction==0)
        {
           node[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i : node)
        {
            cout<<i.first;
            cout<<"->";
            //cout<<i.second;
            for(auto j: i.second)
            {

                cout<<j<<" ";
            }
            cout<<endl;
        }

    }
};
int main()
{
    graph g;
    cout<<"Enter total number of node";
    int n;
    cin>>n;

    cout<<"Enter total number of vertex";
    int e;
    cin>>e;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g.create(u,v,false);
    }
    g.print();

}
