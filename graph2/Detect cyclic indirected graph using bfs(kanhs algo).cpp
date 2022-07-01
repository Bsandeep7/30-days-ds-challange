int topologicalSort(vector < pair < int, int >> & edges, int v, int e)  {
    // Write your code here

    // Write your code here
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first-1;
        int v=edges[i].second-1;
        
        adjList[u].push_back(v);
        //adjList[v].push_back(u);
    }
    
    //create indegree vector
    
    vector<int>indegree(v);
    for(auto i:adjList)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        cnt++;
        for(auto i: adjList[frontNode])
        {
           
            indegree[i]--;
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
    }
    if(cnt==v)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
//     unordered_map<int ,list<int>>adj;
//     createAdj(edges,adj);
//     unordered_map<int ,bool>visited;
//     unordered_map<int,bool>DFSvisited;
//     for(int i=0;i<n;i++)
//     {
//         if(!visited[i])
//         {
//             bool ans=detect(visited,DFSvisited,adj,i);
//             if(ans==true)
//             {
//                 return 1;
//             }
//         }
//     }
//     return 0;
    return topologicalSort(edges,n,edges.size());
}