
Space Complexity : O(n)
Time Complexity : O(n)

透過hash set來儲存遍歷過的值
如果重複的話就直接return true;

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for (auto &num : nums) {
            if (m.find(num) == m.end()) {
                m.emplace(num);
            } else {
                return true;
            }

        }
        return false;
    }
};
```
