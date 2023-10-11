/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void listToVector(  vector<int> & arr,ListNode* head){
if(head == NULL){
    return;
}
arr.push_back(head->val);
listToVector(arr,head->next);
    }
TreeNode*   inoderedtotree(TreeNode* tree ,vector<int>  arr,int start ,int end){
if(start>end) return NULL;
int mid = start+(end - start)/2;
tree = new TreeNode(arr[mid]);
tree->left = inoderedtotree(tree->left ,arr,start,mid-1);
tree->right =inoderedtotree(tree->right ,arr,mid+1,end);
return tree;
 }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        listToVector(arr,head);
        TreeNode* root= NULL;
if (!arr.empty()) {
root =inoderedtotree(root,arr,0,arr.size() -1);
}

    return root;
    }
};