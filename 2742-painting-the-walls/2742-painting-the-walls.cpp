class Solution {
public:
    int dp[501][501];

    int minCost(vector<int>&cost, vector<int>&time, int index, int target){

        if(index >= cost.size()){
            if(target == 0)
                return 0;
            return 1e9;
        }

        if(dp[index][target]!=-1)
            return dp[index][target];

        int res = 1e9;
        // not take
        res = min(res, minCost(cost, time, index+1, target));

        // take
        int val = min(target, 1+time[index]);
        res = min(res, cost[index] + minCost(cost, time, index+1, target-val));

        return dp[index][target] = res;
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return minCost(cost, time, 0, cost.size());
    }
};