using ll = long long;
const int mx = 1e5 + 5;

class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> left, right;
        int n = cost.size(), l = candidates, r = n - candidates;
        if(l >= r) r = l;
        for(int i = 0; i < l; i++){
            left.push(cost[i]);
        }
        for(int i = n - 1; i >= r; i--){
            right.push(cost[i]);
        }
        ll ans = 0;
        for(int i = 0; i < k; i++){
            int lc = mx, rc = mx;
            if(!left.empty()) lc = left.top();
            if(!right.empty()) rc = right.top();
            if(rc < lc){
                ans += rc;
                right.pop();
                if(l < r) right.push(cost[--r]);
            }
            else{
                ans += lc;
                left.pop();
                if(l < r) left.push(cost[l++]);
            }
        }
        return ans;
    }
};