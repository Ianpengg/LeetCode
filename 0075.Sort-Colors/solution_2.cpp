
//  TC: O(n) SC: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
      unordered_map<int, int> table;
      for (auto &num:nums) {
        table[num]++;
      }
      int cur = 0;
      for (int i = 0; i<3; i++) {
        for (int j = 0; j < table[i];j++) {
          nums[cur] = i;
          cur++;
        } 
      }
    }
};