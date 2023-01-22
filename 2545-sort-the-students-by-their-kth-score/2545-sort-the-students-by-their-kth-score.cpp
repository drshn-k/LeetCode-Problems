int in;
bool compare_col( vector<int>& v1, vector<int>& v2) 
{ 
    return v1[in] > v2[in]; 
} 
class Solution {
public:

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
         in = k;
     
        sort(score.begin(), score.end(),compare_col); 
        
        return score;
    }
};