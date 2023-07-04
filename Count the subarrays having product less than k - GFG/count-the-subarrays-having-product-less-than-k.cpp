//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
         int end = 0;
        int start = 0; 
        long long ans = 0;
        long long  pdt = 1; 
        bool flag = false;
        while(end<n){
            flag= true;
            pdt = pdt*arr[end];
            if(pdt<k){
                ans+=(end-start+1);
                end++; 
            }
            else {
                while(start<=end and pdt>=k){
                    pdt /= arr[start];
                    start++; 
                }
              
                ans += (end-start+1);
                
                end++; 
            }
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends