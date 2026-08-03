class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for (int num : nums) {
            while (!st.empty() && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            }
            st.push_back(num);
        }

        st.resize(k);
        return st;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (lexicographical_compare(a.begin() + i, a.end(),
                                        b.begin() + j, b.end())) {
                ans.push_back(b[j++]);
            } else {
                ans.push_back(a[i++]);
            }
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans;

        int start = max(0, k - n);
        int end = min(k, m);

        for (int i = start; i <= end; i++) {
            vector<int> a = maxSubsequence(nums1, i);
            vector<int> b = maxSubsequence(nums2, k - i);

            vector<int> cur = merge(a, b);

            if (cur > ans)
                ans = cur;
        }

        return ans;
    }
};