
// TC: O(m*n) SC: O(1)
 
/*

SC(MN)  -> take a copy of the matrix and accroding to the original matrix,
 change the copy matrix

SC(M + N) -> take two arrays to store the row and column index of the zero

SC(1) -> use the first row and first column to store the row and column index of the zero
and use a variable to store the first row has zero or not
  */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int idx = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int temp=1;

        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
            int cur = matrix[i][j];
            if (cur == 0) {
              if (i == 0) {
                printf("%d", i);
                temp = 0;
              }
              else {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
              }
            }
          }
        }

        for (int i = 1; i < m; i++) {
          for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0 or matrix[i][0] == 0) {
              matrix[i][j] = 0;
            } 
          }
        }

        if (matrix[0][0] == 0) {
          for (int i = 0; i<m; i++) {
            matrix[i][0] = 0;
          }
        }
        if (temp == 0) {
          for (int i = 0; i < n; i++) {
            matrix[0][i] = 0;
          }
        }
    }
};