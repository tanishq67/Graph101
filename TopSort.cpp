https://leetcode.com/problems/course-schedule-ii/description/
------------------------------------------------------------------------------------
class Solution {
public:
    map<int,vector<int>> adj;
    map<int,int> indegree;
    int n;
    vector<int> order;
    
    bool topo_sort(){
        queue<int> q; 
        vector<int> vis(n,0);
        
        for(int x= 0 ; x <n ; x++){
            if(indegree[x] == 0){
                q.push(x);
                vis[x] = 1; 
            }
        }
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            order.push_back(node);
            
            for(auto neighbour: adj[node]){
                if(vis[neighbour]) return true;
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }
            }
            
        }
        for(int x: vis) if(!x)return true;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        for(auto x: prereq){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        n = numCourses;
        bool ans = topo_sort();
        if(ans) return {};
        return order;
    }
};
