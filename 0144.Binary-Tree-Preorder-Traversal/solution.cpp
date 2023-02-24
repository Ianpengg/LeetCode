
// TC: O(n)  SC: O(n)

class Solution {
  vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root != NULL) {
          ans.push_back(root->val);
          preorderTraversal(root->left);
          preorderTraversal(root->right);
        }
        return ans;
    }
};