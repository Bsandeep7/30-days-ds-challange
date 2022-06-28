#define MOD 1000000007
#include<vector>

//recursion solution;
long long int solve(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    
    return (n-1)%MOD * (solve(n-1)%MOD +solve(n-2)%MOD);
}

//dp with memoization
long long int solveMem(int n,vector<long long int>&dp)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]= ((n-1)%MOD * (solveMem(n-1,dp)%MOD +solveMem(n-2,dp)%MOD))%MOD;
    return dp[n];
}

//dp with tab 

long long int solveTab(int n)
{
    vector<long long int>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    
    for(int i=3;i<=n;i++)
    {
        long long int first=dp[i-1]%MOD;
        long long int second=dp[i-2]%MOD;
        
        long long int sum=first+second;
        dp[i]=(((i-1)%MOD)*sum)%MOD;
    }
    return dp[n];
    
    
}

//dp with spaceoptimization

long long int solveSpace(int n)
{
    long long int prev1=0;
    long long int prev2=1;
    
    for(int i=3;i<=n;i++)
    {
        long long int sum=(prev1%MOD)+(prev2%MOD);
        prev1=prev2%MOD;
        prev2=(((i-1)%MOD)*sum)%MOD;
    }
    return prev2;
        
        
        
}



long long int countDerangements(int n) {
    
    
    vector<long long int>dp(n+1,-1);
    //return solveMem(n,dp);
    //return solveTab(n);
    return solveSpace(n);
    
    
}