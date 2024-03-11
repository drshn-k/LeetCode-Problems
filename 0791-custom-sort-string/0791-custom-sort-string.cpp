class Solution {
public:
    string customSortString(string order, string s) {
            unordered_map<char, int> mp;
        string res = "";

        for (auto c : s) {
            mp[c]++;
        }
        for (int i = 0; i < order.size(); i++) {
                res += string(mp[order[i]], order[i]);
                mp[order[i]] = 0;
        }
        for (auto it : mp) {
            if (it.second != 0)
                res += string(it.second, it.first);
        }
        return res;
    }
};