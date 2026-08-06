class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 ;
        int high = nums.size() - 1 ;
        int res = -1 ;

        while(low <= high){
            int guess = (low + high) /2 ;

            if(nums[guess] > nums[nums.size() - 1])  //part 1 
            {
            low = guess + 1 ;
            }
            else                                    // part 2
            {
                res = guess ;
                high = guess - 1 ;
            }
        }
        return nums[res] ;
    }
};