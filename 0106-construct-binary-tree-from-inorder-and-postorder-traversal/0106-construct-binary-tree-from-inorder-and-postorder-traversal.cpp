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
    int search(int data , vector<int>& arr){
        for(int i = 0 ; i < arr.size() ; i++){
            if(data == arr[i])
                return i ; 
        }
        return -1 ; 
    }
    TreeNode* buildTree(vector<int>& post , vector<int>& in , int postS , int postE , int inS , int inE){
        if(postS > postE)
           return NULL ; 
        
        TreeNode* root = new TreeNode(post[postE]) ; 

        int x = search(root->val , in) ; 

        
        //leftIn
        int leftinS = inS ; 
        int leftinE = x-1 ; 

        //RightIn
        int rightinS = x+1 ; 
        int rightinE = inE ; 

        //leftPre
        int leftpostS = postS ; 
        int leftpostE = leftpostS + (leftinE - leftinS) ;

        //rightPre
        int rightpostS = leftpostE + 1 ; 
        int rightpostE = postE - 1 ; 

        root->left = buildTree(post,in,leftpostS,leftpostE,leftinS,leftinE) ; 
        root->right = buildTree(post,in,rightpostS,rightpostE,rightinS,rightinE) ;  

        return root ; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1) ; 
    }
};