class Solution {
public:
    long long int mySqrt(int x) {
        int start = 0;
        int end = x;
        long long int ans;
        while(start <= end)
        {
            long long int mid = start + (end - start)/2;
            if(mid*mid == x)
            {
                return  mid;
            }
            else if(mid*mid < x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};