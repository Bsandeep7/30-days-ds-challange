#include<limits.h>
int solve(int n,int x,int y,int z)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT_MIN;
    }
    int a=solve(n-x,x,y,z)+1;
    int b=solve(n-y,x,y,z)+1;
    int c=solve(n-z,x,y,z)+1;
    
    return max(a,max(b,c));
   
}

int solveMem(int n,int x,int y,int z,vector<int>&dp)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT_MIN;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int a=solveMem(n-x,x,y,z,dp)+1;
    int b=solveMem(n-y,x,y,z,dp)+1;
    int c=solveMem(n-z,x,y,z,dp)+1;
    
    dp[n]= max(a,max(b,c));
    return dp[n];
   
}


int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    //int ans=solve(n,x,y,z);
    vector<int>dp(n+1,-1);
    int ans=solveMem(n,x,y,z,dp);
    if(ans<0)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}