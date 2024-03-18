class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       auto cmp=[](const auto& a, const auto& b){
            return a[1]<b[1];
        };
        sort(points.begin(), points.end(), cmp);

        int arrow=1, end=points[0][1];

        for(int i=1; i<points.size(); i++){
            if(points[i][0]>end){
                arrow++;
                end=points[i][1];
            }
        }
        return arrow;    
    }
};