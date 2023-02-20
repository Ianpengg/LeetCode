
// TC: O(logn) SC:O(1)


class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        if (num==1 ) return true;

        while (left < right) {
            long long int mid = left + (right - left) / 2;
            if (mid * mid  > num) {
                right = mid;
            } 
            else if (mid* mid < num){
                left = mid+1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};