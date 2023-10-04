class Solution {
public:
    int t = 0 ; 
    void dfs(vector<int> adj[] , vector<vector<int>> &ans , vector<int> &vis , 
    vector<int> &time , vector<int> &low , int node , int parent){


        vis[node] = 1 ; 
        time[node] = t ; 
        low[node] = t ; 

        t++ ;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj,ans,vis,time,low,it,node) ; 
            }

            if(parent != -1 && parent != it)
               low[node] = min(low[node] , low[it]) ; 
            if(low[it] > time[node]){
                vector<int> v(2) ; 
                v[0] = node  ; 
                v[1] = it ;
                ans.push_back(v) ; 
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n] ; 

        for(auto it : connections){
             adj[it[0]].push_back(it[1]) ; 
             adj[it[1]].push_back(it[0]) ; 
        }

        vector<int> vis(n,0) ; 
        vector<int> time(n,0) ;
        vector<int> low(n,0) ; 
        vector<vector<int>> ans ; 

        dfs(adj,ans,vis,time,low,0,-1) ; 
        return ans ;
    } 
};