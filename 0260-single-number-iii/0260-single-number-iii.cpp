class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
          sort(nums.begin(), nums.end());
    vector<int> answer;
    int n = nums.size();
    int i = 0, j = 1;

    while(j < n)
    {
        if(nums[i] == nums[j])
        {
            i += 2;
            j += 2;
        }
        else
        {
            answer.push_back(nums[i]);
            i += 1;
            j += 1;
        }
    }
    if(i == n-1)    answer.push_back(nums[i]);
    return answer;

    }
};