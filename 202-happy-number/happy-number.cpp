class Solution {
public:
        int func(int n ){
            int sum = 0;
            while(n>0){
                int d = n % 10;
                n = n/10;
                sum = sum + d*d ;
            }
            return sum ;
        }
        bool isHappy(int n) {
        int slow = n ;
        int fast = n ;

        while(fast!=1){
            slow = func(slow);
            fast = func(func(fast)) ;

            if(slow == fast and slow != 1){
                return false;
            }    
        }
            fast = 1;
            return true ;  
    }
};