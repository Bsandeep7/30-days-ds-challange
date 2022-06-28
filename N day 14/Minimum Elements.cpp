int solve(vector<int>num,int x)
{
    if(x==0)
    {
        return 0;
    }
    if(x<0)
    {
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++)
    {
        int ans=solve(num,x-num[i]);
        if(ans!=INT_MAX)
        {
            mini=min(mini,ans+1);
        }
    }
    return mini;
    
}

int solve2(vector<int> &num,vector<int>& dp,int x)
{
    if(x==0)
    {
        return 0;
    }
    if(x<0)
    {
        return INT_MAX;
    }
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++)
    {
        int ans=solve2(num,dp,x-num[i]);
        if(ans!=INT_MAX)
        {
            mini=min(mini,1+ans);
        }
    }
    dp[x]=mini;
    return mini;
}


int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<int>dp(x+1,-1);
    int ans= solve2(num ,dp,x);
    if(ans==INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
     
        
}