

// Time Complexity: O(nlogn), Space Complexity: O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int i;
        sort(nums.begin(), nums.end());
        for(i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};