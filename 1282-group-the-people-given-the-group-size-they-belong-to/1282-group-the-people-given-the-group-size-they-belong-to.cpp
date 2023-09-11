class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
         
        vector <vector<int>> ans;

        vector <pair<int,int>> v;

        for ( int i=0; i<g.size(); i++ ) {
            v.push_back({g[i],i});
        }

        sort(v.begin(),v.end());

        int k = 0;

        for ( int i=0; i<v.size(); ) {

            vector <int> temp;

            for ( int j=0; j<v[i].first; j++ ) {
                temp.push_back(v[k++].second);
            }

            i = k;

            ans.push_back(temp);
        }

        return ans; 
         
    }
};