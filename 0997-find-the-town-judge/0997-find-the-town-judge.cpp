class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> v(n+1 , 1);
        
        for(auto i : trust){
            v[i[0]] = 0;
            v[i[1]]++;
        }
        
        int ans = -1;
        
        for(int i = 1 ; i < n+1; i++){
            if(v[i] == n) ans = i;
        }
        
        
        return ans;
        }
    
};