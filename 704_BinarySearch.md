
Space Complexity : O(1)
Time Complexity : O(logn)

這題是最基本的二元搜索算法, 應用的前提是我們必須針對排序好的數組才能夠使用  
通常會需要設置兩個指標 left指向第一個元素 right指向最後一個元素  
並且在每次循環時 我們要求出兩個指標中間的數值 mid  
並且我們要根據數組中mid位置的元素跟target間的關係來決定該讓left 或 right移動  
這樣每次搜尋我們都會減少一半的搜尋半徑 因此可以達到O(logn)的時間複雜度

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    if (nums[left] == target) 
        return left;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } 
        else if (nums[mid] < target) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }

    }
    return -1;
    
    }
};
```
