#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>

void prepareList( unordered_map<int,set<int>>&adj,vector<vector<int>>& edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
        
    }
}

bool BFSans( unordered_map<int,set<int>>adj, unordered_map<int,bool>&visited,int node,unordered_map<int,int>parent)
{
    queue<int>q;
    q.push(node);
    visited[node]=true;
    parent[node]=-1;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        
       // ans.push_back(frontNode);
        
        for(auto i: adj[frontNode])
        {
           
            if(visited[i]== true && i!=parent[frontNode])
            {
                return true;
            }
            else if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
                parent[i]=frontNode;
            }
           
        }
               
    }
    return false;
   
    
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,set<int>>adj;
    unordered_map<int,bool>visited;
    
    prepareList(adj,edges);
    unordered_map<int,int>parent;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
             bool ans=BFSans(adj,visited,i,parent);
            if(ans==1)
            {
                return "Yes";
            }
        }
       
    }
    return "No";
}
