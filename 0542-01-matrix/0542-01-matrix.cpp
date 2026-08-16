class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int ,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) q.push({i,j});  // put all 0 in q
                else mat[i][j] = -1; // not visited
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            auto[i,j] = q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int ni = i+dr[d];
                int nj = j+dc[d];

                if(ni<0||ni>=n || nj<0 || nj>=m) continue;

                if(mat[ni][nj] != -1) continue;

                // distance 
                mat[ni][nj] = mat[i][j]+1;
                q.push({ni,nj});

            }
        }
        return mat;
    }
};