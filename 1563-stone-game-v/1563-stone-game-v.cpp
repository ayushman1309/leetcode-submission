class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        //Precompute prefix sums
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i+1] = prefixSum[i] + stoneValue[i];
        }

        // Initialize DP table
        vector<vector<int>> dp(n,vector<int>(n, 0));

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for (int k = i; k < j; ++k) {
                    int sumleft = prefixSum[k+1] - prefixSum[i];
                    int sumright = prefixSum[j+1] - prefixSum[k+1];

                    int curr;
                    if (sumleft < sumright) {
                        curr = sumleft + dp[i][k];
                    } else if (sumright < sumleft) {
                        curr = sumright + dp[k+1][j];
                    } else { 
                        curr = sumleft + max(dp[i][k], dp[k+1][j]);
                    }
                    
                    dp[i][j] = max(dp[i][j], curr);
                }
            }
        }

        //The result is the maximum score for the entire array 
        return dp[0][n-1];
    }
};