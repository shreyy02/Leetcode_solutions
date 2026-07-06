class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> target;
        unordered_map<char, int> window;
        
    for (char c : t)
            target[c]++;

        int required = target.size(); // Number of unique characters
        int formed = 0;               // Number of characters meeting required frequency

        int low = 0;
        int start = 0;
        int minLen = INT_MAX;

        for (int high = 0; high < s.size(); high++) {

            char c = s[high];
            window[c]++;

            // Character frequency just reached the required count
            if (target.count(c) && window[c] == target[c])
                formed++;

            // Try shrinking the window
            while (formed == required) {

                if (high - low + 1 < minLen) {
                    minLen = high - low + 1;
                    start = low;
                }

                char leftChar = s[low];
                window[leftChar]--;

                // Window is no longer valid
                if (target.count(leftChar) &&
                    window[leftChar] < target[leftChar])
                    formed--;

                low++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};