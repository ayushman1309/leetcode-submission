class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int x = 0, y = 0;
        int dx = 1, dy = 0; // movinf right

        vector<int> res;
        for (int i = 0; i < rows * cols; i++) {
            res.push_back(matrix[y][x]); // initial put 1st position in matrix
            matrix[y][x] = -101;//after pushing it mark them visited
            if (x + dx < 0 || x + dx >= cols ||
                y + dy < 0 || y + dy >= rows ||
                matrix[y + dy][x + dx] == -101) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            x += dx;
            y += dy;
        }
        return res;
    }
};