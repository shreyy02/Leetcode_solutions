class Solution {
  public:
    bool func(vector<int> &books, int n, long long limit, int k){
        int students = 1;
        long long page = 0;

        for(int i = 0; i < n; i++){
            if(books[i] > limit) return false;

            if(page + books[i] <= limit){
                page += books[i];
            } else {
                students++;
                page = books[i];
            }
        }
        return students <= k;
    }

    int findPages(vector<int> &books, int k) {
        int n = books.size();
        if(n < k || k == 0) return -1;

        long long low = 0, high = 0;
        for(int i = 0; i < n; i++){
            low = max(low, (long long)books[i]);
            high += books[i];
        }

        long long res = -1;
        while(low <= high){
            long long guess = low + (high - low) / 2;
            if(func(books, n, guess, k)){
                res = guess;
                high = guess - 1;
            } else {
                low = guess + 1;
            }
        }
        return (int)res;
    }
};