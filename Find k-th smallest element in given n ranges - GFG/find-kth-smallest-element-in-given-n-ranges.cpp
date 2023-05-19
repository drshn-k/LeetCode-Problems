//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>qq){
             vector<vector<int>> merge;
        sort(range.begin(), range.end());
        vector<int> temp = range[0];
        
        for(auto it: range){
            if(it[0] <= temp[1]){
                temp[1] = max(it[1],temp[1]);
            }
            else{
                merge.push_back(temp);
                temp = it;
            }
        }
        merge.push_back(temp);
        
        // making the difference array
        vector<int> diff;
        int sum = 0;
        for(auto it: merge){
            diff.push_back(it[1]-it[0]+1);
            sum+=it[1]-it[0]+1;
        }
        
        //making the pre difference array
        vector<int> prediff(diff.size(),0);
        prediff[0] = diff[0];
        for(int i=0;i<diff.size();i++){
            prediff[i] = diff[i] + prediff[i-1]; 
        }
        
        reverse(begin(prediff), end(prediff));
        prediff.push_back(0);
        reverse(begin(prediff), end(prediff));
        
        // cout<<"pre diff array: \n";
        // for(auto it: prediff)cout<<it<<" ";
        // cout<<"\n";
        
        //making the final ans
        vector<int> ans;
        
        for(int i=0;i<q;i++){
            if(qq[i] > sum){ // if the value is greater than size -1
                ans.push_back(-1);
            }
            else{
                for(int j=1;j<prediff.size();j++){
                    if(qq[i]<=prediff[j]){
                        int val = abs(qq[i] - prediff[j-1]);
                        ans.push_back(merge[j-1][0]+val-1);
                       break;
                    }
                }
            }
        }
        
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends