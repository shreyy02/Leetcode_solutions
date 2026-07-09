class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;

            nodelete = max(prevnodelete + arr[i], arr[i]);

            if (prevonedelete == INT_MIN)
                onedelete = prevnodelete;   // delete current element
            else
                onedelete = max(prevnodelete, prevonedelete + arr[i]);

            ans = max(ans, max(nodelete, onedelete));
        }

        return ans;
    }
};