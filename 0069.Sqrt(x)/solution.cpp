

// TC: O(logn) SC: O(1)

class Solution {
 public:
  int mySqrt(int x) {
    int l, r;
    if (x == 0 || x == 1)
      return x;
    l = 0;
    r = x;
    while (l < r) {
      long long int mid = l + (r - l) / 2;
      if (mid * mid > x) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l - 1;
  }
};