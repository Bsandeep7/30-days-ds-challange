#include<unordered_map>
#include<list>
#include<vector>
#include<stack>

void DFS(unordered_map<int,list<int>>&adjList, vector<bool>&visited
         , vector<int>&ans,int node)
{
    
    visited[node]=true;
    for(auto i :adjList[node])
    {
        if(!visited[i])
        {
            DFS(adjList,visited,ans,i);
            
        }
    }
    //cout<<node<<" ";
    ans.push_back(node);
    
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    // Write your code here
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        
        adjList[u].push_back(v);
        //adjList[v].push_back(u);
    }
    
    vector<int> ans;
    vector<bool>visited(v);
    for(int i=0;i<v;i++)
    {
        
        if(!visited[i])
        {
            //vector<int>component;
            DFS(adjList,visited,ans,i);
             //ans.push_back(component);
        }
       
    }
    vector<int>a;
    for(int i=ans.size()-1;i>=0;i--)
    {
       // int t=ans.top();
        //cout<<ans[i]<<" ";
        //ans.pop();
        //a.push_back(t);
        a.push_back(ans[i]);
    }
    return a;
}