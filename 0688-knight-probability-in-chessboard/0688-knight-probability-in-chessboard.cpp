class Solution {
public:
    vector<vector<vector<double>>> dp;
    double rec(int i,int j,int n,int k){
        
        if (i<0 || j<0 || i>=n || j>=n)
            return 0;
        if (k==0)
            return 1;
        if (dp[i][j][k]!=-1)
            return dp[i][j][k];
        return dp[i][j][k] = 
               rec(i+2,j+1,n,k-1) +
               rec(i+2,j-1,n,k-1) +
               rec(i-2,j+1,n,k-1) +
               rec(i-2,j-1,n,k-1) +
               rec(i+1,j+2,n,k-1) +
               rec(i+1,j-2,n,k-1) +
               rec(i-1,j+2,n,k-1) +
               rec(i-1,j-2,n,k-1); 
    }
    double knightProbability(int n, int k, int row, int column) {
        if (k==0)
            return 1;
dp.resize(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double fav = rec(row,column,n,k);
        return fav/pow(8,k);}
};