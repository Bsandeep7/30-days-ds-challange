long long count(long long n)
{
    if(n<=1)
    {
        return n;
    }
    long long one=1;
    long long two=2;

    for(int i=3;i<=n;i++)
    {
        long long curr=one+two;
        one=two;
        two=curr;
    }
    return  two;

}


int countDistinctWayToClimbStair(long long nStairs)
{
    //  Write your code here.


    if(nStairs==0)
    {
        return 1;
    }
      long long ans=count(nStairs);
    return ans;
}
