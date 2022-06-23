#include<bits/stdc++.h>
#include<vector>
using namespace std;

// using memoization
int fib(int n,vector<int>arr)
{


    if(n<=1)
    {

        return n;
    }

    if(arr[n]!=-1)
    {
        return arr[n];
    }


    arr[n]=fib(n-1,arr)+fib(n-2,arr);

    return arr[n];
}

//using tabulation

void fibt(int n)
{
    vector<int>arr(n+1);
    arr[0]=0;
    arr[1]=1;

    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n];

}

// space optimization

void fibs(int n)
{
    int first=0;
    int second=1;
    for(int i=2;i<=n;i++)
    {
       int curr=first+second;
       first=second;
       second=curr;

    }
    cout<<second;
}

int main()
{

    int n;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=0;i<=n;i++)
    {
        arr[i]=-1;
    }

   fib(n,arr);
   fibt(n);
   fibs(n);
    return 0;
}
