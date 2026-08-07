class Solution {
public:
    long long fun(vector<int>& piles ,int n , int speed)
    {
        long long hour = 0 ;
        for(int i = 0 ; i<n ; i++){
            hour +=  piles[i] / speed ;
            if(piles[i] % speed != 0 )
            hour ++ ;
        }
        return hour ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size() ;
        int low = 1 ;
        int high = *max_element(piles.begin() , piles.end()) ;
        int res = high ;

        while(low <= high){
            int guess = (low+high) / 2 ;
            long long hour = fun(piles,n,guess) ;

            if(hour > h) {
                low = guess + 1;
            }
            else {
                res = guess;
                high = guess - 1;
            }
        }
        return res ;
    }
};