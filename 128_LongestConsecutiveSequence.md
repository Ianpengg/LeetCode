
Space Complexity : O(n)
Time Complexity : O(n)

利用hash_map先把全部數字存進去, 遍歷hash_map並檢查“每個數字減一”的結果是否存在hash_map中  
這是為了確定我們一定是從連續序列的第一個元素開始計算長度, 並且降低計算複雜度  
確定前一個數字不存在hash_map中之後, 我們可以從當前數字逐漸加一並同時檢查hash_map中是否有此數字  
在檢查同時累計連續序列的長度, 最後回傳最長的結果  




```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_map;
        for (auto num : nums) {
            hash_map.insert(num);
        }

        int res = 0;

        for (int num : hash_map) {
            // check the possible start number
            if (hash_map.count(num-1)) {
                continue;
            }

            // calculate the length of each consecutive sequence
            int count = 1;
            int temp = num;
            while (hash_map.count(temp+1)) {
                temp++;
                count++; 
            }
            
            res = max(res, count);
        }
        return res;
    }
};

```
