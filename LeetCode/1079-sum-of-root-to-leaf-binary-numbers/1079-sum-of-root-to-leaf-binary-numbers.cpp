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
private: 
    void getSum(TreeNode* root, long long& sum, long long num) {

        if(root == nullptr) 
            return ;
        
        
        int f = num << 1 | (root -> val);
        // f = num;
        if((root -> left == nullptr) and (root -> right == nullptr)) 
            sum = sum + f;
        getSum(root -> left, sum, f);
        getSum(root -> right, sum, f);
        
    

    }
public:
    int sumRootToLeaf(TreeNode* root) {
        long long s = 0, n = 0;
        getSum(root, s, n);
        //  ans = ans >> 1;
        return s;
    }
};