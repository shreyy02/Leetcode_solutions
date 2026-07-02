class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
   
   
   
        for(int i = 0 ; i<n-2 ; i++) {
            if(i>0 and nums[i] == nums[i-1])
                continue;

            int left = i+1 ;
            int right = n-1 ;
            int sum = -1*nums[i];

            while(left<right){
                int s = nums[left] + nums[right];

                if (s == sum){
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;


                    while(left<n and nums[left] == nums[left-1])
                        left++;

                    while(right>=n and nums[right] == nums[right+1])
                        right-- ;
                }
                else if(s<sum){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return res;
    
    }
};