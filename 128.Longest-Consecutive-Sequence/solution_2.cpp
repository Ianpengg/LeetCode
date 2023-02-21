

// TC: O(n), SC: O(n)


class Solution {
public:
     int longestConsecutive(vector<int>& nums) {
        unordered_set<int> table(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : table) {
            if (!table.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (table.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
      }
};