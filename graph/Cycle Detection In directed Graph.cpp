#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
void createAdj(vector < pair < int, int >> & edges, unordered_map<int ,list<int>>&adj)
{
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
    }
}
bool detect(unordered_map<int ,bool>&visited,  unordered_map<int,bool>DFSvisited, unordered_map<int ,list<int>>adj,int node)
{
    visited[node]=true;
    DFSvisited[node]=true;
    for(auto i: adj[node])
    {
        
        if(!visited[i])
        {
            bool temp=detect(visited,DFSvisited,adj,i);
        }
        if(visited[i] && DFSvisited[i])
        {
            return true;
        }
        
    }
    return false;
    
    
    
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int ,list<int>>adj;
    createAdj(edges,adj);
    unordered_map<int ,bool>visited;
    unordered_map<int,bool>DFSvisited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=detect(visited,DFSvisited,adj,i);
            if(ans==true)
            {
                return 1;
            }
        }
    }
    return 0;
}