//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
          vector<int>vr;
        int ans=-1;
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        
        //first occurance 
        
        while(start<=end){
            if(arr[mid]==x){
                ans=mid;
                end=mid-1;
            }
            else if(arr[mid]>x){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
      
        
        // last occurance
        int start2=0;
        int end2=n-1;
        int mid2=start2+(end2-start2)/2;
        
        int ans2=-1;
        
        while(start2<=end2){
            
            if(arr[mid2]==x){
                ans2=mid2;
                start2=mid2+1;
            }
            else if(arr[mid2]>x){
                end2=mid2-1;
            }
            
            else{
                start2=mid2+1;
            }
            mid2=start2+(end2-start2)/2;
        }
        
        vr.emplace_back(ans);
        vr.emplace_back(ans2);
        
    
        return vr; // code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends