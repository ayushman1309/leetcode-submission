class Solution {
public:
    void dfs(vector<vector<char>>& grid ,int r,int c){
        if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size() ||grid[r][c] == '0') return;

        // mark visited 
        grid[r][c] = '0';

        dfs(grid,r-1,c); //up
        dfs(grid,r+1,c);   //down
        dfs(grid,r,c+1); //right
        dfs(grid,r,c-1); //left

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    count++;

                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};