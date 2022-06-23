#include<iostream>
using namespace std;


void maxHeapify(int arr[],int i,int n)
{
    int index=i;

    int leftindex=i*2;
    int rightindex=i*2+1;

    if(leftindex<=n && arr[index]<arr[leftindex] )
    {

        index=leftindex;

    }
    if(rightindex<=n && arr[index]<arr[rightindex])
    {

        index=rightindex;
    }
    if(index!=i)
    {
        swap(arr[index],arr[i]);
        maxHeapify(arr,index,n);

    }
}


void print(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}
void heapSort(int arr[],int n)
{
    for(int j=n;j>0;j--)
    {
        swap(arr[j],arr[1]);

        maxHeapify(arr,1,j-1);

    }

}

int main()
{

    int arr[10]={-1,45,35,39,48,49,63,64,37,100};
    int n=9;
    //print(arr,n);
    for(int i=n/2;i>0;i--)
    {
       maxHeapify(arr,i,n);


    }
    heapSort(arr,n);
    print(arr,n);

}



