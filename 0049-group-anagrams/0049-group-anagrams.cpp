class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        vector<vector<string>>ans;
        vector<string>b;
        b=a;

         map<string,vector<int>>m;

       for(int i=0;i<a.size();i++){
           sort(b[i].begin(),b[i].end());
           m[b[i]].push_back(i);
       }

        for(auto &i:m){
        vector<string>v;
        for(int j=0;j<i.second.size();j++){
            v.push_back(a[i.second[j]]);
        }
        ans.push_back(v);
        }

   return ans;

    }
};