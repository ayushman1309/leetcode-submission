class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r , int c , int i){
        if(i == word.size()) return true;
        // out of bound 
        if(r<0 || r>=board.size() || c<0 || c>= board[0].size()) return false;

        // wrong char
        if(board[r][c] != word[i]) return false;

        char mark = board[r][c];
        board[r][c] = '#';
        if (dfs(board, word, r-1, c, i + 1) ||  // up
            dfs(board, word, r+1, c, i+ 1) ||   // down
            dfs(board, word, r, c-1, i + 1) ||  // left
            dfs(board, word, r, c+1, i + 1))   // right
                return true;
        
        board[r][c] = mark;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (dfs(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }
};