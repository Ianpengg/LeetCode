// TC: O(n) , SC: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left, right;
        left = 0;
        right = nums.size()-1;
        vector<int> ans(nums.size(), 0);
        int p = nums.size() - 1;
        while (p >= 0) {
          if (abs(nums[left]) >= abs(nums[right])) {
            ans[p] = nums[left] * nums[left];
            left++;
            p--;
          }
          else {
            ans[p] = nums[right] * nums[right];
            right--;
            p--;
          }
        }
        return ans;

    }
};