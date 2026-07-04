class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        int k = 2;
        int n = fruits.size();
        std ::unordered_map<int,int>f ;
        int res = 0;
        
        for(high=0 ; high<n ; high++){
            f[fruits[high]] ++ ;
            
        while(f.size() > k){
            f[fruits[low]] -- ;
            if(f[fruits[low]] == 0){
            f.erase(fruits[low]);
            }
            low ++;
        }
    
            int len = high - low +1;
            res = max(res,len);
        
        }
        return res;
    }
};