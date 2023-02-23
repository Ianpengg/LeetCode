class Solution {

// TC:O(m + n) SC:O(1)

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0) return false;
        if (n == 0) return false;
        int i = m-1, j = 0;
        while (i >= 0 && j < n) {
          if (matrix[i][j] == target) return true; 
          if (matrix[i][j] > target) {
              i--;
          }
          else {
              j++;
          }
        }
        return false;    
    }
};