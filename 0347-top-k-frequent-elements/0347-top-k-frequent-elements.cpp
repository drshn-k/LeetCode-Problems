class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> mp;
        for(auto i: nums)mp[i]++;
        vector<pair<int,int>> v;
        
        for(auto i: mp){
            pair<int, int> sam;
            sam = make_pair(i.second , i.first);
            v.push_back(sam);
        }
        
        sort(v.begin() , v.end());
        
        reverse(v.begin() , v.end());
        int i = 0 ;
        vector<int> ans;
        while(i < k ){
            ans.push_back(v[i].second);
            i++;
            
        }
        // for(auto i: v)cout << i.first << ' ' << i.second << endl; 
        
        return ans;
    }
};