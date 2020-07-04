// Time Complexity : O(N)
// Space Complexity : O(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total=0;
    void helper(TreeNode* root,int sum){
        if(!root)
            return;
        sum=sum*10+root->val;
        if(!root->left && !root->right)
            total+=sum;
        else{
        helper(root->left,sum);
        helper(root->right,sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return total;
    }
};
