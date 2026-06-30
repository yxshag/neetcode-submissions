class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start_idx = 0;
        int max_len = 1;

        // Base case:all single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Base Case:find all 2 character palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start_idx = i;
                max_len = 2;
            }
        }

        //memoisation
        for (int len = 3; len <= n; len++) { 
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Ending index
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    // Update our tracking for the longest substring found
                    if (len > max_len) {
                        start_idx = i;
                        max_len = len;
                    }
                }
            }
        }
        return s.substr(start_idx, max_len);
    }
};