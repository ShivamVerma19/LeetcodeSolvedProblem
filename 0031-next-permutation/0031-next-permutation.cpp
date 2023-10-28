class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size() ; 

        int x = -1 ; 

        for(int i = n-2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                x = i ; 
                break ; 
            }
        }

        int y = -1 ; 
        if(x != -1){

            for(int i = n-1  ; i >= x ; i--){
                if(nums[i] > nums[x]){
                    y = i ; 
                    break ; 
                }
            }
        }

        if(x != -1)
           swap(nums[x] , nums[y])  ; 


        if(x != -1)
           reverse(nums.begin()+x+1, nums.end());
        else
           reverse(nums.begin() , nums.end()) ; 
    }
};