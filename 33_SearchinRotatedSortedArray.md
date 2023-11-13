
Space Complexity : O(1)
Time Complexity : O(logN)

這題的技巧點在於轉移後的數組會被拆成兩邊, 而這兩邊會分別是獨立且升序排序的數組, 因此我們可以透過二分搜尋法  
透過不斷決定搜尋範圍來達到logN的複雜度。  
首先我們每次都要先判斷中點的左還是右是排序好的, 假設左邊是排序好的那我們接著要判斷該往左搜尋還是右邊  
判斷方式就是我們先判斷nums[mid]跟nums[left]的關係, 可以透過這個決定左還是右是排序好的,  
如果是左邊排序好 -> 判斷target是否小於nums[left] or target > nums[mid] -> 如果是則往右搜尋, 否則往左  
如果是右邊排序好 -> 判斷target是否大於nums[right] or target < nums[mid] -> 如果是則往左搜尋, 否則往右 





```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int left = 0, right = nums.size()-1;

       while (left <= right) {
           int mid = left + (right - left) / 2;
           if (target == nums[mid]) {
               return mid;
           }
           // left sorted portion
           if (nums[left] <= nums[mid]) {
               if (target > nums[mid] || target < nums[left]) {
                   left = mid + 1;
               } else {
                   right = mid -1;
               }
           } 
           // right sorted portion
           else {
               if (target < nums[mid] || target > nums[right]) {
                   right = mid - 1;
               } else {
                   left = mid + 1;
               }
           }  
       }
       return -1;
    }
};
```
