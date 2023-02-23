

// TC: O(n), SC: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int left = 0;
        int right = -1;
        int n = nums.size();
        int t = k%n; 
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + t);
        reverse(nums.begin()+t, nums.end());

        
    }
};