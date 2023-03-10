
// TC: O(nlogn) SC: O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int curr = 1;
        int maxi = 0;
        sort(nums.begin(), nums.end());
        if (n == 0) {
            return 0;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] == (nums[i-1] + 1)) {
                curr++;
            } else if (nums[i] != (nums[i-1])) {
                maxi = max(maxi, curr);
                curr = 1;
            }        
        }
        maxi = max(maxi, curr);
        return maxi;
    }
};