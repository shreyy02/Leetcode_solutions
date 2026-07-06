class Solution {
public:
    int characterReplacement(string s, int k) {
        int high = 0;
        int low = 0;
        int n = s.size();
        int max_count = 0;
        int res = 0;
        std::unordered_map<char,int>f ;

        for(high=0 ; high<n ; high++){
            f[s[high]] ++;

            int len = high - low+ 1;
            max_count = max(max_count ,f[s[high]]);
            int diff = len - max_count ;

            while(diff>k){
                f[s[low]] --;
                low ++;

            len = high - low + 1 ;
            diff = len - max_count ;
            }
                len = high - low + 1;
                res = max(res , len);
            

        }
        return res ;
    }
};