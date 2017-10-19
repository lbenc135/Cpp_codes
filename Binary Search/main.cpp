#include <iostream>
using namespace std;

void Sort(int arr[], int asize)
{
    int temp;
    while(asize)
    {
        int newn=0;
        for(int i=1;i<asize;i++)
        {
            if(arr[i-1]>arr[i])
            {
                temp=arr[i-1];
                arr[i-1]=arr[i];
                arr[i]=temp;
                newn=i;
            }
        }
        asize=newn;
    }
}

bool Search(int arr[], int asize, int s)
{
    int mn=0, mx=asize;
    while(mn<mx-1)
    {
        int md=(mn+mx)/2;
        if(arr[md]<s) mn=md;
        else if(arr[md]>s) mx=md;
        else if(arr[md]==s) return md;
    }
}

int main()
{
    int arr[10];
    int s;
    for(int i=0;i<10;i++)
        cin >> arr[i];
    Sort(arr, 10);
    cin >> s;
    cout << Search(arr, 10, s);
}
