class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j]) {

                    if (j - i <= 2)
                        pal[i][j] = true;
                    else
                        pal[i][j] = pal[i + 1][j - 1];
                }
            }
        }

        vector<int> dp(n);

        for (int i = 0; i < n; i++) {

            if (pal[0][i]) {
                dp[i] = 0;
            } else {

                dp[i] = i;

                for (int j = 0; j < i; j++) {

                    if (pal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};