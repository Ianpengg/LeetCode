// TC: O(n), SC: O(n)

class Solution {
  vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root != NULL) {
          postorderTraversal(root->left);
          postorderTraversal(root->right);
          ans.push_back(root->val);
        }
        return ans;
    }
};