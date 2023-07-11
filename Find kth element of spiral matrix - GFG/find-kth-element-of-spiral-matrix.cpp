//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
         // Your code goes here.
         
         int l= 0;
         int t=0;
         int b= n-1;
         int r = m-1; 
         vector<int>arr;
         while(l<=r and t<=b){
     
             for(int i =l; i<=r; i++){
                  k--; 
                  if(k==0)return a[t][i];
             }
             t++;
         
             for(int i = t; i<=b; i++){
                k--; 
                  if(k==0)return a[i][r];
             }
             r--;
 
             for(int i = r; i>=l; i--){
                     k--; 
                  if(k==0)return a[b][i];
             }
             b--;

             for(int i = b; i>=t; i--){
                k--; 
                  if(k==0)return a[i][l];
             }
             l++; 
         }
         
         return 0; 
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends