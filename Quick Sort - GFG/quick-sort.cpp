//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
  void quickSort(int arr[], int low, int high)
    {
        // code here
        // This function sorts the array using the quick sort algorithm.

        // `low` is the low index of the array.
        // `high` is the high index of the array.

        // If the low index is less than the high index, then the function recursively sorts the array.
        if(low<high){
           // `part` is the index of the pivot element.
           int part=partition(arr,low,high);
           
           // Recursively sort the left subarray.
           quickSort(arr,low,part-1);
           
           // Recursively sort the right subarray.
           quickSort(arr,part+1,high);
        }
    }
    
    // This function partitions the array around the pivot element.
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       // `startInd` is the index of the first element greater than the pivot.
       // `endInd` is the index of the last element smaller than the pivot.
       // `p` is the pivot element.
      int startInd=low,endInd=high;
      int p=arr[low];
      while(startInd<endInd){
          // Iterate until `arr[startInd]` is greater than or equal to the pivot.
          while(arr[startInd]<=p){
              startInd = startInd + 1;
          }
           // Iterate until `arr[endInd]` is less than the pivot.
          while(arr[endInd]>p){
              endInd = endInd - 1;
          }
          // If `startInd` is less than `endInd`, then swap the elements at `startInd` and `endInd`.
          if(startInd<endInd){
              swap(arr[startInd],arr[endInd]);
          }
      }
       // Swap the pivot element with the element at `endInd`.
      swap(arr[low],arr[endInd]);
      
      // Return the index of the pivot element.
      return endInd;
     
    }

};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends