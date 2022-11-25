//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	  int cur = 0, res = 0;
        int n = nums.size();
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    left[i] = max(left[i], left[j] + 1);
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--)
                if (nums[j] < nums[i])
                    right[i] = max(right[i], right[j] + 1);
        }
        for (int i = 0; i < n; i++)
            res = max(res, left[i] + right[i] + 1);
        return res;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends