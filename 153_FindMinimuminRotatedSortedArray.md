
Space Complexity : O(1)
Time Complexity : O(log(N))

這題也是先排序好的數組, 然後會隨機旋轉n次, 會把原本排序好的數組分成兩部分,  
ex: 5, 6, 7, 1, 2, 3, 4, 要找出最小值的話可以透過比較中間值跟 right的元素比較, 如果中間值比較大那代表說那右半邊才可能出現最小值,
可以把left移到mid+1的位置, 反之則將right移到mid-1的位置,  
並且搜索區間是[left, right) left <= x < right  因此 [left, left-1)為空即停止
 
```c++
class Solution {
public:
    int findMin(vector<int>& nums) {

       int left = 0, right = nums.size() - 1;

       // if array is non-rotated return first element
        if (nums[left] <= nums[right]) {
            return nums[left];
        }
        while (left < right) {
           int mid = left + (right - left) / 2;
           // check if the mid element is the minumum
           // since the array is ascending order so the right element would be greater than left,
           // if we want to check the mid is the max or not, we need to compare it with its left element.
           if (mid - 1 >= 0 && nums[mid] < nums[mid-1]) {
               return nums[mid];
           }
           
           // check which partition should be searched
           // mid >
           if (nums[mid] > nums[right]) {
               left = mid+1; 
           } else {
               right = mid-1;
           }
       } 
       return nums[left];
    }
};
```
