class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0 ;
        int max_end = nums[0] ;
        int min_end = nums[0] ;
        int res = nums[0] ;

        for(i=1 ; i<nums.size() ; i++){
            int v1 = nums[i] ;
            int v2 = min_end * nums[i] ;
            int v3 = max_end * nums[i] ;

            max_end = max(v1 ,max(v2 , v3)) ;
            min_end = min(v1 , min(v2 , v3)) ;

            res = max(res , max(max_end , min_end)) ;
        }
        return res ;
    }
};