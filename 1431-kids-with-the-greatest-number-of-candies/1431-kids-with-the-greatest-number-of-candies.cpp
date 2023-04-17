class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxi = 0;
        int n = candies.size();
        for(auto i : candies){
            if(i > maxi)maxi = i;
        }
        
        vector<bool>ans;
        
        for(auto i : candies){
            if(i+extraCandies >= maxi)ans.push_back(1);
            
            else ans.push_back(0);
        }
     
        return ans;
    }
};