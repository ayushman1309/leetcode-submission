class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> min_damage(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        
        min_damage[0][0] = grid[0][0];
        dq.push_front({0, 0});
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            if (x == m - 1 && y == n - 1) {
                break;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int new_damage = min_damage[x][y] + grid[nx][ny];
                    
                    if (new_damage < min_damage[nx][ny]) {
                        min_damage[nx][ny] = new_damage;
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        
        return health - min_damage[m - 1][n - 1] >= 1;
    }
};