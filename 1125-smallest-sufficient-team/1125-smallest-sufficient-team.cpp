class Solution {
public:
    typedef long long int64;
    vector<int> smallestSufficientTeam(vector<string>& reqSkills, vector<vector<string>>& people) {
        int n = reqSkills.size();
        int m = people.size();

        map<string, int> skillMap;
        for(int i = 0; i < n; i++) {
            skillMap[reqSkills[i]] = i;
        }
        map<int, int64> peopleSkill;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < (int)people[i].size(); j++) {
                peopleSkill[i] |= (1 << skillMap[people[i][j]]);
            }
        }

        vector<int64> dp(1 << n, (1LL << m) - 1);
        dp[0] = 0;
        for(int skillMask = 1; skillMask < (1 << n); skillMask++) { // skills
            // consider each person
            for(int j = 0; j < m; j++) {
                int64 smallerSkillMask = skillMask & ~(peopleSkill[j]);
                if(smallerSkillMask != skillMask) {
                    int64 peopleMask = dp[smallerSkillMask] | (1LL << j);
                    if(__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillMask])) {
                        dp[skillMask] = peopleMask;
                    }
                }
            }
        }

        int64 peopleMask = dp[(1 << n) - 1];
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            if((peopleMask >> i) & 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};