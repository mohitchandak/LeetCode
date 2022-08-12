class Solution {
public:
    int mySqrt(int x) {
        
        
        //using stl
        //return sqrt(x);
        
        
        //Binary Search
        int lo = 0 , hi = x, ans = -1 ;
        while(lo <= hi){
            long long  mid = lo + (hi-lo) / 2 ;
            if(mid * mid <= x) ans = mid , lo = mid + 1 ;
            else hi = mid - 1 ;
        }
        return ans ;
    }
};