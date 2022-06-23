class Solution{
    public:
    void maxHeapify(vector<int>&arr,int i,int n)
{
    int index=i;

    int leftindex=i*2+1;
    int rightindex=i*2+2;

    if(leftindex<n && arr[index]<arr[leftindex] )
    {

        index=leftindex;

    }
    if(rightindex<n && arr[index]<arr[rightindex])
    {

        index=rightindex;
    }
    if(index!=i)
    {
        swap(arr[index],arr[i]);
        maxHeapify(arr,index,n);

    }
}

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>v;
       for(int i=0;i<n;i++)
       {
           v.push_back(a[i]);
       }
        for(int i=0;i<m;i++)
       {
           v.push_back(b[i]);
       }
       
      for(int i=(v.size()/2)-1;i>=0;i--)
      {
          maxHeapify(v,i,v.size());
      }
      return v;
       
    }
};