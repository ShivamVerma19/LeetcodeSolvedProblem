#include <bits/stdc++.h> 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size() ; 
        unordered_map<int,int> map ; 
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minHeap ;
        vector<int> ans ; 
        if(k > n)
           return ans ; 
           
        for(int i = 0 ; i < n ; i++){
            map[arr[i]]++ ; 
        }

        for(auto i : map){
            minHeap.push({i.second , i.first}) ; 
            if(minHeap.size() > k)
               minHeap.pop() ; 
        }

        priority_queue<pair<int,int>> maxHeap ; 

        while(!minHeap.empty()){
            auto f = minHeap.top() ; 
            maxHeap.push({f.first,f.second}) ; 
            minHeap.pop() ; 
        }

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second) ; 
            maxHeap.pop() ; 
        }

        return ans ; 
    }
};