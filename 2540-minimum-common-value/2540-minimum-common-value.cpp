class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
         int n1 = 0, n2 = 0;

        if(nums1[nums1.size() - 1] < nums2[0] || nums2[nums2.size() - 1] < nums1[0]) return -1;

        while(n1 < nums1.size() && n2 < nums2.size()){
            if(nums1[n1] == nums2[n2]) return nums1[n1];
            if(nums1[n1] > nums2[n2]) n2++;
            else if(nums1[n1] < nums2[n2]) n1++;
        }

        return -1;
    }
};