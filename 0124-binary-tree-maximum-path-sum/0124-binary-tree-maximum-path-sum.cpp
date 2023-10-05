#include <bits/stdc++.h>

class Solution {
public:
    int maxPathSum(TreeNode* root , int &maxi){
        if(root == NULL) return 0 ; 

        int maxL = maxPathSum(root->left,maxi) ; 
        int maxR = maxPathSum(root->right,maxi) ;
        if(maxL < 0) 
           maxL = 0 ; 
        if(maxR < 0)
           maxR = 0 ; 
        int maxRoot = root->val + maxL + maxR ; 

        maxi = max(maxi,maxRoot) ; 

        return root->val + max(maxL,maxR) ; 
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN ; 

        maxPathSum(root,maxi) ; 

        return maxi ;
    }
};