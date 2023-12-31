class Solution {
public:
   int f(int i, string&s, vector<int>&dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        for(int j=i; j<s.size(); j++){
            if(ispalindrome[i][j]==1){
                int cnt=1+f(j+1, s, dp);
                ans=min(ans, cnt);
            }
        }
        return dp[i]=ans;
    }
    vector<vector<int>> ispalindrome;
    int minCut(string s) {
      
       int n=s.length();
       ispalindrome.resize(n+1,vector<int>(n+1,1));
       for(int l=2;l<=n;l++)
       {
          int j=l-1;
          int i=0;
          while(j<n)
          {
              if(s[i]==s[j] && ispalindrome[i+1][j-1]==1)
              {
                   ispalindrome[i][j]=1;
                   
              }
              else{
                  ispalindrome[i][j]=0;
              }

              j++;
              i++;
          }   
       }
       vector<int>dp(s.size(), -1);
        return f(0, s, dp)-1;
    }
};