class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low = 0;
        int high = k-1;
        int n = arr.size();
        int sum = 0;
        
        for(int i=low ; i<= high ; i++)
            sum = sum + arr[i];
            
            int res = sum;
            
        while(high < n){
            res = max(res, sum);
            low++;
            high++;
            
            if(high == n)
                break;
            sum = sum - arr[low-1];
            sum = sum + arr[high];
            
        }
        return res;
    }
};