class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,start=0,end=0,n=s.size();
        int mini=INT_MAX;
        unordered_map<char,int>mp;
        //creating a map to store the string t
        for(int m=0;m<t.size();m++){
            mp[t[m]]++;
        }
        int count=mp.size();

        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }

            if(count==0){
                if(mini>j-i+1){
                    mini=j-i+1; start=i; end=j;
                }
                else mini=mini;

                while(count==0){
                    if(mini>j-i+1){
                    mini=j-i+1; start=i; end=j;
                    }
                    else mini=mini;


                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]>0){
                            count++;
                        }
                        i++;
                    }
                    else
                        i++;
                    }
            }

            j++;
        }
        
        string temp="";
        for(int i=start;i<=end;i++){
            temp+=s[i];
        }

        if(mini==INT_MAX) return "";
        else return temp;
        
    }
};