#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=0;
    for(int i=0;i<n-2;i++)
    {
        if(arr[i]+arr[i+2]==2*arr[i+1])
        {
            count++;
        }
    }
    cout<<"The number of subarrays of length three satisfying the condition is: "<<count;
    return 0;
}