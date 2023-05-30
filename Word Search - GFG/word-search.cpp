//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   void dfs( vector<vector<char>>& board , int i , int j , int ind , string &word , bool &flag )
    {
        if( i < 0 or j < 0 or i >= board.size() or j >= board[0].size()) return ;
        
        if( board[i][j] != word[ind] ) return ;
        
        if( ind == word.size() - 1 )
        {
            flag = true ;
            return ;
        }
        
        char c = board[i][j] ;
        board[i][j] = '#' ;
        
        dfs( board , i+1 , j , ind+1 , word , flag ) ;
        dfs( board , i-1 , j , ind+1 , word , flag ) ;
        dfs( board , i , j-1 , ind+1 , word , flag ) ;
        dfs( board , i , j+1 , ind+1 , word , flag ) ;
        
        board[i][j] = c ;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        for( int i = 0 ; i < board.size() ; i++ )
        {
            for( int j =0 ; j < board[i].size() ; j++ )
            {
                if( board[i][j] == word[0] )
                {
                    bool flg = false ;
                    dfs( board , i , j , 0 , word , flg ) ;
                    if(flg) return true ;
                }
            }
        }
        
        return  false ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends