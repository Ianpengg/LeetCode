
Space Complexity : O(n)
Time Complexity : O(n)

這題可以用unordered_map來紀錄遍歷過的數字跟他的下標, 並且在每一次循環時計算target - nums[i]的值, 同時檢查hash_map中有沒有已經訪問過  
若是訪問過的話就直接回傳當下的index: i 跟已經儲存在hash_map中的 hash_map[temp]  
若沒有訪問過則新增 nums[i]跟對應的下標index到hash_map中


```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if (m.find(temp) != m.end()) {
                return {i, m[temp]};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};

```
