class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums1.size(),m = nums2.size();
        int i=0,j=0;
        map<pair<int,int>,bool> mp;
        pq.push({nums1[0]+nums2[0],0,0});
        vector<vector<int>> ans;
        while(ans.size()<k && !pq.empty())
        {
            int x = pq.top()[1];
            int y = pq.top()[2];
            ans.push_back({nums1[pq.top()[1]],nums2[pq.top()[2]]});
            pq.pop();
            if(x+1<n && mp.find({x+1,y})==mp.end())
            {
                mp[{x+1,y}] = true;
                pq.push({nums1[x+1]+nums2[y],x+1,y});
            }

            if(ans.size()<k && y+1<m && mp.find({x,y+1})==mp.end())
            {
                mp[{x,y+1}] = true;
                pq.push({nums1[x]+nums2[y+1],x,y+1});
            }
            // cout << x << " " << y << endl;
        }
        // cout << endl;
        return ans;
    }
}; 