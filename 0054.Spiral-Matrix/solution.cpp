
// TC O(mn)  SC: O(mn) if ans is considered as extra space


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int bottom = matrix.size(); //row
        int right = matrix[0].size(); //col
        int left = 0, top = 0, cnt = 0; 
        vector<int> res(bottom * right);  
        while(top < bottom && left < right)
        {
          for (int i=left; i < right; i++) {
            res[cnt++] = matrix[top][i];
          }
          top++;
          for (int i=top; i < bottom; i++) {
            res[cnt++] = matrix[i][right-1];
          }
          right--;
 
          if (!(top < bottom && left < right ))
            break;

          for (int i =right-1; i>=left; i--) {
            res[cnt++] = matrix[bottom-1][i];
          } 
          bottom--;
          for (int i = bottom-1; i >= top;i--) {
            res[cnt++] = matrix[i][left];
          }
          left++;
        } 
        return res;
    }
};