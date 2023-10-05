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
    int i=1;
    long x=LONG_MIN;

    void inorder(TreeNode* root){
        if(root==NULL || i==0){return;}
        inorder(root->left);
        if(root->val<=x){i=0;return;}
        else{x=root->val;}
        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        root->left=NULL;root->right=NULL;x=0;
        return i;
    }
};