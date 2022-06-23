#include<iostream>
using namespace std;

class heap{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int val)
    {
        size=size+1;
        int index=size;
        arr[index]=val;


        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;

            }
            else
            {
                break;

            }
        }


    }
    void print()
    {
        for(int i=1;i<=size;i++)
        {
         cout<<arr[i]<<" ";

        }
        cout<<endl;
    }

    void deleteheapnode()
    {
        if(size==0)
        {
            cout<<"Nothing to delete"<<endl;
        }
        arr[1]=arr[size];
        size=size-1;
        int index=1;
        while(index<=size)
        {
            int leftindex=index*2;
            int rightindex=index*2+1;

            if(leftindex<=size && arr[index]<arr[leftindex] && arr[leftindex]>arr[rightindex])
            {

                swap(arr[index],arr[leftindex]);
                index=leftindex;
            }

             else if(rightindex<=size && arr[index]<arr[rightindex]  && arr[leftindex]<arr[rightindex] )
            {

                 swap(arr[index],arr[rightindex]);
                 index=rightindex;
            }
            else
            {
                return;
            }

        }

    }

};


int main()
{
    heap h;
    h.insert(55);
    h.insert(45);
    h.insert(35);
    h.insert(60);
    h.insert(86);
    h.insert(47);
    h.print();
    h.deleteheapnode();
    h.print();

}
