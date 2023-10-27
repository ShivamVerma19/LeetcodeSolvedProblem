class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans ;
        if(intervals.size() == 0)
           return ans ;

        sort(intervals.begin() , intervals.end()) ; 

        int s = intervals[0][0] ; 
        int e = intervals[0][1] ;

        for(int i = 1 ; i < intervals.size() ; i++){

            if(e >= intervals[i][0]){
                e = max(e,intervals[i][1]) ;
            }
            else{
                vector<int> v(2) ; 
                v[0] = s ; 
                v[1] = e ;
                ans.push_back(v) ; 

                s = intervals[i][0] ; 
                e = intervals[i][1] ; 
            }
        }

        vector<int> v(2) ; 
        v[0] = s ; 
        v[1] = e ;
        ans.push_back(v) ;

        return ans ;
    }
};