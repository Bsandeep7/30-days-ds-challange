#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(vector < vector < int >> &arr,vector<vector<bool>>&visited,int x,int y,int n)
{
    if(( x>=0 && x<n )&&( y>=0 && y<n) && arr[x][y]==1 &&  visited[x][y]!=1)
    {
        return true;
    }else
    {
        return false;
    }
}

void solve(vector < vector < int >> & arr,  vector<vector<bool>>&visited, vector<string>&ans, string path, int x, int y, int n)
{
    if(x==n-1 && y==n-1)
    {
        ans.push_back(path);
        return;
    }

    //D L R U

    visited[x][y]=1;

    if(isSafe(arr,visited,x+1,y,n))
    {
        solve(arr,visited,ans,path+'D',x+1,y,n);
    }

     if(isSafe(arr,visited,x,y-1,n))
    {
        solve(arr,visited,ans,path+'L',x,y-1,n);
    }

     if(isSafe(arr,visited,x,y+1,n))
    {
        solve(arr,visited,ans,path+'R',x,y+1,n);
    }

     if(isSafe(arr,visited,x-1,y,n))
    {
        solve(arr,visited,ans,path+'U',x-1,y,n);
    }

    visited[x][y]=0;


}



vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    string path="";
    if(arr[0][0]==0)
    {
        return ans;
    }
    solve(arr,visited,ans,path,0,0,n);
    return ans;
}
int main()
{
    vector<vector<int>>arr{
        {1,0,0,0},
        {1,0,0,0},
        {1,0,0,0},
        {1,1,1,1}
    };
    int n=4;
    vector<string> ans;
    ans=searchMaze(arr,n);
    for(int i=0;i<ans.size();i++)
    {

        cout<<ans[i]<<endl;;
    }





}
