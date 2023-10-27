
Space Complexity : O(1)
Time Complexity : O(1)

檢查valid sudoku的流程主要分三個部分:  
1. 每個row不能有重複數字
2. 每個col不能有重複數字
3. 每個3x3 block 不能有重複數字

因此可以利用 unordered_set的方式來記錄數字是否重複出現過來判斷valid sudoku  
主要的trick會在判斷3x3 block時, 我們需要遍歷9x9的vector並判斷當前的`[row][col]` 是屬於第幾個block 並將其加入對應的unordered_set中  
可以用 `int loc = (row / 3) * 3 + col / 3;` 來判斷其所在的block 其他就是照著邏輯去寫  



```c++

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row<9; row++) {
            unordered_set<char> check_row;
            for (int col = 0; col<9; col++) {
                if (board[row][col] != '.' && check_row.find(board[row][col]) != check_row.end()) {
                    return false;
                }
                check_row.insert(board[row][col]);

            }
        }
        
        for (int col = 0; col<9; col++) {
            unordered_set<char> check_col;
            for (int row = 0; row<9; row++) {
                if (board[row][col] != '.' && check_col.find(board[row][col]) != check_col.end()) {
                    return false;
                }
                check_col.insert(board[row][col]);

            }
        }
        vector<unordered_set<char>> check_subbox(9);
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // iterate through each element in subbox
                int loc = (row / 3) * 3 + col / 3;
                if (board[row][col] != '.' && 
                check_subbox[loc].find(board[row][col]) != check_subbox[loc].end()) {
                    return false;
                }
                check_subbox[loc].insert(board[row][col]);
            }
        }
        return true;

    }
};

```
