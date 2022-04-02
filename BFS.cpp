class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<int> ans, vis(n + 1, 0 );  
        queue<int> q;
        q.push(0); vis[0] = 1;
      
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(int x : adj[node]){
                if(!vis[x]){
                    q.push(x);
                    vis[x] = 1; // vis ko true karni ki postion yehi hogi because agar upar karege toh insert hota jaega and baad me true hoga
                }
            }
        }
        
        return ans;
    }
};
