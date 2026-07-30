class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(string &s, int start) {

        // Base Case
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible substring
        for (int end = start; end < s.size(); end++) {

            // Check if current substring is palindrome
            if (isPalindrome(s, start, end)) {

                // Choose
                path.push_back(s.substr(start, end - start + 1));

                // Explore
                backtrack(s, end + 1);

                // Unchoose (Backtrack)
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        backtrack(s, 0);
        return ans;
    }
};