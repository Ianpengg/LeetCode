
// TC: O(n)  SC: O(n

class Solution {
public:
    bool isValid(string s) {
        stack<int> store;
        for (const char ch: s) {
          if (ch == '(' || ch=='{' || ch =='[') {
            store.push(ch);
          }
          else {
            if (store.empty()) return false;
            if (ch == ')' && store.top() != '(' ) return false;
            if (ch == '}' && store.top() != '{' ) return false;
            if (ch == ']' && store.top() != '[' ) return false;
            store.pop(); 
          }
        }
        return store.empty();
    }
};