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
    vector<int>ans;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i: adjList[frontNode])
        {
           
            indegree[i]--;
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
    }
    return ans;