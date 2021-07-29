// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size(), i, j, cd, res = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for(i = 0; i < n; i++) {
            // Compute dp[i]
            for(j = i-1; j >= 0; j--) {
                cd = A[i] - A[j];
                if (dp[j].find(cd) == dp[j].end())
                    dp[i][cd] = max(dp[i][cd], 2);
                else
                    dp[i][cd] = max(dp[i][cd], 1+dp[j][cd]);
                
                res = max(res, dp[i][cd]);
            }
        }
        
        return res;
    }
};