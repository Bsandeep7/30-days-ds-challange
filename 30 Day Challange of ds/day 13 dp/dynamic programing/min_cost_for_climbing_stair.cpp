class Solution {
public:
//     int count(int n,vector<int>& cost)
//     {
//       if(n<=1)
//       {
//           return cost[n];
//       }

//         return cost[n]+min(count(n-1,cost),count(n-2,cost));
//     }


    int count2(int n,vector<int>&dp,vector<int>& cost)
    {
         if(n<=1)
         {
          return cost[n];
         }
        if(dp[n]!=-1)
        {
            return dp[n];
        }

        dp[n] =cost[n]+min(count2(n-1,dp,cost),count2(n-2,dp,cost));
        return dp[n];
    }

    int count3(int n,vector<int>& cost)
    {
        int prev2=cost[0];
        int prev1=cost[1];
        for(int i=2;i<n;i++)
        {
            int curr=cost[i]+min(prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);


    }

    int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         return min(count(n-1,cost),count(n-2,cost));

        int n=cost.size();
        // vector<int>dp(n+1,-1);
        // return min(count2(n-1,dp,cost),count2(n-2,dp,cost));
        return count3(n,cost);

    }


};
