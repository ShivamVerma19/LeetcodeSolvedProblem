class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& a) {
        
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[n-1][i] = a[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down = a[i][j] + dp[i+1][j];
                int dia = a[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,dia);
            }
        }

        return dp[0][0];
    }
};