class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int maxIsland = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    maxIsland = max(maxIsland, dfs(grid, visited, r, c));
                }
            }
        }

        return maxIsland;        
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        int rows = grid.size(), cols = grid[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || grid[r][c] == 0) {
            return 0;
        }

        visited[r][c] = true;
        return 1 + dfs(grid, visited, r + 1, c) + dfs(grid, visited, r - 1, c)
                 + dfs(grid, visited, r, c + 1) + dfs(grid, visited, r, c - 1);
    }
};