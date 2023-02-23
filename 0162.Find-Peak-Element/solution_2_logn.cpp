// TC: O(n) SC:O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int left, right;
        left = 0;
        right = nums.size() - 1;
        while (left < right ) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < nums[mid+1]) {
            left = mid+1;
          }
          else {
            right = mid;
          }
        }
        return right;
    }
};
};