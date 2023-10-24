
Space Complexity : O(1)
Time Complexity : O(n)

透過hashmap來記錄string 中字母的出現次數, 並且讀第二個字串的時候扣掉hashmap中對應的字母出現次數,最後檢查hashmap中是否還有0。

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        // construct a array of 26 which is the total alphabets
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (auto num:arr) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }
};
```
