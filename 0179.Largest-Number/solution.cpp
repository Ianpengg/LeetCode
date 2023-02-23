
// TC: O(nlogn) SC:(1)
// Concept 4-32 > 32-4  so 4 > 32
// Concept  4-32 > 32-4 so 4 > 32  and if 32-1 > 1-32 then 32 > 1, so 4 > 32 > 1
class Solution {
public:
    static bool sortString(int a, int b) {
      string a1 = to_string(a);
      string b1 = to_string(b);
      return ( a1+b1 > b1+a1);
    }
    string largestNumber(vector<int>& nums) {
       
        string ans; 
        sort(nums.begin(), nums.end(), sortString);
        if (nums[0] == 0) return "0";
        for (int i = 0; i < nums.size(); i++) {
          ans += to_string(nums[i]);
        }
        return ans;
    }
};