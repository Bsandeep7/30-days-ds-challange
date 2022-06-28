int solve(vector<int> &nums,int n)
{
    if(n==0)
    {
        return nums[n];
    }
    if(n<0)
    {
        return 0;
    }
    int inc=solve(nums,n-2)+nums[n];
    int exc=solve(nums,n-1)+0;
    
    int ans=max(inc,exc);
    return ans;
}
int solveMem(vector<int> &nums,int n,vector<int>&dp)
{
    if(n==0)
    {
        return nums[n];
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int inc=solveMem(nums,n-2,dp)+nums[n];
    int exc=solveMem(nums,n-1,dp)+0;
    
    dp[n]=max(inc,exc);
    return dp[n];
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size()+1,-1);
    
   return solveMem(nums,nums.size()-1,dp);
    
}