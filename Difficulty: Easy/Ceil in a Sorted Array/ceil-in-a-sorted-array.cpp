class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int low = 0;
        int high = arr.size() - 1 ;
        int result = -1 ;
        
        while (low <= high ){
            int guess = (low+high) / 2;
            
            if(arr[guess] >= x ){
            high = guess - 1 ;
            result = guess ;
            }
            else{
            low = guess + 1 ;
            }
        }
        return result ;
    }
};