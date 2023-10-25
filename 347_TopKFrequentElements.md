
Space Complexity : O(n)
Time Complexity : O(n)

透過hashmap來記錄nums中數字的出現次數,創建一個二維vector, 並用出現次數來把對應的數字放入對應位置的vector中。這題我們可以得知一個數字最多只會出現 `nums.size()` 次, 因此在初始化二維vector時可以縮小空間。最後透過反向遍歷二維vector我們就能把出現次數前k個的數字加到答案中。 

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        int n = nums.size();
        // use hashmap to calculate the appear times
        unordered_map<int, int> table;
        for (int num : nums) {
            table[num]++;
        }

        vector<vector<int>> res(n+1); // vector used to do bucket sort
        vector<int> ans;
        for (auto pair : table) {
            res[pair.second].push_back(pair.first);
        }
        int k_cnt = 0;
        for (int i = n; i>0; i--) {
            for (int j = 0; j < res[i].size(); j++) {
                ans.push_back(res[i][j]);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return {};
    }
};
```
