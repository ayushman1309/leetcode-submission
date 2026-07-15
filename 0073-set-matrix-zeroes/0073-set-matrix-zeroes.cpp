class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool Zero = false;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int r=0;r<n;r++){
            if(matrix[r][0] ==0) Zero = true;
            for(int c=1; c < m;c++){
                if(matrix[r][c] == 0){
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for(int r=n-1;r>=0;r--){
            for(int c=m-1;c>=1;c--){
                if(matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
            }
            if(Zero) matrix[r][0] = 0;
        }
    }
};