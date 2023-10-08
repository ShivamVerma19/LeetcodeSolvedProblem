class Solution {
    void solve(vector<int> nums, vector<vector<int>> &ans, int i){
        if(i >= nums.size()){
            ans.push_back(nums);
            return ;
        }

        for(int x=i; x<nums.size(); x++){
            swap(nums[i],nums[x]);
            solve(nums,ans,i+1);
            swap(nums[i],nums[x]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        solve(nums,ans,i);

        return ans;
    }
};