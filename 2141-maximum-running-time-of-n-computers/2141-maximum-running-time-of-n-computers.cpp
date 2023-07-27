class Solution {
public:
    using ll = long long;
    long long maxRunTime(int n, vector<int>& batteries) {
        ll res;
        if (batteries.size() == n) {
            res = *std::min_element(batteries.cbegin(), batteries.cend());
        } else {
            std::sort(batteries.begin(), batteries.end());
            auto last = batteries.cend() - 1;
            auto it = batteries.cend() - n;
            res = *it;
            ll sum = std::accumulate(batteries.cbegin(), it, 0LL);
            int i = 1;
            while (it != last) {
                ll curr = (*(it + 1) - *it) * i;
                if (curr <= sum) {
                    res = *(it + 1);
                    sum -= curr;
                } else {
                    res += sum / i;
                    sum = 0;
                    break;
                }
                ++it;
                ++i;
            }
            res += sum / i;
        }
        return res;
    }
};