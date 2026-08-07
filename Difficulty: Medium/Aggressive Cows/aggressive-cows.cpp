class Solution {
  public:
    bool fun(vector<int> &stalls , int n , int k , int guess){
        int cow = 1 ;
        int i = 0 ;
        int pos = stalls[i] ;
        
        for( i = 0 ; i < n ; i++)
        {
            int dist = stalls[i] - pos ;
            if(dist < guess)
            continue ;
            
            cow ++ ;
            pos = stalls[i] ;
        }
        if(cow >= k)
        return true ;
        else
        return false ; 
    }
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size() ;
        std :: sort(arr.begin() , arr.end()) ;
        
        int low = 1 ;
        int high = arr[n-1] - arr[0] ;
        int res = -1 ;
        
        while(low<=high){
            int guess = (low + high) / 2 ;
            
            if(fun(arr , n , k , guess)){
                res = guess ;
                low = guess + 1 ;
            }
            else {
                high = guess - 1 ;
            }
        }
        return res ;
        
    }
};