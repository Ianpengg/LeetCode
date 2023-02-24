
// TC: O (n) SC: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left < right ) {
          if (nums[left]+ nums[right] == target) return {left+1, right+1};
          if (nums[left] + nums[right] > target) {
            right--;
          }
          else {
            left++;
          }
        }
        return {};
    }
};