
Space Complexity : O(n)
Time Complexity : O(1)

首先此題的重點是空間複雜度必須是 O(1) 也就意味著我們不能用hash_map的方式來處理  
又因為輸入vector為排序過的元素, 因此我們可以利用2 pointers的方法來做  
首先設置left 跟 right兩個指針, 指向第一個及最後一個元素  
這時我們可以透過比較 nums[left] 跟 nums[right]的和跟target的關係來決定指針要往哪邊縮  
ex: 如果 nums[left] + nums[right] > target 那就表示我們的nums[right]太大, 因此right就要減一  
依照此循環遍歷完所有元素我們就可以找到最後的答案  


```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      
        int left = 0, right = numbers.size() -1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum > target) {
                right--;
            } 
            else if (sum < target) {
                left++;
            } else {
                return {left+1, right+1};
            }
        }
        
        return {};
    }
};

```
