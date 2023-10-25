
Space Complexity : O(n)
Time Complexity : O(n)

透過unordered_map的哈希表來儲存每個anagram對應的vector index
每個單字都要先做排序, 因為同樣anagram排序完就會是一樣的
哈希表中如果沒有出現過那就幫這個anagram新增一個key,
value則是儲存該anagram在result vector 中的index,
出現過則在對應index的vector中把字串加入.
沒出現過的話 把一個空的vector加到result後面 (因此res.size()會+1)
```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> res;
        for (string s:strs) {
            string temp = s;
            sort(temp.begin(), temp.end());

            if (!map.count(temp)) {
                map[temp] = res.size();
                res.push_back({});
            }
            res[map[temp]].push_back(s);
        }

        return res;
    }
};
```
