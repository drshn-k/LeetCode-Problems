class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        vector<int> ans(n,0);
        vector<int> temp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    ans[i]++;
                }
                else if(mat[i][j]==0){
                    break;
                }
            }
        }
    
        for(int i=0;i<k;i++){
            int min=INT_MAX;
            int minIndex=-1;
            for(int j=0;j<ans.size();j++){
                if(min>ans[j]){
                    min=ans[j];
                    minIndex=j;
                }
            }
            temp.push_back(minIndex);
            ans[minIndex]=105;
        }
        return temp;
    }
};