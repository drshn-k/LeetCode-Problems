//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		        int low=0;
            int high=0;
            int n=A.size();
            string ans="";
            unordered_map<char,int>mp;
            while(high<n)
            {
                mp[A[high]]++;
                while(low<high && mp[A[low]]>1)
                low++;
                if(mp[A[low]]>1)
                ans.push_back('#');
                else
                ans.push_back(A[low]);
                high++;
            }
            return ans; // Code here
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends