
// TC: O(n) SC: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right = height.size()-1, res=0;
        while (left < right) {
          int h = min(height[left], height[right]);
          res = max(res, h * (right - left));
          while ( left < right && h  == height[left]) ++left;
          while ( left < right && h == height[right]) --right;
          
        }
        return res;
    }
};

