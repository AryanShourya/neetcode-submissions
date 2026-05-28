class Solution {
public:
    bool ans = false;
    set<pair<int,int>> visited;
    bool solve(vector<vector<char>>& board,int i,int j,string word,int l){
        if(word.length()==l){
            //ans = true;
            return true;
        }
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited.count({i,j})){
            return false;
        }

        visited.insert({i,j});
        if(board[i][j] == word[l]){
            //word.erase(word.begin()+0);
            ans = (solve(board,i,j-1,word ,l+1) || solve(board,i,j+1,word,l+1) || 
                    solve(board,i-1,j,word,l+1) || solve(board,i+1,j,word,l+1)
            );
        }

        visited.erase({i,j});
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++ ){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(solve(board,i,j,word,0)){
                        return true;
                    }
                }
            }
        }

        return ans;     
    }
};
