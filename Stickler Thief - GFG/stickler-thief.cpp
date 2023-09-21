//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    { if(n == 0) return 0;
        if(n == 1) return arr[0];
    
        int include = arr[0];  // Maximum sum including the previous element
        int exclude = 0;       // Maximum sum excluding the previous element
    
        for (int i = 1; i < n; i++) {
            // Current maximum excluding i
            int new_exclude = max(exclude, include);
    
            // Current maximum including i
            include = exclude + arr[i];
            exclude = new_exclude;
        }
    
        // Return the maximum value of include and exclude
        return max(include, exclude);
        // Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends