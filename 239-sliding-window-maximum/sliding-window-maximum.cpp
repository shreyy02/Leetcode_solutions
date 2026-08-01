class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;      // stores indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove indices that are out of the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Record the maximum once the first window is complete
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};